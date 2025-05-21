#define BUTTON_IN 3

#include <Arduino.h>
#include <Display.hpp>
#include <Remote.hpp>

Display display;
// Remote remote;

// uint16_t val;
// char button_name = 'i';
// char button_name_pre = '0';
// uint8_t currentModeIndex = 0;

// const char modes[5] = {'o', 'j', 'l', 'f', 's'};

void setup()
{
  pinMode(BUTTON_IN, INPUT);

  display.begin();
  // remote.init();
}

// void loop()
// {
//   char mode = pgm_read_byte(&modes[currentModeIndex]);

//   val = analogRead(BUTTON_IN);

//   if (val > 1000)
//   {
//     button_name = 'P';
//   }
//   else if (val > 900)
//   {
//     button_name = 'M';
//   }
//   else if (val > 800)
//   {
//     button_name = 'S';
//   }
//   else if (val > 700)
//   {
//     button_name = 'U';
//   }
//   else if (val > 500)
//   {
//     button_name = 'D';
//   }
//   else
//   {
//     button_name = 'i';
//   }

//   if (button_name != button_name_pre)
//   {

//     switch (button_name)
//     {
//     case 'P':
//       display.clear();
//       remote.switchPower();
//       break;

//     case 'M':
//       if (remote.AC.PowerIsOn)
//       {
//         display.clear_mode_space();
//         delay(100);
//         currentModeIndex = (currentModeIndex + 1) % 5;
//       }
//       break;

//     case 'S':
//       break;

//     case 'U':
//       if (remote.AC.PowerIsOn)
//       {
//         display.clear_temp_space();
//         delay(100);
//         remote.increaseTemp();
//       }

//     case 'D':
//       if (remote.AC.PowerIsOn)
//       {
//         display.clear_temp_space();
//         delay(100);
//         remote.decreaseTemp();
//       }

//     default:
//       break;
//     }

//     button_name_pre = button_name;
//   }

//   if (remote.AC.PowerIsOn)
//   {
//     display.ui(remote.AC.Temperature, mode);
//   }
//   else
//   {
//     display.show_off_screen();
//   }

//   delay(100);
// }
