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
  if(digitalRead(limS) == HIGH)
    {
      delay(200);
      if(digitalRead(limS) == HIGH){
        return true;
        cycle++;
      }
    }
  return false;
}
