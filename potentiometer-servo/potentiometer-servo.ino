#include <Servo.h>

Servo myServo;

//Map potPin to A0
int const potPin = A0;
//Create empty variables
int potVal;
int angle;

void setup() {
  //Using the servo library, attach the servo to pin 9
  myServo.attach(9);
  //Uncomment for debugging
  //Serial.begin(9600);
}

void loop() {
  //Read the analog value on Potpin
  potVal = analogRead(potPin);
  //Uncomment for debugging
  //Serial.print("potVal: ");
  //Serial.println(potVal);
  //map function scales number.  The potentiometer provides values 0-1023
  //the servo operations in degrees ranging from 0-179
  angle = map(potVal, 0, 1023, 0, 179);
  //Uncomment for debugging
  //Serial.print("angle: ");
  //Serial.println(angle);
  //Tell the servo to move the the mapped angle
  myServo.write(angle);
  //Uncomment for debugging
  //Delay is 500 to make the serial output human readable.
  //delay(500);  
}
