void setup() {
Serial.begin(9600);
Serial.println("The Process is started");
pinMode(7,OUTPUT);
}

void loop() {
int ADC_VAL = analogRead(A1);
float volts = (5.0f/1024)*ADC_VAL; 
Serial.println("ADC reading: ");
Serial.println(volts);
if (volts >= 1) {
  
  digitalWrite(7,HIGH);
  delay(200);
  }
else {
  digitalWrite(7,LOW);
  delay(200);
  }


delay(300);
}
