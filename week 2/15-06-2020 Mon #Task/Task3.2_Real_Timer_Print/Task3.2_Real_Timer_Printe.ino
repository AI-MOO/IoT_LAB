const unsigned int UpdateInterval = 1000;

unsigned long lastUpdate;

byte hour;
byte minute;
byte second;

void setup(){
  Serial.begin(9600);
}

void loop(){
  if(millis() - lastUpdate >= UpdateInterval){
    lastUpdate = lastUpdate + UpdateInterval;
   
    second++;
   
    if(second == 60){
      second = 0;
      minute++;
    }
    if(minute == 60){
      minute = 0;
      hour++;
    }
    if(hour == 24){
      hour = 0;
    }
   
    Serial.print(hour);
    Serial.print(':');
    if(minute < 10){
      Serial.print('0');
    }
    Serial.print(minute);
    Serial.print(':');
    if(second < 10){
      Serial.print('0');
    }
    Serial.println(second);
  }
}
