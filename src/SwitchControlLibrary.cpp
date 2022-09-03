#include "SwitchControlLibrary.h"

#if defined(_USING_HID)

static const uint8_t _hidReportDescriptor[] PROGMEM = {
    0x05, 0x01,       //   USAGE_PAGE (Generic Desktop)
    0x09, 0x05,       //   USAGE (Game Pad)
    0xa1, 0x01,       //   COLLECTION (Application)
    0x15, 0x00,       //   LOGICAL_MINIMUM (0)
    0x25, 0x01,       //   LOGICAL_MAXIMUM (1)
    0x35, 0x00,       //   PHYSICAL_MINIMUM (0)
    0x45, 0x01,       //   PHYSICAL_MAXIMUM (1)
    0x75, 0x01,       //   REPORT_SIZE (1)
    0x95, 0x10,       //   REPORT_COUNT (16)
    0x05, 0x09,       //   USAGE_PAGE (Button)
    0x19, 0x01,       //   USAGE_MINIMUM (1)
    0x29, 0x10,       //   USAGE_MAXIMUM (16)
    0x81, 0x02,       //   INPUT (Data,Var,Abs)
    0x05, 0x01,       //   USAGE_PAGE (Generic Desktop)
    0x25, 0x07,       //   LOGICAL_MAXIMUM (7)
    0x46, 0x3b, 0x01, //   PHYSICAL_MAXIMUM (315)
    0x75, 0x04,       //   REPORT_SIZE (4)
    0x95, 0x01,       //   REPORT_COUNT (1)
    0x65, 0x14,       //   UNIT (20)
    0x09, 0x39,       //   USAGE (Hat Switch)
    0x81, 0x42,       //   INPUT (Data,Var,Abs)
    0x65, 0x00,       //   UNIT (0)
    0x95, 0x01,       //   REPORT_COUNT (1)
    0x81, 0x01,       //   INPUT (Cnst,Arr,Abs)
    0x26, 0xff, 0x00, //   LOGICAL_MAXIMUM (255)
    0x46, 0xff, 0x00, //   PHYSICAL_MAXIMUM (255)
    0x09, 0x30,       //   USAGE (X)
    0x09, 0x31,       //   USAGE (Y)
    0x09, 0x32,       //   USAGE (Z)
    0x09, 0x35,       //   USAGE (Rz)
    0x75, 0x08,       //   REPORT_SIZE (8)
    0x95, 0x04,       //   REPORT_COUNT (4)
    0x81, 0x02,       //   INPUT (Data,Var,Abs)
    0x06, 0x00, 0xff, //   USAGE_PAGE (Vendor Defined 65280)
    0x09, 0x20,       //   USAGE (32)
    0x95, 0x01,       //   REPORT_COUNT (1)
    0x81, 0x02,       //   INPUT (Data,Var,Abs)
    0x0a, 0x21, 0x26, //   USAGE (9761)
    0x95, 0x08,       //   REPORT_COUNT (8)
    0x91, 0x02,       //   OUTPUT (Data,Var,Abs)
    0xc0              // END_COLLECTION
};

SwitchControlLibrary_::SwitchControlLibrary_()
{
    static HIDSubDescriptor node(_hidReportDescriptor, sizeof(_hidReportDescriptor));
    CustomHID().AppendDescriptor(&node);

    memset(&_joystickInputData, 0, sizeof(USB_JoystickReport_Input_t));
    _joystickInputData.LX = (uint8_t)Stick::CENTER;
    _joystickInputData.LY = (uint16_t)Stick::CENTER;
    _joystickInputData.RX = (uint16_t)Stick::CENTER;
    _joystickInputData.RY = (uint16_t)Stick::CENTER;
    _joystickInputData.Hat = (uint16_t)Hat::CENTER;
}

void SwitchControlLibrary_::sendReport()
{
    CustomHID().SendReport(&_joystickInputData, sizeof(USB_JoystickReport_Input_t));
}

void SwitchControlLibrary_::pressButtonY()
{
    _joystickInputData.Button |= (uint16_t)Button::Y;
}

void SwitchControlLibrary_::releaseButtonY()
{
    _joystickInputData.Button &= ((uint16_t)Button::Y ^ 0xffff);
}

void SwitchControlLibrary_::pressButtonB()
{
    _joystickInputData.Button |= (uint16_t)Button::B;
}

