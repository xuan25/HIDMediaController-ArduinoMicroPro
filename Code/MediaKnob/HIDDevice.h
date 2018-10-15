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
