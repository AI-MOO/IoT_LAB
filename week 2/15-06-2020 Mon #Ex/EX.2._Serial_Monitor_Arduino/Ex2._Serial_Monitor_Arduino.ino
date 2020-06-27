void setup() {
  
Serial.begin(9600);                   // initialise the communication between Arduino & my PC
Serial.println("Setup");         // print in serial monitor : Hello world 
}

void loop() {

  Serial.println("Loop"); // print Loop then escape line 
  delay(2500);

}
