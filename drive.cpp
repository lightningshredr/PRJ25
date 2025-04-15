#include  "drive.h"
void PRJ25::forward(){
  digitalWrite(enA, HIGH);
  digitalWrite(phA, HIGH);
}
void PRJ25::backward(){
  digitalWrite(enA, HIGH);
  digitalWrite(phA, LOW);
}
void PRJ25::stop(){
  digitalWrite(enA, LOW);
  digitalWrite(phA, LOW);
}
bool PRJ25::forwardDist(long dist){
  long distanceInit = car.getDistance();
  long travel = distanceInit-dist;
  if(distanceInit>(dist+car.getRealDist())) return 0;
  forward();
  while(getDistance()> travel)
  {
    delayMicroseconds(1);
  }
  stop();
}
bool PRJ25::backwardDist(long dist){
  long distanceInit = getDistance();
  long travel = distanceInit+dist;
  backward();
  while(getDistance()< travel)
  {
    delayMicroseconds(1);
  }
  stop();
}