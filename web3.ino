#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
 
const char* ssid= "dlink";
const char* pass= "12345678900";
const int trigger = 2;
const int echo = 0;
const int trigger1 = 4; //D4
const int echo1 = 5; //D5
long T;
long T1;
float distanceCM;
float distanceCM1;
WiFiClient  client;

unsigned long myChannelField = 998606; // Channel ID
unsigned long myChannelField1 = 998611;
const int ChannelField = 1; // Which channel to write data
const int ChannelField1 = 1; 
const char * myWriteAPIKey = "L6IDPH5P6VJQ2NUB"; // Your write API Key
const char * myWriteAPIKey1 = "Z9T5ZUUT1NVP0O3W";


void setup()
{
  Serial.begin(115200);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trigger1, OUTPUT);
  pinMode(echo1, INPUT);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}
void loop()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConnected.");
     Serial.println(WiFi.localIP());
  }
  digitalWrite(trigger, LOW);
  delay(1);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  T = pulseIn(echo, HIGH);
  distanceCM = T * 0.034;
  distanceCM = distanceCM / 2;
  Serial.print("Distance in cm: ");
  Serial.println(distanceCM);
  digitalWrite(trigger1, LOW);
  delay(1);
  digitalWrite(trigger1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger1, LOW);
  T1 = pulseIn(echo1, HIGH);
  distanceCM1 = T1 * 0.034;
  distanceCM1 = distanceCM1 / 2;
  Serial.print("Distance in cm1: ");
  Serial.println(distanceCM1);
  ThingSpeak.writeField(myChannelField, ChannelField, distanceCM, myWriteAPIKey);
  ThingSpeak.writeField(myChannelField1, ChannelField1, distanceCM1, myWriteAPIKey1);
  delay(1000);
}
