#include "MediaButton.h"

int d,e;

MediaButton::MediaButton(int dPin, int ePin){
  d = dPin;
  e = ePin;
}

void MediaButton::begin(){
  pinMode(d, OUTPUT);
  digitalWrite(d, LOW);
  pinMode(e, INPUT_PULLUP);
}

void MediaButton::refresh(HIDDevice hid1){
  //判断按键
  if(!digitalRead(e)){
    int i = 0;
    //按下循环
    while(!digitalRead(e)){
      delay(10);
      i++;
      //按下超时（上一首）
      if(i>50){
        hid1.rtcOnce(_PREVIOUS, 4);
        i = 0;
        while(!digitalRead(e)){
          if(i>1){
            hid1.rtcOnce(_PREVIOUS, 4);
          }
          delay(500);
          i++;
        }
        return;
      }
    }
    i = 0;
    //释放循环
    while(digitalRead(e)){
      delay(10);
      i++;
      //释放超时（暂停/播放）
      if(i>50){
        hid1.rtcOnce(_PLAY_PAUSE, 4);
        return;
      }
    }

    i = 0;
    //按下循环2
    while(!digitalRead(e)){
      delay(10);
      i++;
      //按下超时（上一首）
      if(i>50){
        hid1.rtcOnce(_NEXT, 4);
        i = 0;
        while(!digitalRead(e)){
          if(i>1){
            hid1.rtcOnce(_NEXT, 4);
          }
          delay(500);
          i++;
        }
        return;
      }
    }

    i = 0;
    //释放循环2
    while(digitalRead(e)){
      delay(10);
      i++;
      //释放超时（暂停/播放）
      if(i>50){
        hid1.rtcOnce(_NEXT, 4);
        return;
      }
    }

    //按下循环3
    while(!digitalRead(e)){
      delay(10);
      i++;
      //按下超时（喜欢）
      if(i>50){
        hid1.hotkeyOnce(2);
        while(!digitalRead(e)){
        }
        return;
      }
    }
    hid1.hotkeyOnce(2);
    return;

  }
}
