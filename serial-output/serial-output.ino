void setup()
{
  //Initialize the serial object with a baud rate of 9600
  Serial.begin(9600);
  //Print a line and newline 
  Serial.println("Starting..");
}

void loop()
{
  //Print a line and newline
  Serial.println("Hi, my name is..");
  //Print a line without a newline
  Serial.print("...");
  //Print a line and newline
  Serial.println("Chicka chicka slim shady");
  delay(1000);
}
