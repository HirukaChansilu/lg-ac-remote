#include <IRremote.hpp>
#include "ac_LG.hpp"

class AC_Remote
{
private:
    int emitterPin;
    Aircondition_LG AC;
    bool isOn = false;

public:
    void init(int emitterPin)
    {
        this->emitterPin = emitterPin;
        IrSender.begin(emitterPin);
        AC.setType(LG_IS_WALL_TYPE);

        Serial.println("Initialized IR emitter on pin " + String(emitterPin));
    };
    bool getPower()
    {
        return isOn;
    }
    void setPower(bool isOn)
    {
        if (isOn)
        {
            AC.sendCommandAndParameter(LG_COMMAND_ON, 0);
            Serial.println("AC is on");
        }
        else
        {
            AC.sendCommandAndParameter(LG_COMMAND_OFF, 0);
            Serial.println("AC is off");
        }
        this->isOn = isOn;
    }
    void switchPower()
    {
        setPower(!this->isOn);
    }
};