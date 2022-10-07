
//Create variable type int with name switchState, set it zero 
int switchState = 0;

void setup() {
  //Set pins 3-5 as OUTPUT pins, set pin 2 as an INPUT pin
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);

}

void loop() {
  //Read pin 2, set value to switchState
  switchState = digitalRead(2);
  //If switchState is LOW (NOT PRESSED), power only pin 3
  if(switchState == LOW) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else {
  //If switchState is not LOW (THE BUTTON IS PRESSED), power pins 4 and 5
  //in an alternating cycle
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    delay(250);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(250);

  }
}
