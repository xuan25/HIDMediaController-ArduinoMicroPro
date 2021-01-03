#include "Encoder.h"
#include "MediaButton.h"
#include "HIDDevice.h"

static int a=8,b=6,c=7,d=16,e=15;

Encoder enc1(a,b,c);
MediaButton btn1(d,e);
HIDDevice hid1;

void setup() {
  enc1.begin();
  btn1.begin();
  hid1.begin();
}

int total = 0;
int threshold = 5;
void loop() {
  int re = enc1.refresh();
  total += re;
  if(total == threshold){
    //#编码器正转#
    hid1.mediaControl(VOLUME_INCREMENT);
    hid1.mediaControl(0);
    total = 0;
  }
  else if(total == -threshold){
    //#编码器反转#
    hid1.mediaControl(VOLUME_DECREMENT);
    hid1.mediaControl(0);
    total = 0;
  }

  btn1.refresh(hid1);
}
