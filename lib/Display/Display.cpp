
#include <TinyWireM.h>
#include <Tiny4kOLED.h>

#include "Display.hpp"

void Display::begin()
{
    oled.begin();

    oled.setFont(FONT6X8);
    oled.clear();
    oled.on();
}

void Display::show_text(char text[])
{
    oled.setCursor(0, 0);
    oled.println(text);
}

void Display::show_text(int text)
{
    oled.setCursor(0, 0);
    oled.println(text);
}
