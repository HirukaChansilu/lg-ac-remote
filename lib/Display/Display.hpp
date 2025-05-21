#ifndef __DISPLAY_HPP__
#define __DISPLAY_HPP__

class Display
{
private:
public:
    void begin();
    void show_text(char text[]);
    void show_text(int text);
    void show_text(char text);
    void show_text(uint16_t text);
    void show_text(uint8_t text);
    void clear();
    void show_off_screen();
    void ui(uint8_t temp, char mode);
};

#endif