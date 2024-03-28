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
    // display.init();
    ac.init(3);
    buttons.init();
}

void loop()
{
    // display.showText("Hello, world!");

    if (buttons.buttonPressed(POWER_BTN))
    {
        ac.switchPower();
    }
}