void SwitchControlLibrary_::releaseButtonB()
{
    _joystickInputData.Button &= ((uint16_t)Button::B ^ 0xffff);
}

void SwitchControlLibrary_::pressButtonA()
{
    _joystickInputData.Button |= (uint16_t)Button::A;
}

void SwitchControlLibrary_::releaseButtonA()
{
    _joystickInputData.Button &= ((uint16_t)Button::A ^ 0xffff);
}

void SwitchControlLibrary_::pressButtonX()
{
    _joystickInputData.Button |= (uint16_t)Button::X;
}

void SwitchControlLibrary_::releaseButtonX()
{
    _joystickInputData.Button &= ((uint16_t)Button::X ^ 0xffff);
}

void SwitchControlLibrary_::pressButtonL()
{
    _joystickInputData.Button |= (uint16_t)Button::L;
}

void SwitchControlLibrary_::releaseButtonL()
{
    _joystickInputData.Button &= ((uint16_t)Button::L ^ 0xffff);
}

void SwitchControlLibrary_::pressButtonR()
{
    _joystickInputData.Button |= (uint16_t)Button::R;
}

void SwitchControlLibrary_::releaseButtonR()
{
    _joystickInputData.Button &= ((uint16_t)Button::R ^ 0xffff);
}

void SwitchControlLibrary_::pressButtonZL()
{
    _joystickInputData.Button |= (uint16_t)Button::ZL;
}

void SwitchControlLibrary_::releaseButtonZL()
{
    _joystickInputData.Button &= ((uint16_t)Button::ZL ^ 0xffff);
}

void SwitchControlLibrary_::pressButtonZR()
{
    _joystickInputData.Button |= (uint16_t)Button::ZR;
}

void SwitchControlLibrary_::releaseButtonZR()
{
    _joystickInputData.Button &= ((uint16_t)Button::ZR ^ 0xffff);
}

void SwitchControlLibrary_::pressButtonMinus()
{
    _joystickInputData.Button |= (uint16_t)Button::MINUS;
}

void SwitchControlLibrary_::releaseButtonMinus()
{
    _joystickInputData.Button &= ((uint16_t)Button::MINUS ^ 0xffff);
}

void SwitchControlLibrary_::pressButtonPlus()
{
    _joystickInputData.Button |= (uint16_t)Button::PLUS;
}

void SwitchControlLibrary_::releaseButtonPlus()
{
    _joystickInputData.Button &= ((uint16_t)Button::PLUS ^ 0xffff);
}

void SwitchControlLibrary_::pressButtonLClick()
{
    _joystickInputData.Button |= (uint16_t)Button::LCLICK;
}

void SwitchControlLibrary_::releaseButtonLClick()
{
    _joystickInputData.Button &= ((uint16_t)Button::LCLICK ^ 0xffff);
}

void SwitchControlLibrary_::pressButtonRClick()
{
    _joystickInputData.Button |= (uint16_t)Button::RCLICK;
}

void SwitchControlLibrary_::releaseButtonRClick()
{
    _joystickInputData.Button &= ((uint16_t)Button::RCLICK ^ 0xffff);
}

void SwitchControlLibrary_::pressButtonHome()
{
    _joystickInputData.Button |= (uint16_t)Button::HOME;
}

void SwitchControlLibrary_::releaseButtonHome()
{
    _joystickInputData.Button &= ((uint16_t)Button::HOME ^ 0xffff);
}

void SwitchControlLibrary_::pressButtonCapture()
{
    _joystickInputData.Button |= (uint16_t)Button::CAPTURE;
}

void SwitchControlLibrary_::releaseButtonCapture()
{
    _joystickInputData.Button &= ((uint16_t)Button::CAPTURE ^ 0xffff);
}

void SwitchControlLibrary_::moveHat(uint8_t hat)
{
    _joystickInputData.Hat = hat;
}

void SwitchControlLibrary_::moveLeftStick(uint8_t lx, uint8_t ly)
{
    _joystickInputData.LX = lx;
    _joystickInputData.LY = ly;
}

void SwitchControlLibrary_::moveRightStick(uint8_t rx, uint8_t ry)
{
    _joystickInputData.RX = rx;
    _joystickInputData.RY = ry;
}

SwitchControlLibrary_ &SwitchControlLibrary()
{
    static SwitchControlLibrary_ obj;
    return obj;
}

#endif
