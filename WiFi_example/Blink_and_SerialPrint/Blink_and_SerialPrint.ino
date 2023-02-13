/*
ESP8266 blink and serial print
Blink the blue LED on the ESP8266 module
Board: Generic ESP2866 module
*/

#define LED 2 //Define blinking LED pin

void setup() {
  pinMode(LED, OUTPUT); // Initialize the LED pin as an output

  Serial.begin(115200); // Needed for serial print with serial monitor. Data rate is set to 115200 bits per second (baud)
  delay(10); // delay of 10 microseconds
  Serial.println(""); // first serial print (empty line)
  Serial.print("Application started"); // second serial print
  delay(3000); // delay of 3 seconds
  Serial.println(".. and running"); // third serial print. Notice the difference between print and println!
}
// the loop function runs over and over again forever
void loop() {
  Serial.println("LED ON");
  digitalWrite(LED, LOW); // Turn the LED on (Note that LOW is the voltage level)
  delay(1000); // Wait for a second
  Serial.println("LED OFF");
  digitalWrite(LED, HIGH); // Turn the LED off by making the voltage HIGH
  delay(2000); // Wait for two seconds
}
