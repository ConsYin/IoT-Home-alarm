#include <stdio.h>
#include <wiringPi.h>
#include <time.h>
#include "ifttt.h"
void sounding(){
  time_t t;t= time(NULL);
  int i;
  while(1){
    if (((time(NULL)-t)%2)==0){digitalWrite(1,HIGH);digitalWrite(2,HIGH);
        digitalWrite(4,HIGH);}
    else{digitalWrite(1,LOW);digitalWrite(2,LOW);digitalWrite(4,LOW);}
    if(digitalRead(3)==0){off();}
    if(i<1){
ifttt("https://maker.ifttt.com/trigger/alarm_triggered/with/key/b1QwPwFliGUWnU6LYgRbb1","yxy","intruder","triggered");}
    ++i;
     }

}
void triggered()
{  
   time_t t;
   t= time(NULL);
   while((time(NULL)-t)<=10){
    if (((time(NULL)-t)%2)==0){digitalWrite(1,LOW);digitalWrite(2,LOW);}
    else{digitalWrite(1,HIGH);digitalWrite(2,HIGH);}
    if(digitalRead(3)==0){off();}
     }
    sounding();
}
void armed()
{digitalWrite(2,HIGH);
while(1){
if(digitalRead(0)==1){triggered();}
}
}
void arming()
{
digitalWrite(1,HIGH);delay(1000);digitalWrite(1,LOW);delay(1000);
digitalWrite(1,HIGH);delay(1000);digitalWrite(1,LOW);delay(1000);
digitalWrite(1,HIGH);delay(1000);digitalWrite(1,LOW);delay(1000);
digitalWrite(1,HIGH);delay(1000);digitalWrite(1,LOW);delay(1000);
digitalWrite(1,HIGH);delay(1000);digitalWrite(1,LOW);delay(1000);
armed();
}

void off()
{digitalWrite(1,LOW);digitalWrite(2,LOW);
while(digitalRead(3)==1){}
arming();
}
int main(int argc, char *argv[])
{
  wiringPiSetup () ;
  pinMode(3, INPUT);pinMode(0,INPUT);pinMode(1, OUTPUT);pinMode(2, OUTPUT);
  pinMode(4,OUTPUT);digitalWrite(4,LOW);digitalWrite(2,LOW);
  digitalWrite(1,LOW);
  pullUpDnControl(3, PUD_UP);
  off();
  /*while(1) {
    printf("Waiting for reset\n");
    while(digitalRead(3) == 1);
    printf("Waiting for event\n");
    while(digitalRead(3) == 0);
    printf("Alarm\n");
  }
  NOTREACHED*/
  return 0 ;
}
