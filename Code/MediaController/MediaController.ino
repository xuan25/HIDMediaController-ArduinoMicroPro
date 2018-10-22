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

void loop() {
  int re = enc1.refresh();
  if(re == 1){
    //#编码器正转#
    hid1.mediaControl(VOLUME_INCREMENT);
  }
  else if(re == -1){
    //#编码器反转#
    hid1.mediaControl(VOLUME_DECREMENT);
  }

  btn1.refresh(hid1);
}
