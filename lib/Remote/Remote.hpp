#ifndef __REMOTE_HPP__
#define __REMOTE_HPP__

#define EMITTER_PIN 3

#include <IRremote.hpp>
#include <ac_LG.hpp>

class Remote
{
private:
    Aircondition_LG AC;
    bool isSwing = true;

public:
    void init()
    {
        IrSender.begin(EMITTER_PIN);
        AC.setType(LG_IS_WALL_TYPE);
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
            AC.sendCommandAndParameter(LG_COMMAND_TEMPERATURE_PLUS, 0);
        }
    }
    void decreaseTemp()
    {
        if (AC.PowerIsOn)
        {
            AC.sendCommandAndParameter(LG_COMMAND_TEMPERATURE_MINUS, 0);
        }
    }
    void setTemp(int temp)
    {
        if (AC.PowerIsOn)
        {
            AC.sendCommandAndParameter(LG_COMMAND_TEMPERATURE, temp);
        }
    }
    void jetMode()
    {
        if (AC.PowerIsOn)
        {
            AC.sendCommandAndParameter(LG_COMMAND_JET, 0);
        }
    }
    void toggleLight()
    {
        if (AC.PowerIsOn)
        {
            AC.sendCommandAndParameter(LG_COMMAND_LIGHT, 0);
        }
    }
    void setFanSpeed(int speed)
    {
        if (AC.PowerIsOn)
        {
            AC.sendCommandAndParameter(LG_COMMAND_FAN_SPEED, speed);
        }
    }
    void toggleFanSpeed()
    {
        if (AC.PowerIsOn)
        {
            AC.sendCommandAndParameter(LG_COMMAND_FAN_SPEED, (AC.FanIntensity + 1) % SIZE_OF_FAN_SPEED_MAPPING_TABLE);
        }
    }
    void toggleSwing()
    {
        if (AC.PowerIsOn)
        {
            isSwing = !isSwing;

            AC.sendCommandAndParameter(LG_COMMAND_SWING, isSwing ? 1 : 0);
        }
    }
    bool getPowerMode()
    {
        return AC.PowerIsOn;
    }
    int getTemp()
    {
        return AC.Temperature;
    }
};

#endif