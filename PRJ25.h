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

//for drv8855 
/*
#define enA 5
#define enB 6
#define phA 8
#define phB 7
*/
//limit switch
#define limS  11

//meters per second ~estimated, need to test
#define VMAX 30

class PRJ25 {
  public:
    void setup();
    void  forward(int speed);
    void  backward(int speed);
    void  stop();
    void  armForward(int speed);
    void  armBackward(int speed);
    void  armBrake();
    int  vectorf(long p,long i, long d);
    int  vectorb(long k, long d);
    long  getDistance();
    bool  ballLoaded();
    long  getMinDist();
    long  getMaxDist();
    void  setMaxDist();
    int cycle = 0;
    bool s = true;
  private:
    long maxDist;
    //minimum distance in m
    long minDist;
};

//extern PRJ25 car;
#endif