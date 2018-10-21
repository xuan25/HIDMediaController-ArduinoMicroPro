#ifndef Encoder_H
#define Encoder_H

#include "arduino.h"

class Encoder{
  private:int prePinA;
  private:int prePinB;
  private:int preDire;
  private:int a,b,c;

  public:Encoder(int aPin, int bPin, int cPin);
  public:void begin();
  private:int nextFrame();
  public:int refresh();
};

#endif
