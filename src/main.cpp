#define BUTTON_IN 3

#include <Arduino.h>
#include <Display.hpp>

Display display;

void setup()
{
  pinMode(BUTTON_IN, INPUT);

  display.begin();
}

void loop()
{
  int val = analogRead(BUTTON_IN);
  display.show_text(val);
}
