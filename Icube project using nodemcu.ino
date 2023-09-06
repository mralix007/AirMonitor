#include <Blynk.h>
#define BLYNK_TEMPLATE_ID "TMPLCjcDySll"
#define BLYNK_DEVICE_NAME "IQUBE PROJECT"
#define BLYNK_AUTH_TOKEN "k03BfZnrTiv94I7BH0EO6MoCbbgD1qTk"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
char auth[] = " k03BfZnrTiv94I7BH0EO6MoCbbgD1qTk";
 
/* WiFi credentials */
char ssid[] = "Honor Play";
char pass[] = "aditya28";
 
SimpleTimer timer;
 
int mq135 = A0; // smoke sensor is connected with the analog pin A0 
int data =0; 
void setup() 
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L,SendData); // new data will be updated every 1 sec 
}
 
void loop() 
{
  timer.run(); // Initiates SimpleTimer
  Blynk.run();
}
 
/***************************************************
 * Send Sensor data to Blynk
 **************************************************/
void SendData()
{
data = analogRead(mq135); 
  Blynk.virtualWrite(V2,data); //
}
 
