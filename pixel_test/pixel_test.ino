#include <U8g2lib.h>

// Set up display for heltec_wifi_kit_32_v3
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ 18, /* data=*/ 17, /* reset=*/ 21);


void setup() {
  Serial.begin(115200);
  Serial.println("Setting up display.");
  u8g2.begin();
}


void loop() {
  for (int y = 0; y < 64; y++) {
    for (int x = 0; x < 128; x++) {
      u8g2.clearBuffer();
      u8g2.drawPixel(x, y);
      u8g2.sendBuffer();
    }
  }
}
