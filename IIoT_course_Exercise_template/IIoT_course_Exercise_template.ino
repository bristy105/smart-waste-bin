
//Define libraries here


//Define global variables here
int valueFromFunction = 10000; // global variable



void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(115200); // Needed for serial print with serial monitor. Data rate is set to 115200 bits per second (baud)
  delay(10); // delay of 10 microseconds
  Serial.println("");
  Serial.print("Application started");
  Serial.println("");

}

void loop() {
  // put your main code here, to run repeatedly:


  
  laserSensor(100, 2000);  // calls a function defined in another tab
  delay(5000);

  valueFromFunction = ultrasonicSensor();  // calls a function defined in another tab
  Serial.print("valueFromFunction is: ");
  Serial.println(valueFromFunction);
  Serial.println("");
  delay(5000);

}
