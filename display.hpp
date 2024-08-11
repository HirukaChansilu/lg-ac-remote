#include <Arduino.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET -1       // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

Adafruit_SSD1306 displayLocal(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

class Display
{
private:
    bool isOn = false;
    int menuIndex = 0;
    int fanIndex = 0;
    const char *menuItems[5] = {"Jet", "Lights", "Fan", "Swing", "O.M.T."};

public:
    void init()
    {
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
        displayLocal.setTextColor(SSD1306_WHITE);

        Serial.println("Initialized display");
    };

    void showDebugText(const char *text)
    {
        displayLocal.clearDisplay();
        displayLocal.setTextSize(1);
        displayLocal.setCursor(0, 0);
        displayLocal.print(text);
        displayLocal.display();
    }

    void renderArrow(bool up, int x, int y, int length)
    {
        const double diff = length / sqrt(2);
        if (up)
        {
            displayLocal.drawLine(x, y, x + diff, y + diff, SSD1306_WHITE);
            displayLocal.drawLine(x, y, x - diff, y + diff, SSD1306_WHITE);
        }
        else
        {
            displayLocal.drawLine(x, y, x + diff, y - diff, SSD1306_WHITE);
            displayLocal.drawLine(x, y, x - diff, y - diff, SSD1306_WHITE);
        }
    }

    void showOffScreen()
    {
        displayLocal.clearDisplay();
        displayLocal.setTextSize(2);
        displayLocal.setCursor(22, 8);
        displayLocal.print("A/C OFF");
        displayLocal.display();
    }

    void showMenu(int temp)
    {
        displayLocal.clearDisplay();

        displayLocal.setTextSize(3);
        displayLocal.setCursor(4, 4);
        displayLocal.print(temp);
        displayLocal.setCursor(48, 4);
        displayLocal.print("C");
        displayLocal.setTextSize(1);
        displayLocal.setCursor(40, 4);
        displayLocal.print("o");

        displayLocal.drawFastVLine(70, 0, 32, SSD1306_WHITE);

        this->renderArrow(true, 99, 4, 5);
        this->renderArrow(false, 99, 28, 5);

        const int charLength = strlen(this->menuItems[this->menuIndex]);

        displayLocal.setCursor(70 + (58 - charLength * 6) / 2, 12);
        displayLocal.print(this->menuItems[this->menuIndex]);

        displayLocal.display();
    }

    void increaseMenuIndex()
    {
        this->menuIndex++;
        if (this->menuIndex > 4)
        {
            this->menuIndex = 0;
        }
    }

    int getMenuIndex()
    {
        return this->menuIndex;
    }

    int getFanIndex()
    {
        return this->fanIndex;
    }

    void increaseFanIndex()
    {
        this->fanIndex++;
        if (this->fanIndex > 4)
        {
            this->fanIndex = 0;
        }
    }
};