#include <Arduino.h>
#include <Display.hpp>
#include <Button.hpp>
#include <Remote.hpp>

Display display;
Button button;
Remote remote;

static int currentMode = 0;
static int lastMode = -1;
static int lastPowerMode = -1;
static int lastTemp = -1;

void setup()
{

  display.begin();
  button.begin();
  remote.init();
}

void loop()
{

  Event event = button.event();

  if (event.button >= 0)
  {
    if (event.button == 0 && event.longPress)
    {
      remote.switchPower();
    }
    else if (event.button == 0 && !event.longPress)
    {
      switch (currentMode)
      {
      case 0:
        remote.setTemp(22);
        break;

      case 1:
        remote.jetMode();
        break;

      case 2:
        remote.toggleLight();

      case 3:
        remote.toggleFanSpeed();

      case 4:
        remote.toggleSwing();

      default:
        break;
      }
    }
    else if (
        event.button == 1 && !event.longPress)
    {
      remote.increaseTemp();
    }
    else if (
        event.button == 2 && !event.longPress)
    {
      remote.decreaseTemp();
    }
    else if (event.button == 1 && event.longPress)
    {
      currentMode++;
      if (currentMode > 4)
      {
        currentMode = 0;
      }
    }
    else if (event.button == 2 && event.longPress)
    {
      currentMode--;
      if (currentMode < 0)
      {
        currentMode = 4;
      }
    }
  }

  if (currentMode != lastMode ||
      remote.AC.PowerIsOn != lastPowerMode ||
      remote.AC.Temperature != lastTemp)
  {
    display.clear();
    lastPowerMode = remote.AC.PowerIsOn;
    lastMode = currentMode;
    lastTemp = remote.AC.Temperature;
  }

  if (remote.AC.PowerIsOn)
  {
    display.ui(remote.AC.Temperature, currentMode);
  }
  else
  {
    display.show_off_screen();
  }
}
