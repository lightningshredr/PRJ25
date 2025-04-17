#include  "PRJ25.h"
#include  <Arduino.h>
PRJ25::PRJ25(void)
{
/* for DRV8855  
pinMode(enA,OUTPUT);
pinMode(enB,OUTPUT);
pinMode(phA,OUTPUT);
pinMode(phB,OUTPUT);
*/
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
pinMode(limS,INPUT);

//for TB6612FNG
pinMode(PWMA,OUTPUT);
pinMode(PWMB,OUTPUT);
pinMode(AIN1,OUTPUT);
pinMode(BIN1,OUTPUT);
pinMode(STBY, OUTPUT);

}
long PRJ25::getRealDist(){
  return realDist;
}