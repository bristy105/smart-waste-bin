/*
Ultrasonic Sensor HC-SR04 and Arduino Tutorial

*/
// pin numbers for wemos D1 mini ESP2866
//const int trigPin = 05; //yellow D1
//const int echoPin = 04; //green D2

// pin numbers for Firebeetle 32
const int trigPin = 25; //orange D2
const int echoPin = 26; //white D3

// also connect 3.3V and GND to power the sensor

// defines variables
long duration;
int distance;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(115200); // Starts the serial communication
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(40); // was 10
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance [cm]: ");
Serial.println(distance);
}
