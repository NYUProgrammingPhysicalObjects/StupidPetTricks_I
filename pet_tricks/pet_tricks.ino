#include <NewPing.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

int fadeLight = 6; // fade light (simulate yelling Woah)
int blinkLight = 13; // blink (simulate dog barking)
int brightness = 0;
int fadeAmt = 5;

void setup()
{
  pinMode(blinkLight,OUTPUT);
  pinMode(fadeLight,OUTPUT);
  digitalWrite(blinkLight,0);
  analogWrite(fadeLight,0);
  Serial.begin(9600);
}


void loop(){
 delay (50);
 
 /***********************Ultrasonic Part****************************/
 unsigned int pre = sonar.ping();
 unsigned int dist = pre/US_ROUNDTRIP_CM; // calculating distance
 Serial.print("Distance is: ");
 Serial.print(dist);
 Serial.println(" cm");
 
 /********************End of Ultrasonic Part***********************/ 
 
  /**********************Pet Tricks Part***************************/ 
  if(dist<=10)
    {
      digitalWrite(fadeLight,0);
      /*************simulates a barking pattern**************************/
      digitalWrite(blinkLight,1);
      delay(100);
      digitalWrite(blinkLight,0);
      delay(100);
      digitalWrite(blinkLight,1);
      delay(100);
      digitalWrite(blinkLight,0);
      delay(500);
      /*******************end of barking pattern ***********************/
    }
  else if(dist>10 && dist<=50)
  {
    digitalWrite(blinkLight,0);
    /*************simulates screaming woah*****************************/
    analogWrite(fadeLight,brightness);
    
    brightness = brightness+fadeAmt;
    if(brightness == 0 || brightness == 127)
    {
      fadeAmt = -fadeAmt;
    }
    
    /*************end of all screaming and barking*********************/
    //delay(30);
  }
 /********************End of Pet Tricks Part***********************/ 
}


