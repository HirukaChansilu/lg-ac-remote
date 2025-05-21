#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

#include "Types.hpp"

class Button
{
private:
public:
    void begin();
    uint16_t debug_value();
    Event event();
};

#endif