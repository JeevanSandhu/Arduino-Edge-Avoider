#include <NewPing.h>
#define motorA_front 10
#define motorB_front 3
#define motorA_back 9
#define motorB_back 2

#define sonarA_trig 12
#define sonarA_echo 13

#define sonarB_trig 11
#define sonarB_echo 7

NewPing sonarA(sonarA_trig,sonarA_echo,200);
NewPing sonarB(sonarB_trig,sonarB_echo,200);

void setup() {
    pinMode(motorB_back, OUTPUT);
    pinMode(motorA_back, OUTPUT);
    pinMode(motorB_front, OUTPUT);
    pinMode(motorA_front, OUTPUT);

    Serial.begin(9600);
}

int delay1=0;

void loop() {
  int distanceA=sonarA.ping_cm();
  int distanceB=sonarB.ping_cm();
  Serial.print("A : ");
  Serial.println(distanceA);
  Serial.print("B : ");
  Serial.println(distanceB);

  if((distanceA==0 || distanceA>10) && (distanceB==0 || distanceB>10))
  {
    digitalWrite(motorA_front,LOW);
    digitalWrite(motorA_back,HIGH);
    digitalWrite(motorB_front,LOW);
    digitalWrite(motorB_back,HIGH);
    delay1=1;
  }
  else if(distanceA!=0 && distanceA<=10 && distanceB!=0 && distanceB<=10)
  {
    digitalWrite(motorA_front,HIGH);
    digitalWrite(motorA_back,LOW);
    digitalWrite(motorB_front,HIGH);
    digitalWrite(motorB_back,LOW);
  }
  else if(distanceA==0 || distanceA>10)
  {
    digitalWrite(motorA_front,HIGH);
    digitalWrite(motorA_back,LOW);
    digitalWrite(motorB_front,LOW);
    digitalWrite(motorB_back,LOW);    
  }
  else if(distanceB==0 || distanceB>10)
  {
    digitalWrite(motorA_front,LOW);
    digitalWrite(motorA_back,LOW);
    digitalWrite(motorB_front,HIGH);
    digitalWrite(motorB_back,LOW);    
  }  

  if(delay1==1)
  {
    delay(1000);
    digitalWrite(motorA_front,HIGH);
    digitalWrite(motorA_back,LOW);
    digitalWrite(motorB_front,LOW);
    digitalWrite(motorB_back,LOW);
    delay(1000);
    delay1=0;
  }

  delay(500);
}
