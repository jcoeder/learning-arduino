//Set sensorPin to A0
const int sensorPin = A0;
//Create baseline temp (celcius)
const float baselineTemp = 20.0;

void setup() {
  //Initialize the serial object
  Serial.begin(9600);
  //Loop to initialize pins starting with 3 then working up
  //Until pin number is less than 6
  for(int pinNumber = 3; pinNumber<6; pinNumber++){
    //Set mode to OUTPUT
    pinMode(pinNumber, OUTPUT);
    //Set value to LOW
    digitalWrite(pinNumber, LOW);
  }

}

void loop() {
  //Read the value of the sensor
  int sensorVal = analogRead(sensorPin);
  //Convert the sensor output to voltage
  float voltage = (sensorVal/1024.0) * 5.0;
  //Convert the voltage to temerature in Celsuis
  //Sensor can read temps below 0.  Must offset
  float ctemperature = (voltage - .5) * 100;
  //Convert Celsuis to Fahrenheit
  float ftemperature = (((9.0/5.0)*ctemperature)+32);
  //Print all the values.
  Serial.print("Sensor Value: ");
  Serial.println(sensorVal);
  Serial.print("Voltage Value: ");
  Serial.println(voltage);
  Serial.print("Celcius Temperature Value: ");
  Serial.println(ctemperature);
  Serial.print("Fahrenheit Temperature Value: ");
  Serial.println(ftemperature);
  //If Celsuis temp is below the baseline temp plus 2 degress
  //illuminate 0 of the lights
  if(ctemperature < baselineTemp+2){
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  //If Celsuis temp is above the baseline temp plus 2 degress
  //and less than the baseline temp plus 4 degrees
  //illuminate 1 of the lights
  else if(ctemperature >= baselineTemp+2 && ctemperature < baselineTemp+4) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  //If Celsuis temp is above the baseline temp plus 4 degress
  //and less than the baseline temp plus 6 degrees
  //illuminate 2 of the lights
  else if(ctemperature >= baselineTemp+4 && ctemperature < baselineTemp+6) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  }
  //If Celsuis temp is above the baseline temp plus 6 degress
  //illuminate all of the lights
  else if(ctemperature >= baselineTemp+6) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  }
  delay(1000);
}
