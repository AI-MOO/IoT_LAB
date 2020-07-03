#include <ESP8266WiFi.h>
#include <PubSubClient.h>


// Update these with values suitable for your network.
const char* ssid = "*****************";                  /// Replace asterisks by your network label 
const char* password = "*************";                 /// Replace asterisks by your password
const char* mqtt_server = "mqtt.eclipse.org";           /// mqtt server !!! 
const char* topic_action = "Home/";                     /// asign a topic to subscrib and publish 
const char* topic_status = "Home/";   

WiFiClient espClient;
PubSubClient client(espClient);

unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE  (50)                          
char msg[MSG_BUFFER_SIZE];
#define MSG_BUFFER_SIZE1  (50)
char msg1[MSG_BUFFER_SIZE1];

int value = 0;
float Steam = 0.0;
void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  pinMode(2, OUTPUT);                                /// prepare LED_Blue in Pin GPIO2 (pin D4) 
  digitalWrite(2, LOW);
  pinMode(5, OUTPUT);                               /// prepare LED_Green in Pin GPIO5 (pin D1)
  digitalWrite(5, LOW);
}



//// no change here 
void setup_wifi() {
   delay(100);
  // We start by connecting to a WiFi network
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) 
    {
      delay(500);
      Serial.print(".");
    }
  randomSeed(micros());
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) 
{
  Serial.print("Command from MQTT broker is : [");
  Serial.print(topic);
  Serial.print("Changing Room lamp to ");
  int p =(char)payload[0]-'0';
  int s =(char)payload[0]-'0';
  if(p == 1){                                             /// asign a conditin to make the swtich on node-red control LED_Blue
        digitalWrite(2, HIGH);
        Serial.print("On");   
      }
  else if(p == 0){
        digitalWrite(2, LOW);
        Serial.print("Off");
      }
  if(s == 2){                                            /// asign a conditin to make the swtich on node-red control LED_Green
        digitalWrite(5, HIGH);
        Serial.print("On");
      }
  else if(s == 3){
        digitalWrite(5, LOW);
        Serial.print("Off");
      }
  
  Serial.println();
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) 
  {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    //if you MQTT broker has clientID,username and password
    //please change following line to    if (client.connect(clientId,userName,passWord))
    if (client.connect(clientId.c_str()))
    {
      Serial.println("connected");
     //once connected to MQTT broker, subscribe command if any
      client.subscribe("Home/LED");                                             /// subscribe to the LED switch topic 
      client.subscribe("Home/LED");                                             /// subscribe to the LED switch topic
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 6 seconds before retrying
      delay(6000);
    }
  }
} //end reconnect()



void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();


/// this loop for steam sensor 
  unsigned long now = millis();
  if (now - lastMsg > 2000) {               
    lastMsg = now;
    ++value;
    
    snprintf (msg, MSG_BUFFER_SIZE, "%lf", (5.0f/1024)*analogRead(A0));             ///snprintf (msg, MSG_BUFFER_SIZE, "Steam Sensor Reading (v): #%lf volt", (5.0f/1024)*analogRead(A0));
    
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish("Home/sensor", msg);                                           // publish data through sensor topic 
   
    
    snprintf (msg1, MSG_BUFFER_SIZE1, "%ld", analogRead(A0));                      ///snprintf (msg, MSG_BUFFER_SIZE, "Steam Sensor Reading : #%ld analog reading", analogRead(A0));
    Serial.print("Publish message: ");
    Serial.println(msg1);
    client.publish("Home/Gauge", msg1);                                            /// publish data through sensor topic 
  
  }
}
