#include  "sensors.h"
long PRJ25::getDistance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  long cm = (duration/2)/29.1;
  return cm;
}
bool PRJ25::ballLoaded(){
  digitalWrite(limS,LOW);
  int ct = 0;
  while(ct<3)
  {
    delay(10);
  if(digitalRead(limS) == HIGH)
    {
      ct=0;
      return false;
    }
    else{
      ct++;
    }
  }
  return true;
}