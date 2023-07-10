# Ardi_UHF_Shield_Software
<img src="https://cdn.shopify.com/s/files/1/1217/2104/files/ArdiUHFShield.jpg?v=1683886717">
Ardi 

This github provides getting started guide and other working details for Ardi UHF Shield 

### Features:
- Onboard 2.0” TFT Display


### Specifications:
- Display resolution 240x320 pixels

  
### Hardware Overview
#### Pinout
<img src="https://cdn.shopify.com/s/files/1/1217/2104/files/ArdiUHFpinout.png?v=1688471914">

- (1) & (4) Programmable Buttons
- (2) Voltage Selection 3.3V/5V
- (3) TFT 2.0 Display
- (5) 5-Way Joystick

**Note:** Don't forget to set jumper selection on correct selection when using with 5V or 3.3V board. Put jumpber on **3V3-SEL** when using with **3.3V MCU boards** and on **SEL-5V** when using with **5V MCU Boards**.

#### Interfacing Details

When Relay shield mounted on ArdiPi, selection **jumper** must be on **3V3-SEL** side
|ArdiPi | UHF shield | Function |
|---|---|---|
| GP18 | CLK | Clock pin of SPI interface for Display |
| GP16 | BL | BackLight for display |
| GP19 | DIN | MOSI (Master OUT Slave IN) pin of SPI interface for display |  
| GP17 | CS | SPI Chip select pin for display |


## How to Configure UHF Lite from Application
Things you will need:

**Hardware->**
1. Ardi UHF Shield 
2. USB to TTL converter [Buy](https://shop.sb-components.co.uk/products/usb-ttl)

**Software->**
UHF RFID reader App - [Download](https://github.com/sbcshop/UHF_Lite_Pico_Expansion_Software/blob/main/uhf%20lite.rar)

<img src = "https://github.com/sbcshop/UHF_Lite_Pico_Expansion_Software/blob/main/Images/img.JPG"/>

Connect USB to TTL to Ardi UHF shield:
Make sure to connect jumper wire as per below image and UHF Expansion ***without*** PICO

<img src = "https://github.com/sbcshop/UHF_Lite_Pico_Expansion_Software/blob/main/Images/UHF%20Lite.jpg"/>
Steps Shown below to configure UHF of Ardi UHF shield:

<img src = "https://github.com/sbcshop/UHF_Lite_Pico_Expansion_Software/blob/main/Images/img1.png"/>
<img src = "https://github.com/sbcshop/UHF_Lite_Pico_Expansion_Software/blob/main/Images/img2.png"/>
<img src = "https://github.com/sbcshop/UHF_Lite_Pico_Expansion_Software/blob/main/Images/img3.png"/>
<img src = "https://github.com/sbcshop/UHF_Lite_Pico_Expansion_Software/blob/main/Images/img4.png"/>
<img src = "https://github.com/sbcshop/UHF_Lite_Pico_Expansion_Software/blob/main/Images/img5.png"/>
<img src = "https://github.com/sbcshop/UHF_Lite_Pico_Expansion_Software/blob/main/Images/img6.png"/>
<img src = "https://github.com/sbcshop/UHF_Lite_Pico_Expansion_Software/blob/main/Images/img7.png"/>
<img src = "https://github.com/sbcshop/UHF_Lite_Pico_Expansion_Software/blob/main/Images/img8.png"/>

UHF Command Manual [Download](https://github.com/sbcshop/UHF_Lite_Module/blob/main/UHF%20Lite%20Manual.pdf) 

### Example Codes
 Ardi RFID shield Sample codes provided for different boards
 - [Ardi RFID shield for UNO](https://github.com/sbcshop/Ardi_RFID_Shield_Software/tree/main/examples/ArduinoUno_RFID_shield_interfacing) 
 - [Ardi RFID shield for Ardi32](https://github.com/sbcshop/Ardi_RFID_Shield_Software/tree/main/examples/Ardi32_RFID_shield_interfacing) 
 - [Ardi RFID shield for ArdiPi](https://github.com/sbcshop/Ardi_RFID_Shield_Software/tree/main/examples/ArdiPi_RFID_shield_interfacing)
 
 Using this sample code as a guide, you can modify, build for other boards and share codes!!  
   
## Resources
  * [Schematic](https://github.com/sbcshop/Ardi_RFID_Shield_Hardware/blob/main/Design%20Data/SCH%204CH%20Relay%20Shield.pdf)
  * [Hardware Files](https://github.com/sbcshop/Ardi_RFID_Shield_Hardware/tree/main)
  * [Step File](https://github.com/sbcshop/Ardi_RFID_Shield_Hardware/blob/main/Mechanical%20Data/STEP%204CH%20Relay%20Shield.step)


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
