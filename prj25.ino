#include  "PRJ25.h"
void setup() {
  PRJ25();
  Serial.begin(9600);

}

void loop() 
{
  int count = 0;
  long starting = car.getDistance();
  while(!car.ballLoaded()){
    delay(100);
  }
  car.forward();
  if(car.getDistance()<(2*2.54)){
    car.stop();
    while(car.ballLoaded()){
    car.armForward();
    delay(50);
    car.armBrake();
    delay(300);
    count++;
    }
    car.armBackward();
    delay(50*count);
    car.armBrake();
  }
  car.backwardDist(6*12.0*2.54);
  if(car.getDistance()<starting-0.25){
    car.backward();
    delay(50);
    car.stop();
  }
  if(car.getDistance()>starting+0.25){
    car.forward();
    delay(50);
    car.stop();
  }
}
