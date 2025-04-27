#include  "PRJ25.h"

PRJ25 car;

void setup() {
  car.setup();
  Serial.begin(9600);
}

void loop() 
{ 
    car.setMaxDist();
    delay(10);
    while(car.ballLoaded()){
      delay(1);
    }
    //car.vectorf(car.getDistance(),2,car.getMaxDist());
    
    while(car.getDistance() >= 28 ){
      //car.forward(160);
      car.vectorf(car.getDistance(),2,car.getMaxDist());
      }
    
    car.stop();
    delay(300);
    //car.armForward(92);
    car.armForward(255);
    delay(150);
    car.armBrake();
    delay(600);
    car.armBackward(60);
    delay(200);
    while(car.getDistance()<= car.getMaxDist()-0.006){
      car.backward(255);
    }
    car.backward(255);
    delay(2500);
    car.stop();
}