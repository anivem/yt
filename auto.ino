#define BLYNK_TEMPLATE_ID "---"
#define BLYNK_TEMPLATE_NAME "---"
#define BLYNK_AUTH_TOKEN "---"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

Servo servo_D0;


char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "guestwifi";
char pass[] = "guestwifi";

BLYNK_WRITE(V0)
{
  int value = param.asInt();
  if(value == 1)
  {

    servo_D0.write(30);

       
  }

  if(value == 0)
  {

    servo_D0.write(90);
    
       
  }


  
}


void setup() {
  // put your setup code here, to run once:

   Serial.begin(115200);
   Blynk.begin(auth, ssid, pass);
   pinMode(D7, OUTPUT);
   servo_D0.attach(D0, 500, 2500);

}

void loop() {
  // put your main code here, to run repeatedly:


   Blynk.run();
   
}
