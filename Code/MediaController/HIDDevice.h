#ifndef HIDDevice_H
#define HIDDevice_H

#include "arduino.h"
#include <HID.h>

#define VOLUME_INCREMENT 0x01
#define VOLUME_DECREMENT 0x02
#define MUTE 0x04
#define PLAY_PAUSE 0x08
#define NEXT 0x10
#define PREVIOUS 0x20

#define MOUSE_LEFT 0x00
#define MOUSE_RIGHT 0x01
#define MOUSE_MIDDLE 0x04

#define KEY_LEFT_CTRL 1<<0x00
#define KEY_LEFT_SHIFT 1<<0x01
#define KEY_LEFT_ALT 1<<0x02
#define KEY_LEFT_GUI 1<<0x03
#define KEY_RIGHT_CTRL 1<<0x04
#define KEY_RIGHT_SHIFT 1<<0x05
#define KEY_RIGHT_ALT 1<<0x06
#define KEY_RIGHT_GUI 1<<0x07

#define KEY_UP_ARROW    0x52
#define KEY_DOWN_ARROW    0x51
#define KEY_LEFT_ARROW    0x50
#define KEY_RIGHT_ARROW   0x4f
#define KEY_BACKSPACE   0x2a
#define KEY_TAB       0x2b
#define KEY_RETURN      0x28
#define KEY_ESC       0x29
#define KEY_INSERT      0x49
#define KEY_DELETE      0x4c
#define KEY_PAGE_UP     0x4b
#define KEY_PAGE_DOWN   0x4e
#define KEY_HOME      0x4a
#define KEY_END       0x4d
#define KEY_CAPS_LOCK   0x39
#define KEY_F1        0x3a
#define KEY_F2        0x3b
#define KEY_F3        0x3c
#define KEY_F4        0x3d
#define KEY_F5        0x3e
#define KEY_F6        0x3f
#define KEY_F7        0x40
#define KEY_F8        0x41
#define KEY_F9        0x42
#define KEY_F10       0x43
#define KEY_F11       0x44
#define KEY_F12       0x45

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

class HIDDevice{
  private:static const uint8_t _hidReportDescriptor[] PROGMEM; 

  public:HIDDevice();
  public:void begin();
  public:void mediaControl(uint8_t c);
  public:void keyEvent(uint8_t modifiers, uint8_t key1, uint8_t key2, uint8_t key3, uint8_t key4, uint8_t key5, uint8_t key6);
  public:void mouseEvent(uint8_t buttons, uint8_t x, uint8_t y, uint8_t wheel);
};

#endif
