#ifndef PRJ25_H
#define PRJ25_H
#include  <Arduino.h>
//Ultrasonic Sensor
#define trigPin 13
#define echoPin 12

//motor controller
// for TB6612FNG
#define PWMA 5
#define PWMB 6
#define AIN1 7
#define BIN1 8
#define STBY 3

//for drv885 
/*
#define enA 5
#define enB 6
#define phA 8
#define phB 7
*/


//limit switch
#define limS  11

class PRJ25
{
  public:
    PRJ25(void);
    void  forward();
    void  backward();
    void  stop();
    void  armForward();
    void  armBackward();
    void  armBrake();
    long  getDistance();
    bool  ballLoaded();
    bool  forwardDist(long dist);
    bool  backwardDist(long dist);
    long  getRealDist();
    int cycle = 0;
  private:
    //starting line distance in cm
    long realDist = 25.4*6*12;
};

extern PRJ25 car;

#endif