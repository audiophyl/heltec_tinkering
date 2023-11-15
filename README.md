# HelTec WiFi Kit 32 V3 in Arduino IDE
Welcome! This is a summary of my findings while setting up the aforementioned HelTec ESP32 microcontroller. Heltec's documentation was lacking, so I hope someone finds these notes helpful.

## Process
1. Install Arduino IDE.
2. Add Arduino ESP32 support through File -> Preferences -> Additional Board Manager URLs
    * HelTec's documentation says otherwise, but I found the Espressif arduino-esp32 URL to be best.
    * This URL is https://espressif.github.io/arduino-esp32/package_esp32_index.json
3. Add Espressif ESP32 board support.
    * Tools -> Board -> Board Manager
    * Search for 'ESP32'
    * Select the Espressif package to install
4. Add Acrobotic SSD1306 display support
    * Tools -> Manage Libraries
    * Search for 'U8g2'
    * Select the U8g2 package to install
4. Configure Arduino to use the HelTec WiFi Kit 32 V3
    * Select 'HelTec WiFi Kit 32(V3)' from the Tools -> Board -> ESP32 Arduino menu
    * Connect the board
    * Select the correct port for your setup

## Fix an Espressif error
For v2.0.14 and all versions prior of arduino-esp32 from Espressif, a folder will need to be renamed so you can compile sketches. For my setup, that required renaming this folder:

```
~/snap/arduino/current/.arduino15/packages/esp32/hardware/esp32/2.0.14/variants/heltec_wifi_kit_32_v3
```

to this:

```
~/snap/arduino/current/.arduino15/packages/esp32/hardware/esp32/2.0.14/variants/heltec_wifi_kit_32_V3
```

Following this change, it should now be possible to compile sketches for this board using the Arduino IDE.

## Hardware Notes
### Display
I find U8g2 (and U8x8) to be the most straightforward to use. Your setup line will depend on correct pin numbering to be passed to the constructor:

> OLED_SDA = 17
> OLED_SCL = 18
> OLED_RST = 21

So your constructor for U8g2 might look like this:

```
#include <U8g2lib.h>
// set up display for heltec_wifi_kit_32_v3
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ 18, /* data=*/ 17, /* reset=*/ 21);
```

## Links
-HelTec [product page](http://hiletgo.com/ProductDetail/2157143.html)  
-[Hackaday](https://hackaday.io/project/26991-esp32-board-wifi-lora-32) article regarding a similar board  
-[Robotzero.one](https://robotzero.one/heltec-wifi-kit-32/) blog entry regarding a similar board  
-[GitHub](https://github.com/HelTecAutomation/Heltec_ESP32) repository for some HelTec code  
