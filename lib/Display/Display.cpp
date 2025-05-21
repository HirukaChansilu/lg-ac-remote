#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSans12pt7b.h>

#include "Display.hpp"
#include "Icons.hpp"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET -1       // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void Display::begin()
{
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if (!oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
    {
        for (;;)
            ; // Don't proceed, loop forever
    }

    // Show initial display buffer contents on the screen --
    // the library initializes this with an Adafruit splash screen.
    oled.display();
    delay(2000); // Pause for 2 seconds

    // Clear the buffer
    oled.clearDisplay();
    oled.setTextColor(SSD1306_WHITE);
}

void Display::show_text(char text[])
{
    oled.clearDisplay();
    oled.setCursor(0, 0);
    oled.println(text);
    oled.display();
}

void Display::show_text(int text)
{
    oled.clearDisplay();
    oled.setCursor(0, 0);
    oled.println(text);
    oled.display();
}

void Display::show_text(char text)
{
    oled.clearDisplay();
    oled.setCursor(0, 0);
    oled.println(text);
    oled.display();
}

void Display::show_text(uint16_t text)
{
    oled.clearDisplay();
    oled.setCursor(0, 0);
    oled.println(text);
    oled.display();
}

void Display::show_text(uint8_t text)
{
    oled.clearDisplay();
    oled.setCursor(0, 0);
    oled.println(text);
    oled.display();
}

void Display::clear()
{
    oled.clearDisplay();
    oled.display();
}

void Display::show_off_screen()
{
    oled.setFont(&FreeSans12pt7b);
    oled.setCursor(18, 22);
    oled.print("A/C OFF");
    oled.display();
}

void Display::ui(uint8_t temp, char mode)
{
    oled.setTextSize(1);

    oled.setFont(&FreeSans12pt7b);
    oled.setCursor(2, 22);
    oled.print(temp);
    oled.setCursor(32, 22);
    oled.print("C");

    oled.setFont();
    oled.setCursor(28, 2);
    oled.print("0");

    oled.setCursor(60, 12);
    oled.print("<");
    oled.setCursor(120, 12);
    oled.print(">");

    oled.drawLine(55, 0, 55, 32, SSD1306_WHITE);

    switch (mode)
    {
    case 0: // OMT
        oled.setFont(&FreeSans9pt7b);
        oled.setCursor(70, 24);
        oled.print("O");
        oled.setCursor(106, 24);
        oled.print("T");
        oled.drawBitmap(86, 0, omt_bitmap, 20, 32, SSD1306_WHITE);
        break;

    case 1: // Jet
        oled.setFont();
        oled.setCursor(85, 8);
        oled.print("Jet");
        oled.setCursor(82, 16);
        oled.print("Mode");
        break;

    case 2: // Lights
        oled.setFont();
        oled.setCursor(76, 8);
        oled.print("Toggle");
        oled.setCursor(76, 16);
        oled.print("Lights");
        break;

    case 3: // Fan
        oled.setFont();
        oled.setCursor(85, 8);
        oled.print("Fan");
        oled.setCursor(79, 16);
        oled.print("Speed");
        break;

    case 4: // Swing
        oled.setFont();
        oled.setCursor(76, 8);
        oled.print("Toggle");
        oled.setCursor(79, 16);
        oled.print("Swing");
        break;

    default:
        break;
    }

    oled.display();
}
