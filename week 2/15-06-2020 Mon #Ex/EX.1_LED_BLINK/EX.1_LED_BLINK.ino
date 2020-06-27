void setup() {
  // put your setup code here, to run once:
pinMode(LED_BUILTIN, OUTPUT);
digitalWrite(LED_BUILTIN,HIGH);
delay(2000);
}

void loop() {

  digitalWrite(LED_BUILTIN,HIGH);
  delay(1000);

  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);
  

}
