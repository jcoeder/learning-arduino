//Create variables for the associated output pins
const int greenLEDPin = 9;
const int redLEDPin = 11;
const int blueLEDPin = 10;

//Create variables for the associated sensor pins
const int greenSensorPin = A0;
const int redSensorPin = A1;
const int blueSensorPin = A2;

//Set default values 
int greenValue = 0;
int redValue = 0;
int blueValue = 0;

//Set default sensor values
int greenSensorValue = 0;
int redSensorValue = 0;
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
  //Read the analog value of the sensor and wait .5 seconds
  greenSensorValue = analogRead(greenSensorPin);
  delay(500);
  //Read the analog value of the sensor and wait .5 seconds
  redSensorValue = analogRead(redSensorPin);
  delay(500);
  //Read the analog value of the sensor and wait .5 seconds
  blueSensorValue = analogRead(blueSensorPin);
  delay(500);
  
  Serial.println("Raw Sensor Values");
  Serial.println("Green: ");
  Serial.println(greenSensorValue);
  Serial.println("Red: ");
  Serial.println(redSensorValue);
  Serial.println("Blue: ");
  Serial.println(blueSensorValue);
  greenValue = greenSensorValue/4;
  redValue = redSensorValue/4;
  blueValue = blueSensorValue/4;
  Serial.println("Values");
  Serial.println("Green: ");
  Serial.println(greenValue);
  Serial.println("Red: ");
  Serial.println(redValue);
  Serial.println("Blue: ");
  Serial.println(blueValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(redLEDPin, redValue);
  analogWrite(blueLEDPin, blueValue);
}
