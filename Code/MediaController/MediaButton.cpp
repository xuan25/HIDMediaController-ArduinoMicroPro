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
        //#按钮长按保持#
        hid1.mediaControl(PREVIOUS);
        hid1.mediaControl(0);
        i = 0;
        while(!digitalRead(e)){
          if(i>1){
            //#按钮长按保持循环#
            hid1.mediaControl(PREVIOUS);
            hid1.mediaControl(0);
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
        //#按钮短按#
        hid1.mediaControl(PLAY_PAUSE);
        hid1.mediaControl(0);
        return;
      }
    }

    i = 0;
    //按下循环2
    while(!digitalRead(e)){
      delay(10);
      i++;
      //按下超时（下一首）
      if(i>50){
        //#按钮双击保持#
        hid1.mediaControl(NEXT);
        hid1.mediaControl(0);
        i = 0;
        while(!digitalRead(e)){
          if(i>1){
            //#按钮双击保持循环#
            hid1.mediaControl(NEXT);
            hid1.mediaControl(0);
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
      //释放超时（下一首）
      if(i>50){
        //#按钮双击#
        hid1.mediaControl(NEXT);
        hid1.mediaControl(0);
        return;
      }
    }

    //按下循环3
    while(!digitalRead(e)){
      delay(10);
      i++;
      //按下超时（喜欢）
      if(i>50){
        //#按钮三击保持#
        hid1.keyEvent(KEY_LEFT_CTRL | KEY_LEFT_ALT, KEY_L, 0, 0, 0, 0, 0);
        hid1.keyEvent(0, 0, 0, 0, 0, 0, 0);
        while(!digitalRead(e)){
          //#按钮三击保持循环#
          delay(500);
        }
        return;
      }
    }
    //#按钮三击#
    hid1.keyEvent(KEY_LEFT_CTRL | KEY_LEFT_ALT, KEY_L, 0, 0, 0, 0, 0);
    hid1.keyEvent(0, 0, 0, 0, 0, 0, 0);
    return;

  }
}
