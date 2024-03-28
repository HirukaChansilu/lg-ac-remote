#include <IRremote.hpp>
#include "ac_LG.hpp"

#define EMITTER_PIN 3

class AC_Remote
{
private:
    Aircondition_LG AC;
    bool isOn = false;
    bool isSwing = true;

public:
    void init()
    {
        IrSender.begin(EMITTER_PIN);
        AC.setType(LG_IS_WALL_TYPE);
        AC.FanIntensity = 2;
        AC.Temperature = 22;

        Serial.println("Initialized IR emitter on pin " + String(EMITTER_PIN));
    };
    int getTemp()
    {
        return AC.Temperature;
    }
    bool getPower()
    {
        return isOn;
    }
    void setPower(bool isOn)
    {
        if (isOn)
        {
            Serial.println("Fan speed: " + String(AC.FanIntensity) + ", Temperature: " + String(AC.Temperature) + ", Mode: " + String(AC.Mode));

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
    void increaseTemp()
    {
        AC.sendCommandAndParameter(LG_COMMAND_TEMPERATURE_PLUS, 0);
        Serial.println("Increased temperature");
    }
    void decreaseTemp()
    {
        AC.sendCommandAndParameter(LG_COMMAND_TEMPERATURE_MINUS, 0);
        Serial.println("Decreased temperature");
    }
    void setTemp(int temp)
    {
        AC.sendCommandAndParameter(LG_COMMAND_TEMPERATURE, temp);
        Serial.println("Set temperature to " + String(temp));
    }

    void jetMode()
    {
        AC.sendCommandAndParameter(LG_COMMAND_JET, 0);
        Serial.println("Jet mode");
    }

    void toggleLight()
    {
        AC.sendCommandAndParameter(LG_COMMAND_LIGHT, 0);
        Serial.println("Toggled light");
    }

    void setFanSpeed(int speed)
    {
        AC.FanIntensity = speed;
        AC.sendTemperatureFanSpeedAndMode();
        Serial.println("Set fan speed to " + String(speed));
    }

    void toggleSwing()
    {
        this->isSwing = !this->isSwing;

        AC.sendCommandAndParameter(LG_COMMAND_SWING, this->isSwing ? 1 : 0);
        Serial.println("Toggled swing");
    }
};