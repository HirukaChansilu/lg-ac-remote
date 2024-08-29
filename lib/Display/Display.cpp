
#include <TinyWireM.h>
#include <Tiny4kOLED.h>

#include "Display.hpp"
#include "Icons.hpp"

void Display::begin()
{
    oled.begin();

    oled.setFont(FONT6X8P);
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

void Display::show_text(char text)
{
    oled.setCursor(0, 0);
    oled.println(text);
}

void Display::show_text(uint16_t text)
{
    oled.setCursor(0, 0);
    oled.println(text);
}

void Display::show_text(uint8_t text)
{
    oled.setCursor(0, 0);
    oled.println(text);
}

void Display::clear()
{
    oled.clear();
}

void Display::show_off_screen()
{
    oled.setFontX2Smooth(FONT6X8P);
    oled.setCursor(36, 1);
    oled.print("A/C OFF");
}

void Display::ui(uint8_t temp, char mode)
{
    oled.setFontX2Smooth(FONT6X8P);
    oled.setCursor(10, 1);
    oled.print(temp);
    oled.setCursor(40, 1);
    oled.print("C");
    oled.setFont(FONT6X8P);
    oled.setCursor(34, 1);
    oled.print("0");

    oled.setFontX2Smooth(FONT6X8P);
    oled.setCursor(60, 1);
    oled.print("<");
    oled.setCursor(120, 1);
    oled.print(">");

    oled.setCursor(56, 0);
    oled.fillLength(0b11111111, 1);
    oled.setCursor(56, 1);
    oled.fillLength(0b11111111, 1);
    oled.setCursor(56, 2);
    oled.fillLength(0b11111111, 1);
    oled.setCursor(56, 3);
    oled.fillLength(0b11111111, 1);

    switch (mode)
    {
    case 'o':
        oled.setFontX2Smooth(FONT6X8P);
        oled.setCursor(74, 1);
        oled.print("O");
        oled.setCursor(106, 1);
        oled.print("T");
        oled.bitmap(86, 0, 86 + 20, 4, epd_bitmap_OMT);
        break;

    case 'j':
        oled.setFont(FONT6X8P);
        oled.setCursor(85, 1);
        oled.print("Jet");
        oled.setCursor(82, 2);
        oled.print("Mode");
        break;

    case 'l':
        oled.setFont(FONT6X8P);
        oled.setCursor(76, 1);
        oled.print("Toggle");
        oled.setCursor(76, 2);
        oled.print("Lights");
        break;

    case 'f':
        oled.setFont(FONT6X8P);
        oled.setCursor(85, 1);
        oled.print("Fan");
        oled.setCursor(79, 2);
        oled.print("Speed");
        break;

    case 's':
        oled.setFont(FONT6X8P);
        oled.setCursor(76, 1);
        oled.print("Toggle");
        oled.setCursor(79, 2);
        oled.print("Swing");
        break;

    default:
        break;
    }
}

void Display::clear_mode_space()
{
    oled.setCursor(72, 0);
    oled.fillLength(0b00000000, 44);
    oled.setCursor(72, 1);
    oled.fillLength(0b00000000, 44);
    oled.setCursor(72, 2);
    oled.fillLength(0b00000000, 44);
    oled.setCursor(72, 3);
    oled.fillLength(0b00000000, 44);
}

void Display::clear_temp_space()
{
    oled.setCursor(0, 1);
    oled.fillLength(0b00000000, 54);
    oled.setCursor(0, 2);
    oled.fillLength(0b00000000, 54);
}