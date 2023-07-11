# Ardi_UHF_Shield_Software
<img src="https://cdn.shopify.com/s/files/1/1217/2104/files/ArdiUHFShield.jpg?v=1683886717">
Ardi UHF Shield is designed to seamlessly integrate with your ArdiPi, Ardi-32 and Arduino Uno plus compatible boards, making it accessible to both beginners and experienced users alike.

This github provides getting started guide and other working details for Ardi UHF Shield 

### Features:
- Onboard High-performance UHF RFID reader module
- 24 hours x 365 days’ work normally
- 0.91” OLED display for visual interaction with shield
- Multi-tone Buzzer onboard for Audio alerts
- Shield compatible with both 3.3V and 5V MCU
- Mounts directly onto your [ArdiPi](https://shop.sb-components.co.uk/products/ardipi-uno-r3-alternative-board-based-on-pico-w), [Ardi-32](https://shop.sb-components.co.uk/products/ardi32-uno-r3-alternative-board-based-on-esp32-s3-wroom), and Arduino compatible boards

### Specifications:
- OLED resolution 128x32 pixels
- I2C Interface for OLED
- UHF Frequency Range :
	- EU/UK: 865.1-867.9 MHz
	- US: 902.25-927.75 MHz
- Protocols Supported: EPCglobal UHF Class 1 Gen 2 / ISO 18000-6C
- Reading Distance: 1meters
- Can identify over 50 tags simultaneously
- Communication interface: TTL UART Interface for UHF
- Communication baud rate: 115200 bps（default and recommend) - 38400bps
- Operation current: 180mA @ 3.5V (26 dBm Output，25°C), 110mA @ 3.5V (18 dBm Output，25°C)
- Working humidity < 95% (+ 25 °C)
- Heat-dissipating method Air cooling(no need out install cooling fin）
- Tags storage capacity: 200pcs tags @ 96 bit EPC
- Output power: 18-26 dBm
- Output power accuracy: +/- 1dB
- Tags RSSI: support
  
## Hardware Overview
### Pinout
<img src="https://cdn.shopify.com/s/files/1/1217/2104/files/ArdiUHFpinout.png?v=1688471914">

- (1) UHF Lite Module
- (2) OLED display 
- (3) Buzzer


### Interfacing Details

When Ardi UHF shield mounted on ArdiPi,
|ArdiPi | UHF shield | Function |
|---|---|---|
| GP1 | U_RX | Serial Tx of UHF to Serial Rx of Pico W |
| GP0 | U_TX | Serial Rx of UHF to Serial Tx of Pico W |
| GP5 | U_EN | UHF Enable pin, LOW to disable and HIGH to enable |  
| GP2 | BUZ | Buzzer +ve Pin |
| GP20/SDA | SDA | Serial Data for I2C interfacing of OLED display|
| GP21/SCL | SCL | Serial Clock for I2C interfacing of OLED display|

When Ardi UHF shield mounted on Ardi-32,
|Ardi-32 | UHF shield | Function |
|---|---|---|
| IO18 | U_RX | Serial Tx of UHF to Serial Rx of ESP32 |
| IO17 | U_TX | Serial Rx of UHF to Serial Tx of ESP32 |
| IO1 | U_EN | UHF Enable pin, LOW to disable and HIGH to enable |  
| IO42 | BUZ | Buzzer +ve Pin |
| IO38/SDA | SDA | Serial Data for I2C interfacing of OLED display|
| IO39/SCL | SCL | Serial Clock for I2C interfacing of OLED display|

When Ardi UHF shield mounted on Arduino Uno, for uploading Code in UNO you will have to remove this UHF shield as it is using Hardware serial pin.
|Arduino UNO | UHF shield | Function |
|---|---|---|
| D0 | U_RX | Serial Tx of UHF to Serial Rx of Arduino UNO |
| D1 | U_TX | Serial Rx of UHF to Serial Tx of Arduino UNO |
| D2 | U_EN | UHF Enable pin, LOW to disable and HIGH to enable |  
| D3 | BUZ | Buzzer +ve Pin |
| A4/SDA | SDA | Serial Data for I2C interfacing of OLED display|
| A5/SCL | SCL | Serial Clock for I2C interfacing of OLED display|

### Example Codes
 Ardi UHF shield Sample codes provided for different boards, codes provided with UHF library files in which some of UHF configuration command included. Taking reference of [UHF command manual](https://github.com/sbcshop/Ardi_UHF_Shield_Software/blob/main/documents/UHF%20Commands%20Manual.pdf) you can add more commands for your applications OR use GUI UHF reader apps to configure UHF.
 - [Ardi UHF shield for ArdiPi](https://github.com/sbcshop/Ardi_UHF_Shield_Software/tree/main/examples/ArdiPi_UHF_shield_interfacing)
 - [Ardi UHF shield for Ardi32](https://github.com/sbcshop/Ardi_UHF_Shield_Software/tree/main/examples/Ardi32_UHF_shield_interfacing) 
 - [Ardi UHF shield for UNO]() 
 
 Using this sample code as a guide, you can modify, build for other boards and share codes!! 
 
## How to Configure UHF Lite from Application
Things you will need:

### **Hardware->**
1. Ardi UHF Shield 
2. USB to TTL converter [Buy](https://shop.sb-components.co.uk/products/usb-ttl)

Connect USB-TTL converter to Ardi UHF shield
| USB-TTL | UHF shield | Function |
|---|---|---|
| RXD | U_RX | Serial Tx of UHF to RXD of TTL |
| TXD | U_TX | Serial Rx of UHF to TXD of TTL |
| VCC | 5V | Serial Data for I2C interfacing of OLED display |
| GND | GND | Serial Clock for I2C interfacing of OLED display |


### **Software->**
UHF RFID reader App - [Download](https://github.com/sbcshop/Ardi_UHF_Shield_Software/blob/main/UHF%20GUI%20application.rar), Extract and Run Application.

<img src = "https://github.com/sbcshop/Ardi_UHF_Shield_Software/blob/main/images/run_uhf_app.png" width="645" height="377"/>

<img src = "https://github.com/sbcshop/UHF_Lite_Pico_Expansion_Software/blob/main/Images/img.JPG"/>

### Steps shown below to configure UHF of Ardi UHF shield using App:
* Select suitable com port, you may get different 
<img src = "https://github.com/sbcshop/UHF_Lite_Pico_Expansion_Software/blob/main/Images/img1.png"/>
<img src = "https://github.com/sbcshop/UHF_Lite_Pico_Expansion_Software/blob/main/Images/img2.png"/>

* Click on Connect button
<img src = "https://github.com/sbcshop/UHF_Lite_Pico_Expansion_Software/blob/main/Images/img3.png"/>
<img src = "https://github.com/sbcshop/UHF_Lite_Pico_Expansion_Software/blob/main/Images/img4.png"/>

* Select your region
<img src = "https://github.com/sbcshop/UHF_Lite_Pico_Expansion_Software/blob/main/Images/img5.png"/>

* Other settings which you may apply
<img src = "https://github.com/sbcshop/UHF_Lite_Pico_Expansion_Software/blob/main/Images/img6.png"/>
<img src = "https://github.com/sbcshop/UHF_Lite_Pico_Expansion_Software/blob/main/Images/img7.png"/>
<img src = "https://github.com/sbcshop/UHF_Lite_Pico_Expansion_Software/blob/main/Images/img8.png"/>

[Download UHF Lite Command Manual](https://github.com/sbcshop/Ardi_UHF_Shield_Software/blob/main/documents/UHF%20Commands%20Manual.pdf) for more detail setup reference. 
   
## Resources
  * [Schematic](https://github.com/sbcshop/Ardi_UHF_Shield_Hardware/blob/main/Design%20Data/SCH%20UHF%20Lite%20Shield.pdf)
  * [Hardware Files](https://github.com/sbcshop/Ardi_UHF_Shield_Hardware/tree/main)
  * [Step File](https://github.com/sbcshop/Ardi_UHF_Shield_Hardware/blob/main/Mechanical%20Data/STEP%20UHF%20Lite%20Shield.step)
  * [Official Arduino Getting Started](https://docs.arduino.cc/learn/starting-guide/getting-started-arduino)
  * [Official Pico W Getting Started](https://projects.raspberrypi.org/en/projects/get-started-pico-w)
  * [Official Getting Started with ESP32 in Arduino](https://docs.espressif.com/projects/arduino-esp32/en/latest/)


## Related Products
   * [Ardi-32](https://shop.sb-components.co.uk/products/ardi32-uno-r3-alternative-board-based-on-esp32-s3-wroom?_pos=6&_sid=90d9cefb0&_ss=r) - Arduino Uno Form factor with latest powerful ESP32 S3
   * [ArdiPi](https://shop.sb-components.co.uk/products/ardipi-uno-r3-alternative-board-based-on-pico-w?_pos=5&_sid=5704675c2&_ss=r) - Arduino Uno Form factor with powerful Pico W of Raspberry Pi having onboard WiFi and BLE support.
   * [Ardi Display Shield](https://shop.sb-components.co.uk/products/ardi-display-shield-for-arduino-uno?_pos=5&_sid=961a5887c&_ss=r) - 2.0" Display Shield with onboard Programmable Buttons and Joystick
   * [Ardi Relay Shield](https://shop.sb-components.co.uk/products/ardi-relay-shield-for-arduino-uno?_pos=4&_sid=961a5887c&_ss=r) - Relay Shield with Screw terminal and Relay ON/OFF Status LED
   * [Ardi RFID Shield](https://shop.sb-components.co.uk/products/ardi-rfid-shield-for-arduino-uno?_pos=5&_sid=b4e4b2ef1&_ss=r) - Ardi RFID Shield with onbard Relay and Status LED
   
   Shields are compatible with ArdiPi, Ardi-32 and Other Arduino Uno Compatible boards.

## Product License

This is ***open source*** product. Kindly check LICENSE.md file for more information.

Please contact support@sb-components.co.uk for technical support.
<p align="center">
  <img width="360" height="100" src="https://cdn.shopify.com/s/files/1/1217/2104/files/Logo_sb_component_3.png?v=1666086771&width=300">
</p>
