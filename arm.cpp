#include  "arm.h"
void PRJ25::armForward()
{
  digitalWrite(enB, HIGH);
  digitalWrite(phB, HIGH);
}
void PRJ25::armBackward()
{
  digitalWrite(enB, HIGH);
  digitalWrite(phB, LOW);
}
void PRJ25::armBrake()
{
  digitalWrite(enB, LOW);
  digitalWrite(phB, LOW);
}