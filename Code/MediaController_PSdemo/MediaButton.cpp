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
      //按下超时（裁剪）
      if(i>50){
        hid1.keyEvent(KEY_LEFT_CTRL, KEY_T, 0, 0, 0, 0, 0);
        hid1.keyEvent(0, 0, 0, 0, 0, 0, 0);
        i = 0;
        while(!digitalRead(e)){
          //
        }
        return;
      }
    }
    i = 0;
    //释放循环
    while(digitalRead(e)){
      delay(10);
      i++;
      //释放超时（确认）
      if(i>50){
        hid1.keyEvent(0, KEY_RETURN, 0, 0, 0, 0, 0);
        hid1.keyEvent(0, 0, 0, 0, 0, 0, 0);
        return;
      }
    }

    i = 0;
    //按下循环2
    while(!digitalRead(e)){
      delay(10);
      i++;
      //按下超时（保存）
      if(i>50){
        hid1.keyEvent(KEY_LEFT_CTRL, KEY_S, 0, 0, 0, 0, 0);
        hid1.keyEvent(0, 0, 0, 0, 0, 0, 0);
        i = 0;
        while(!digitalRead(e)){
          //
        }
        return;
      }
    }

    i = 0;
    //释放循环2
    while(digitalRead(e)){
      delay(10);
      i++;
      //释放超时（保存）
      if(i>50){
        hid1.keyEvent(KEY_LEFT_CTRL, KEY_S, 0, 0, 0, 0, 0);
        hid1.keyEvent(0, 0, 0, 0, 0, 0, 0);
        return;
      }
    }

    //按下循环3
    while(!digitalRead(e)){
      delay(10);
      i++;
      //按下超时（新图层）
      if(i>50){
        hid1.keyEvent(KEY_LEFT_CTRL | KEY_LEFT_SHIFT, KEY_N, 0, 0, 0, 0, 0);
        hid1.keyEvent(0, 0, 0, 0, 0, 0, 0);
        while(!digitalRead(e)){
        }
        return;
      }
    }
    hid1.keyEvent(KEY_LEFT_CTRL | KEY_LEFT_SHIFT, KEY_N, 0, 0, 0, 0, 0);
    hid1.keyEvent(0, 0, 0, 0, 0, 0, 0);
    return;

  }
}
