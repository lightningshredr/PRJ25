#include  "PRJ25.h"
#include  <Arduino.h>
PRJ25::PRJ25(void)
{
pinMode(enA,OUTPUT);
pinMode(enB,OUTPUT);
pinMode(phA,OUTPUT);
pinMode(phB,OUTPUT);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
pinMode(limS,INPUT);
}
long PRJ25::getRealDist(){
  return realDist;
}