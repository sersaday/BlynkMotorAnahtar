/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on NodeMCU.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right NodeMCU module
  in the Tools -> Board menu!

  For advanced settings please follow ESP examples :
   - ESP8266_Standalone_Manual_IP.ino
   - ESP8266_Standalone_SmartConfig.ino
   - ESP8266_Standalone_SSL.ino

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "Token from eMail";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "XXXXXXXXX";
char pass[] = "XXXXXXXXX";
int readD1;
int readD2;
int OzoneSensor = 4;
int AirSensor = l5;

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(OzoneSensor,OUTPUT);
  pinMode(AirSensor,OUTPUT);
  pinMode(A0,INPUT);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

}

void loop()
{
  Blynk.run();
  //for first sensor
  digitalWrite(OzoneSensor, HIGH);     //Turn D1 On
  delay(100);                     
  readD1 = analogRead(0);       //Read Analog value of first sensor
  digitalWrite(OzoneSensor, LOW);      //Turn D1 Off
  delay(100);   
 //for second sensor
  digitalWrite(AirSensor, HIGH);     //Turn D2 On
  delay(100);                     
  readD2 = analogRead(0);       //Read Analog value of second sensor
  digitalWrite(AirSensor, LOW);      //Turn D2 Off
  delay(100);                     
  
  //to the serial monitor
  Serial.print("sensor 1 = ");   
  Serial.print(readD1);
  Serial.print(" / sensor 2 = ");   
  Serial.println(readD2);

  Blynk.virtualWrite(V5, readD1);  // to Blynk server
  Blynk.virtualWrite(V6, readD2);  // to Blynk server
  
}
