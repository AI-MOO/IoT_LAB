void setup() {
  
Serial.begin(9600);                                                // initialise the communication between Arduino & my PC
Serial.println("How many microseconds have taken up to now");       
Serial.println(micros());
pinMode(13,HIGH);
Serial.println(micros());
}

void loop() { 
digitalWrite(13,HIGH);          // 1 = HIGH 
delay(500);
digitalWrite(13,0);            // 0 = LOW        
delay(500);           
  

}
