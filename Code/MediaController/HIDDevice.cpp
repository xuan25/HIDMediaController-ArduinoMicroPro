#include "HIDDevice.h"

static const uint8_t HIDDevice::_hidReportDescriptor[] PROGMEM = {
  
  //Button
    0x05, 0x0c,                    // Usage Page (Consumer Devices)
    0x09, 0x01,                    // Usage (Consumer Control)
    0xa1, 0x01,                    // Collection (Application)
    0x85, 0x04,                    //   REPORT_ID (4)
    0x09, 0xe9,                    //   Usage (Volume Up)
    0x09, 0xea,                    //   Usage (Volume Down)
    0x09, 0xe2,                    //   Usage (Mute)
    0x09, 0xcd,                    //   Usage (Play)
    0x09, 0xb5,                    //   Usage (Next)
    0x09, 0xb6,                    //   Usage (Previous)
    0x15, 0x00,                    //   Logical Minimum (0)
    0x25, 0x01,                    //   Logical Maximum (1)
    0x75, 0x01,                    //   Report Size (1)
    0x95, 0x10,                    //   Report Count (10)
    0x81, 0x06,                    //   Input (Data, Variable, Relative)
    0xc0,                          // End Collection

    //  Keyboard
    0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)  // 47
    0x09, 0x06,                    // USAGE (Keyboard)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x85, 0x02,                    //   REPORT_ID (2)
    0x05, 0x07,                    //   USAGE_PAGE (Keyboard)
   
  0x19, 0xe0,                    //   USAGE_MINIMUM (Keyboard LeftControl)
    0x29, 0xe7,                    //   USAGE_MAXIMUM (Keyboard Right GUI)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0x01,                    //   LOGICAL_MAXIMUM (1)
    0x75, 0x01,                    //   REPORT_SIZE (1)
    
  0x95, 0x08,                    //   REPORT_COUNT (8)
    0x81, 0x02,                    //   INPUT (Data,Var,Abs)
    0x95, 0x01,                    //   REPORT_COUNT (1)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x81, 0x03,                    //   INPUT (Cnst,Var,Abs)
    
  0x95, 0x06,                    //   REPORT_COUNT (6)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0x65,                    //   LOGICAL_MAXIMUM (101)
    0x05, 0x07,                    //   USAGE_PAGE (Keyboard)
    
  0x19, 0x00,                    //   USAGE_MINIMUM (Reserved (no event indicated))
    0x29, 0x65,                    //   USAGE_MAXIMUM (Keyboard Application)
    0x81, 0x00,                    //   INPUT (Data,Ary,Abs)
    0xc0,                          // END_COLLECTION
     
};

HIDDevice::HIDDevice(){
  
}

void HIDDevice::begin(){
  static HIDSubDescriptor node(_hidReportDescriptor, sizeof(_hidReportDescriptor));
  HID().AppendDescriptor(&node);
}

void HIDDevice::rtcOnce(u8 c, int id){
  u8 m[2];
  m[0] = c;
  m[1] = 0;
  HID().SendReport(id,m,2);
  m[0] = 0;
  m[1] = 0;
  HID().SendReport(id,m,2);
}

void HIDDevice::hotkeyOnce(int id){
  u8 m[8];
  m[0] = 0;                   //modifiers
  m[0] |= (1<<KEY_LEFT_CTRL);
  m[0] |= (1<<KEY_LEFT_ALT);
  m[1] = 0;                   //reserved
  m[2] = KEY_L;               //6 keys
  m[3] = 0;
  m[4] = 0;
  m[5] = 0;
  m[6] = 0;
  m[7] = 0;
  HID().SendReport(id,m,8);
  m[0] = 0;
  m[2] = 0;
  m[3] = 0;
  m[4] = 0;
  m[5] = 0;
  m[6] = 0;
  m[7] = 0;
  HID().SendReport(id,m,8);
}
