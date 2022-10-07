//Create variables for the associated output pins
const int greenLEDPin = 9;
const int redLEDPin = 10;
const int blueLEDPin = 11;

//Create variables for the associated sensor pins
const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

//Set default values 
int redValue = 0;
int greenValue = 0;
int blueValue = 0;

//Set default sensor values
int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;


void setup() {
  //Setup the serial console
  Serial.begin(9600);
  //Set the pin mode for each of the pins.
  //See variables for pin numbers
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);

}

void loop() {
  redSensorValue = analogRead(redSensorPin);
  delay(500);
  greenSensorValue = analogRead(greenSensorPin);
  delay(500);
  blueSensorValue = analogRead(blueSensorPin);
  //blueSensorValue = 100;
  delay(500);
  Serial.println("Raw Sensor Values");
  Serial.println("red: ");
  Serial.println(redSensorValue);
  Serial.println("green: ");
  Serial.println(greenSensorValue);
  Serial.println("blue: ");
  Serial.println(blueSensorValue);
  redValue = redSensorValue/4;
  blueValue = blueSensorValue/4;
  greenValue = greenSensorValue/4;
  Serial.println("Values");
  Serial.println("red: ");
  Serial.println(redValue);
  Serial.println("green: ");
  Serial.println(greenValue);
  Serial.println("blue: ");
  Serial.println(blueValue);
  analogWrite(redLEDPin, redValue);
  analogWrite(blueLEDPin, blueValue);
  analogWrite(greenLEDPin, greenValue);
  
}
