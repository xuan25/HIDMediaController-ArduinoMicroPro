#ifndef HIDDevice_H
#define HIDDevice_H

#include "arduino.h"
#include <HID.h>

#define _VOLUME_INCREMENT 0x01
#define _VOLUME_DECREMENT 0x02
#define _MUTE 0x04
#define _PLAY_PAUSE 0x08
#define _NEXT 0x10
#define _PREVIOUS 0x20

#define KEY_LEFT_CTRL   0x00
#define KEY_LEFT_SHIFT    0x01
#define KEY_LEFT_ALT    0x02
#define KEY_LEFT_GUI    0x03
#define KEY_RIGHT_CTRL    0x04
#define KEY_RIGHT_SHIFT   0x05
#define KEY_RIGHT_ALT   0x06
#define KEY_RIGHT_GUI   0x07

#define KEY_A    0x04
#define KEY_B    0x05
#define KEY_C    0x06
#define KEY_D    0x07
#define KEY_E    0x08
#define KEY_F    0x09
#define KEY_G    0x0a
#define KEY_H    0x0b
#define KEY_I    0x0c
#define KEY_J    0x0d
#define KEY_K    0x0e
#define KEY_L    0x0f
#define KEY_M    0x10
#define KEY_N    0x11
#define KEY_O    0x12
#define KEY_P    0x13
#define KEY_Q    0x14
#define KEY_R    0x15
#define KEY_S    0x16
#define KEY_T    0x17
#define KEY_U    0x18
#define KEY_V    0x19
#define KEY_W    0x1a
#define KEY_X    0x1b
#define KEY_Y    0x1c
#define KEY_Z    0x1d

typedef struct
{
  uint8_t modifiers;
  uint8_t reserved;
  uint8_t keys[6];
} KeyReport;

class HIDDevice{
  private:static const uint8_t _hidReportDescriptor[] PROGMEM; 

  public:HIDDevice();
  public:void begin();
  public:void rtcOnce(u8 c, int id);
  public:void hotkeyOnce(int id);
};

#endif
