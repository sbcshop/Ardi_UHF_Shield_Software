#include <HardwareSerial.h>
#include "Uhf.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define mySerial Serial2

byte container[1024]; //A buff container to contain received bytes

//Uncomment corresponding commands to configure UHF, more command can be added in UHF.h
#define COMMANDS HARDWARE_VERSION
//#define COMMANDS MULTIPLE_READ
//#define COMMANDS SINGLE_READ
//#define COMMANDS STOP_READ

String asciiVal;

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // To change default I2C pin, Ardi-32 ESP OLED connected on IO38/SDA, IO39/SCL
  Wire.begin(38, 39); // Wire.begin(SDA, SCL)
  pinMode(21,OUTPUT);
  digitalWrite(21,LOW); // LOW - to enable the module and HIGH to disable the module
  
  mySerial.begin(115200, SERIAL_8N1, 18, 17);
  Serial.begin(115200);
  mySerial.setTimeout(2000);
  
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.clearDisplay();
  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 0);
  display.println(F("Hello"));
  display.display();      // Show initial text
}

void loop() {
  mySerial.write(COMMANDS, sizeof(COMMANDS)); // send command to UHF module for configuration
  delay(100);
  int len = mySerial.available();
  if (len > 0) {
    mySerial.readBytes(container, len); // Read Response from UHF module, and parse frame received
    frameParse(container, len); // This process done in Uhf.cpp file
  }
  delay(1000);
}

// Customize this function as per your requirement
void extractEPC(byte frm[], int le) {
  
  Serial.print("\nComplete Frame: ");
  for (int i = 0; i < le; i++) {
      Serial.print(frm[i], HEX);    //To print in HEX format
      Serial.write(32); // To add space between each byte print
    }
    
  Serial.print("\nExtracted Info Byte from Frame: ");

  // Verify response with 2nd Byte -> Type and 3rd Byte -> COMMAND
  if (frm[1] == 0x02 && frm[2] == 0x22) {  // Extracts info Frame -> multiple read, single read command
    
    // exclude starting 3bytes - HEADER , TYPE, COMMAND and Last 4 bytes - CRC(MSB),CRC(LSB), CHECKSUM,  END
    // information contained inbetween bytes,
    for (int i = 3; i < le - 3; i++) { 
      Serial.print(frm[i], HEX);    //To print in HEX format on terminal
      Serial.write(32);   // To add space between each byte print on terminal
    }
    Serial.write(10);
    
    Serial.print("EPC = 0x");
    asciiVal = "0x";
    for (int i = 8; i < le - 4; i++) { // UHF EPC value starts from 8th byte
      Serial.print(frm[i], HEX);    //To print in HEX format on terminal
      asciiVal += frm[i];    
    }
    Serial.write(10);
    display.clearDisplay();
    displayText("EPC = ",0,0); // pass value-> text, x-axis, y-axis
    displayText(asciiVal,0,10); // pass value-> text, x-axis, y-axis
  }

  
  // Verify response with 2nd Byte -> Type and 3rd Byte -> COMMAND
  if (frm[1] == 0x01 && frm[2] == 0x03) { // Extracts info Frame -> Hardware_version Data
    //Serial.write(42);   // This add * on terminal 
    for (int i = 5; i < le - 2; i++) {
      Serial.print(frm[i], HEX);
      asciiVal += (char)frm[i];   // create ASCII string format of Response Byte Data 
      Serial.write(32);   // To add space between each byte print
    }
    Serial.write(10);
    Serial.println(asciiVal);    //To print in ASCII format
    display.clearDisplay();
    displayText(asciiVal,2,2); // pass value-> text, x-axis, y-axis
    asciiVal = "";
  }
  Serial.println();
}

void displayText(String text, uint8_t x, uint8_t y){
  display.setTextSize(1); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(x, y);
  display.println(text);
  display.display();      // Show initial text
}
void frameParse(byte dataCom[], int lent) {
  //Serial.write(98);
  bool frameBeginFlag = false;
  bool frameEndFlag = true;
  long frameLength;   
  long strNum;      
  byte strBuff[4096];
  int n = lent;
  for (int j = 0; j < n; j++)
  {

    if (frameBeginFlag)
    {
      strBuff[strNum] = dataCom[j];
      if (strNum == 4)
      {
        frameLength = 256 * strBuff[3] + strBuff[4];
        if (frameLength > 3072)
        {
          frameBeginFlag = false;
          continue;
        }
      }
      else if (strNum == frameLength + 6 && strBuff[strNum] == 0x7E)
      {
        int checksum = 0;
        for (int i = 1; i < strNum - 1; i++)
        {
          checksum += strBuff[i];
        }
        checksum = checksum % 256;
        if (checksum != strBuff[strNum - 1])
        {
          // Console.WriteLine("ERROR FRAME, checksum is not right!");
          frameBeginFlag = false;
          frameEndFlag = true;
          continue;
        }
        frameBeginFlag = false;
        frameEndFlag = true;

        //Send out
        byte packet[strNum + 1];
        for (int i = 0; i <= strNum; i++)
        {
          packet[i] = strBuff[i];
        }
        extractEPC(packet, strNum + 1);

      }
      else if (strNum == frameLength + 6 && strBuff[strNum] != 0x7E)
      {
        // Console.WriteLine("ERROR FRAME, cannot get FRAME_END when extends frameLength");
        frameBeginFlag = false;
        frameEndFlag = true;
        continue;
      }
      strNum++;
    }
    else if (dataCom[j] == 0xBB && frameBeginFlag != true)
    {
      strNum = 0;
      strBuff[strNum] = dataCom[j];
      frameBeginFlag = true;
      frameEndFlag = false;
      strNum = 1;
    }
  }
}
