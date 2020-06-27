


void setup() {

Serial.begin(9600);

Serial.println("Hello World");

for (int i = 0; i<=10; i++) {
  
  Serial.println(i);
  delay(250);
  
  }

// Unsigned long variables are extended size variables for number , and store 32 bits (4 bytes), store + numbers only
Serial.print(millis());
Serial.println(" ms");
unsigned long allSeconds=millis()/1000;  // allSecond: shows the number of second is taken to run the previous program in second 
int runHours = allSeconds/3600;          //Convert total time in Seconds into time in Hours
int secsRemaining = allSeconds%3600;    // Here we find the reminder to calculate the remaining time in miniutes 
int runMinutes = secsRemaining/60;      // remaining time / 60 
int runSeconds = secsRemaining%60;      // again we find the reminder to calculate the remaining time in seconds 


char ST[21];                          //Declare an array of chars without initializing it as in String
sprintf(ST,"Runtime(MM:SS): %02d:%02d",runMinutes,runSeconds);
Serial.println(ST);
delay(1000);
}

void loop() {
  
}
