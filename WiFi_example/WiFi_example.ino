/* 
Connect the ESP8266 unit to an existing WiFi access point
works with ESP32 too
*/

#include <WiFi.h>

// Replace these with your WiFi network settings
#define WIFI_SSID "iPhone" //replace this with your WiFi network name. ESP2866 supports only 2GHz Wi-Fi!
#define WIFI_PASSWORD "labas123" //replace this with your WiFi network password


void setup()
{
  delay(1000);
  Serial.begin(115200);
 
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.println();
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("success!");
  Serial.print("IP Address is: ");
  Serial.println(WiFi.localIP());
}

void loop() {
}
