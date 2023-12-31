#include <U8g2lib.h>

// set up display for heltec_wifi_kit_32_v3
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ 21, /* clock=*/ 18, /* data=*/ 17);

#define xbmtest_width 128
#define xbmtest_height 64
static unsigned char xbmtest_bits[] = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x03, 0x84, 0x7f, 0xc0, 0x01, 0x1c, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x86, 0xff, 0xc1,
   0x03, 0x1e, 0x00, 0x00, 0x00, 0x00, 0xa0, 0xbf, 0x00, 0x00, 0x00, 0x00,
   0x06, 0x83, 0x81, 0xc1, 0x03, 0x1e, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff,
   0x0f, 0x00, 0x00, 0x00, 0x8c, 0x83, 0x81, 0xc3, 0x06, 0x1b, 0x00, 0x00,
   0x00, 0x00, 0xfe, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x98, 0x81, 0x01, 0xc3,
   0x06, 0x1b, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00,
   0xd8, 0x80, 0x01, 0xc1, 0x04, 0x19, 0x00, 0x00, 0x00, 0x80, 0xff, 0xf7,
   0xff, 0x01, 0x00, 0x00, 0x70, 0x80, 0x81, 0xc1, 0x8c, 0x19, 0x00, 0x00,
   0x00, 0xc0, 0x3f, 0x00, 0xfe, 0x07, 0x00, 0x00, 0x70, 0x80, 0xff, 0xc0,
   0x8c, 0x19, 0x00, 0x00, 0x00, 0xe0, 0x0f, 0x00, 0xf0, 0x07, 0x00, 0x00,
   0x70, 0x80, 0xff, 0xc1, 0x98, 0x18, 0x00, 0x00, 0x00, 0xe0, 0x07, 0x00,
   0xe0, 0x0f, 0x00, 0x00, 0xf8, 0x80, 0x81, 0xc1, 0xd8, 0x18, 0x00, 0x00,
   0x00, 0xe0, 0x07, 0x00, 0xc0, 0x1f, 0x00, 0x00, 0x98, 0x81, 0x01, 0xc3,
   0x70, 0x18, 0x00, 0x00, 0x00, 0xe0, 0x07, 0x00, 0x80, 0x1f, 0x00, 0x00,
   0x8c, 0x81, 0x01, 0xc3, 0x70, 0x18, 0x00, 0x00, 0x00, 0xe0, 0x03, 0x00,
   0x80, 0x1f, 0x00, 0x00, 0x06, 0x83, 0x01, 0xc3, 0x70, 0x18, 0x00, 0x00,
   0x00, 0xe0, 0x07, 0x00, 0x00, 0x3f, 0x00, 0x00, 0x06, 0x87, 0x81, 0xc3,
   0x00, 0x18, 0x00, 0x00, 0x00, 0xc0, 0x07, 0x00, 0x00, 0x3f, 0x00, 0x00,
   0x03, 0x86, 0xff, 0xc1, 0x00, 0x18, 0x00, 0x00, 0x00, 0xc0, 0x0f, 0x00,
   0x00, 0x3f, 0x00, 0x80, 0x01, 0x8c, 0xff, 0xc0, 0x00, 0x18, 0x00, 0x00,
   0x00, 0x80, 0x3f, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x7f, 0x00, 0x3e, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x7f,
   0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xf8, 0x7f, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x7f, 0x00, 0x7e, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0x50,
   0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xc0, 0x1f, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x07, 0x00, 0x00, 0x3f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x07, 0x00,
   0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xf0, 0x03, 0x00, 0x00, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x03, 0x00, 0x00, 0x3f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x01, 0x00,
   0x00, 0x3f, 0x00, 0xc0, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xf0, 0x03, 0x00, 0x80, 0x1f, 0x00, 0xc0, 0xff, 0x07, 0x00, 0x00,
   0x18, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x03, 0x00, 0x80, 0x1f, 0x00, 0x00,
   0x30, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x03, 0x00,
   0xc0, 0x1f, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00,
   0x00, 0xe0, 0x07, 0x00, 0xe0, 0x0f, 0x00, 0x00, 0x30, 0xe0, 0x01, 0x3c,
   0xfc, 0x01, 0x00, 0x00, 0x00, 0xe0, 0x0f, 0x00, 0xf8, 0x07, 0x00, 0x00,
   0x30, 0xf8, 0x07, 0xff, 0xfc, 0x01, 0x00, 0x00, 0x00, 0xc0, 0x3f, 0x00,
   0xfc, 0x07, 0x00, 0x00, 0x30, 0x1c, 0x06, 0x83, 0x18, 0x00, 0x00, 0x00,
   0x00, 0xc0, 0xff, 0xd5, 0xff, 0x01, 0x00, 0x00, 0x30, 0x0c, 0x8c, 0x01,
   0x18, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00,
   0x30, 0x04, 0x0c, 0x03, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff,
   0x7f, 0x00, 0x00, 0x00, 0x30, 0xfe, 0x0f, 0x17, 0x18, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xfc, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x30, 0xfc, 0x0f, 0x7c,
   0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0x02, 0x00, 0x00, 0x00,
   0x30, 0x06, 0x00, 0xc0, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x30, 0x0c, 0x00, 0xc0, 0x18, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x1c, 0x88, 0xc0,
   0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x30, 0xf8, 0x8f, 0xff, 0xf0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x30, 0xe0, 0x03, 0x3e, 0xe0, 0x01, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00 };


void setup() {
  Serial.begin(115200);
  Serial.println("Setting up display.");
  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.drawXBM( 0, 0, xbmtest_width, xbmtest_height, xbmtest_bits);
  u8g2.sendBuffer();
}


void loop() {
}
