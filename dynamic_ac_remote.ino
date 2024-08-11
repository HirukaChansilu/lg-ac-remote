#include <Arduino.h>
#include "display.hpp"
#include "ac_remote.hpp"
#include "buttons.hpp"

Display display;
AC_Remote ac;
Buttons buttons;

void setup()
{
    Serial.begin(115200);
    display.init();
    buttons.init();
    ac.init();
}

void loop()
{
    if (ac.getPower())
    {
        display.showMenu(ac.getTemp());
    }
    else
    {
        display.showOffScreen();
    }

    if (buttons.buttonPressed(POWER_BTN))
    {
        ac.switchPower();
    }
    if (buttons.buttonPressed(MENU_BTN))
    {
        display.increaseMenuIndex();
    }
    if (buttons.buttonPressed(UP_BTN))
    {
        ac.increaseTemp();
    }
    if (buttons.buttonPressed(DOWN_BTN))
    {
        ac.decreaseTemp();
    }
    if (buttons.buttonPressed(SELECT_BTN))
    {
        switch (display.getMenuIndex())
        {
        case 0:
            ac.jetMode();
            break;

        case 1:
            ac.toggleLight();
            break;

        case 2:
            display.increaseFanIndex();
            ac.setFanSpeed(display.getFanIndex());
            break;

        case 3:
            ac.toggleSwing();
            break;

        case 4:
            ac.setTemp(20);
            break;

        default:
            break;
        }
    }
}
