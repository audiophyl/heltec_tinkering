#include "WiFi.h"
#include <U8g2lib.h>

// set up display for heltec_wifi_kit_32_v3
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ 21, /* clock=*/ 18, /* data=*/ 17);


void setup()
{
  Serial.begin(115200);
  
  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  Serial.println("Setting up WiFi...");
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.println("Setting up display...");
  u8g2.begin();
}


static void wifi_scan()
{
  int n = WiFi.scanNetworks();

  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_spleen5x8_me);
  if (n == 0) {
    Serial.println("Searching for networks.");
    u8g2.drawStr(0, 8, "Searching...");
  } else {
    Serial.println("Networks found:");
    u8g2.drawStr(0, 8, "Networks:");
    for (int i = 0; i < 7; i++) {
      if (i > n) {
        break;
      }
      // Print SSID for each network found
      char currentSSID[24];
      Serial.println(WiFi.SSID(i));
      WiFi.SSID(i).toCharArray(currentSSID, 24);
      u8g2.drawStr(0, (i + 2) * 8, currentSSID);
    }
    Serial.println("");
  }
  u8g2.sendBuffer();
}


void loop()
{
  wifi_scan();
  
  // Wait a bit before scanning again
  delay(5000);
}
