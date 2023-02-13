/*
 
 ESP32 deep sleep and hibernate example
 https://diyi0t.com/reduce-the-esp32-power-consumption/
 
*/

#define uS_TO_S_FACTOR 1000000  /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP  5        /* Time ESP32 will go to sleep (in seconds) */
int var =0;
 
void setup() {
  Serial.begin(115200);
  Serial.setTimeout(2000);
  
  //esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_PERIPH, ESP_PD_OPTION_ON); // deep sleep => all RTC Peripherals are powered
  esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_PERIPH, ESP_PD_OPTION_OFF); // hibernation => all RTC peripherals are deactivated

  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR); // ESP32 wakes up every 5 seconds

  // Wait for serial to initialize.
  while(!Serial) { }

  Serial.println("");
  Serial.println("");
  
}


void loop() {

  Serial.println("");
  Serial.println("ESP is awake");
  var = 0;
  while (var < 5) {
    // do something 
    Serial.print(".");
    delay(1000);
    var++;
  }
  
  Serial.println("");
  
  // Deep sleep mode for 5 seconds, the ESP8266 wakes up by itself when GPIO 16 (D0 in NodeMCU board) is connected to the RESET pin
  Serial.println("I'm awake, but I'm going into sleep mode for 5 seconds.. when I wake I will print shit on the serial.");
  Serial.println("");

  esp_deep_sleep_start();

  
}
