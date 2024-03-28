#include <Arduino.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET -1       // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

Adafruit_SSD1306 displayLocal(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

class Display
{
public:
    void init()
    {
        Serial.begin(9600);

        // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
        if (!displayLocal.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
        {
            Serial.println(F("SSD1306 allocation failed"));
            for (;;)
                ; // Don't proceed, loop forever
        }

        // Show initial display buffer contents on the screen --
        // the library initializes this with an Adafruit splash screen.
        displayLocal.display();
        delay(2000); // Pause for 2 seconds

        // Clear the buffer
        displayLocal.clearDisplay();

        // Draw a single pixel in white
        displayLocal.drawPixel(10, 10, SSD1306_WHITE);

        // Show the display buffer on the screen. You MUST call display() after
        // drawing commands to make them visible on screen!
        displayLocal.display();
        delay(2000);
    };
    void showText(char text[])
    {
        displayLocal.clearDisplay();
        displayLocal.setTextSize(1);              // Normal 1:1 pixel scale
        displayLocal.setTextColor(SSD1306_WHITE); // Draw white text
        displayLocal.setCursor(0, 0);             // Start at top-left corner
        displayLocal.cp437(true);                 // Use full 256 char 'Code Page 437' font
        displayLocal.println(text);
        displayLocal.display();
    };
};