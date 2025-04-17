#include  "arm.h"
void PRJ25::armForward()
{
  digitalWrite(STBY,HIGH);
  digitalWrite(BIN1,HIGH);
  analogWrite(PWMB, 100);
  /*for drv8855
  digitalWrite(enB, HIGH);
  digitalWrite(phB, HIGH);
  */
}
void PRJ25::armBackward()
{
  digitalWrite(STBY,HIGH);
  digitalWrite(BIN1,LOW);
  analogWrite(PWMB, 100);
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