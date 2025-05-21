#ifndef __REMOTE_HPP__
#define __REMOTE_HPP__

#define EMITTER_PIN 2

#include <IRremote.hpp>
#include <ac_LG.hpp>

class Remote
{
public:
    Aircondition_LG AC;

    bool isSwing = true;
    uint8_t temp = 22;

    void init()
    {
        IrSender.begin(EMITTER_PIN);
        AC.setType(LG_IS_WALL_TYPE);
        AC.FanIntensity = 4;
        AC.Temperature = 22;
        AC.Mode = AC_MODE_COOLING;
        AC.PowerIsOn = false;
    };
    void switchPower()
    {
        if (!AC.PowerIsOn)
        {
            AC.sendCommandAndParameter(LG_COMMAND_ON, 0);
        }
        else
        {
            AC.sendCommandAndParameter(LG_COMMAND_OFF, 0);
        }
    }
    void increaseTemp()
    {
        if (AC.PowerIsOn)
        {
            AC.sendTemperatureFanSpeedAndMode();
            AC.sendCommandAndParameter(LG_COMMAND_TEMPERATURE_PLUS, 0);
        }
    }
    void decreaseTemp()
    {
        if (AC.PowerIsOn)
        {
            AC.sendTemperatureFanSpeedAndMode();
            AC.sendCommandAndParameter(LG_COMMAND_TEMPERATURE_MINUS, 0);
        }
    }
    void setTemp(int temp)
    {
        if (AC.PowerIsOn)
        {
            if (temp >= 18 && temp <= 30)
            {
                AC.Temperature = temp;
                AC.sendTemperatureFanSpeedAndMode();
            }
        }
    }
    void jetMode()
    {
        if (AC.PowerIsOn)
        {
            AC.sendIRCommand(LG_JET_ON);
        }
    }
    void toggleLight()
    {
        if (AC.PowerIsOn)
        {
            AC.sendIRCommand(LG_LIGHT);
        }
    }
    void setFanSpeed(int speed)
    {
        if (AC.PowerIsOn)
        {
            AC.FanIntensity = speed;
            AC.sendTemperatureFanSpeedAndMode();
        }
    }
    void toggleFanSpeed()
    {
        if (AC.PowerIsOn)
        {
            AC.FanIntensity = (AC.FanIntensity + 1) % 5;
            AC.sendTemperatureFanSpeedAndMode();
        }
    }
    void toggleSwing()
    {
        if (AC.PowerIsOn)
        {
            isSwing = !isSwing;

            AC.sendIRCommand(isSwing ? LG_WALL_SWING_ON : LG_WALL_SWING_OFF);
        }
    }
};

#endif