#include <Arduino.h>

#include "Button.hpp"

#define BUTTON_IN A0

int errorRange = 50; // +/- (error/1024) of the value

int getButtonValue(int analogValue);

void Button::begin()
{
    pinMode(BUTTON_IN, INPUT);
}

uint16_t Button::debug_value()
{
    return analogRead(BUTTON_IN);
}

const int LONG_PRESS_THRESHOLD = 800;

// Variables to track button state
int previousButtonValue = -1;
unsigned long pressStartTime = 0;
bool isPressing = false;

Event Button::event()
{
    int analogValue = analogRead(BUTTON_IN);
    int currentButtonValue = getButtonValue(analogValue);

    Event event = {.longPress = false, .button = -2};

    if (currentButtonValue != previousButtonValue)
    {
        // Button value changed
        if (currentButtonValue != -1)
        {
            // Button pressed
            pressStartTime = millis();
            isPressing = true;
        }
        else if (isPressing)
        {
            // Button released
            unsigned long pressDuration = millis() - pressStartTime;
            event.longPress = (pressDuration >= LONG_PRESS_THRESHOLD);
            event.button = previousButtonValue;
            isPressing = false;
        }
        previousButtonValue = currentButtonValue;
    }

    return event;
}

int getButtonValue(int analogValue)

{
    int button0Min = 800, button0Max = 1024; // Power / Select Button
    int button1Min = 500, button1Max = 749;  // Up
    int button2Min = 150, button2Max = 449;  // Down

    // Determine which button is pressed based on the analog value
    if (analogValue >= button0Min - errorRange && analogValue <= button0Max + errorRange)
        return 0;
    else if (analogValue >= button1Min - errorRange && analogValue <= button1Max + errorRange)
        return 1;
    else if (analogValue >= button2Min - errorRange && analogValue <= button2Max + errorRange)
        return 2;
    else
    {
        return -1; // No button pressed
    }
}
