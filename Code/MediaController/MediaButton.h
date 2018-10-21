#ifndef MediaButton_H
#define MediaButton_H

#include "arduino.h"
#include "HIDDevice.h"

class MediaButton{
  private:int d,e;
  
  public:MediaButton(int dPin, int ePin);
  public:void begin();
  public:void refresh(HIDDevice hid1);
};

#endif
