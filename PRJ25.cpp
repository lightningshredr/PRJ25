#include  "PRJ25.h"
#include  <Arduino.h>

void PRJ25::setup()
{
  /* for DRV8855  
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
  pinMode(phA,OUTPUT);
  pinMode(phB,OUTPUT);
  */
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(limS,INPUT_PULLUP);

  //for TB6612FNG
  pinMode(PWMA,OUTPUT);
  pinMode(PWMB,OUTPUT);
  pinMode(AIN1,OUTPUT);
  pinMode(BIN1,OUTPUT);
  pinMode(STBY, OUTPUT);
  s = true;
  maxDist = 184;
  minDist = 15;
  Serial.println("initial distance(in): "+maxDist);
}

int PRJ25::vectorf(long p, long i, long d){
  auto k = i;
  auto v = (k*p*(d-p))/d;
  forward(30);
  auto s = (v/VMAX)*255;
  forward(s);
  if(getDistance() >= getMinDist()-0.006){
    return 0.0;
  }
  else{
    vectorf(getDistance(),k,d);
  }

}

int PRJ25::vectorb(long i, long d){
  return 0.0;
}

void PRJ25::forward(int speed){
  digitalWrite(STBY,HIGH);
  digitalWrite(AIN1,HIGH);
  analogWrite(PWMA, speed);
  /*for drv8855
  digitalWrite(enA, HIGH);
  digitalWrite(phA, HIGH);
  */
}

void PRJ25::backward(int speed){
  digitalWrite(STBY,HIGH);
  digitalWrite(AIN1,LOW);
  analogWrite(PWMA, speed);
  /*for drv8855
  digitalWrite(enA, HIGH);
  digitalWrite(phA, LOW);
  */
}

void PRJ25::stop(){
  digitalWrite(STBY,HIGH);
  digitalWrite(AIN1,LOW);
  analogWrite(PWMA, 0);
  digitalWrite(STBY, LOW);
  /*
  digitalWrite(enA, LOW);
  digitalWrite(phA, LOW);
  */
}

void PRJ25::armForward(int speed)
{
  digitalWrite(STBY,HIGH);
  digitalWrite(BIN1,HIGH);
  analogWrite(PWMB, speed);
  /*for drv8855
  digitalWrite(enB, HIGH);
  digitalWrite(phB, HIGH);
  */
}

void PRJ25::armBackward(int speed)
{
  digitalWrite(STBY,HIGH);
  digitalWrite(BIN1,LOW);
  analogWrite(PWMB, speed);
  /*for drv8855
  digitalWrite(enB, HIGH);
  digitalWrite(phB, LOW);
  */
}

void PRJ25::armBrake()
{
  digitalWrite(STBY,HIGH);
  digitalWrite(BIN1,LOW);
  analogWrite(PWMB, 0);
  digitalWrite(STBY, LOW);
  /*for drv8855
  digitalWrite(enB, LOW);
  digitalWrite(phB, LOW);
  */
}

long PRJ25::getDistance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  long cm = (duration/2)/29.1;
  long m = cm/100;
  return cm;
}
  bool PRJ25::ballLoaded(){
  int ct = 0;
  while(ct<3)
  {
    delay(10);
  if(digitalRead(limS) == HIGH)
    {
      ct=0;
      return true;
    }
    else{
      ct++;
    }
  }
  return false;
}

long PRJ25::getMinDist(){
  return minDist;
}

long PRJ25::getMaxDist(){
  return maxDist;
}

void PRJ25::setMaxDist(){
  //m
  //maxDist = getDistance();

}
