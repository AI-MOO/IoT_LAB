#include <ESP8266WiFi.h>
#include <PubSubClient.h>


// Update these with values suitable for your network.
const char* ssid = "HUAWEI Mate 10";
const char* password = "12345678";
const char* mqtt_server = "mqtt.eclipse.org";
const char* topic_action = "tvt/action"; 
const char* topic_status = "tvt/status"; 

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW); 
}

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
  int p =(char)payload[0]-'0';
  // if MQTT comes a 0 turn off LED on D2
  if(p==0) 
  {
     digitalWrite(2, LOW); 
    Serial.println(" Turn Off LED! " );
  } 
  // if MQTT comes a 1, turn on LED on pin D2
  if(p==1)
  {
     digitalWrite(2, HIGH); 
    Serial.println(" Turn On LED! " );
  }
  Serial.println();
} //end callback

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
      client.subscribe("tvt/action");
      client.subscribe("tvt/status");
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

}
