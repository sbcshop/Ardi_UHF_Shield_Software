#include "Uhf.h"
byte container[512]; //A buff container to contain received bytes

//Uncomment corresponding commands to configure UHF, more command can be added in UHF.h
//#define COMMANDS HARDWARE_VERSION
#define COMMANDS MULTIPLE_READ
//#define COMMANDS SINGLE_READ
//#define COMMANDS STOP_READ

String asciiVal;

void setup() {
  pinMode(21,OUTPUT);
  digitalWrite(21,LOW); // LOW - to enable the module and HIGH to disable the module
  Serial.begin(115200, SERIAL_8N1);
}

void loop() {
  Serial.write(COMMANDS, sizeof(COMMANDS)); // send command to UHF module for configuration
  delay(100);
  int len = Serial.available();
  if (len > 0) {
    Serial.readBytes(container, len); // Read Response from UHF module, and parse frame received
    frameParse(container, len); // This process done in Uhf.cpp file
  }
  delay(500);
}

// Customize this function as per your requirement
void extractEPC(byte frm[], int le) {
  Serial.print("\nComplete Frame: ");
  for (int i = 0; i < le; i++) {
      Serial.print(frm[i], HEX);    //To print in HEX format
      //asciiVal += (char)frm[i];   // create ASCII string format of Response Byte Data 
      Serial.write(32); // To add space between each byte print
    }
  Serial.write(10);
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
