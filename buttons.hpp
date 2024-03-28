#define POWER_BTN 4

class Buttons
{
private:
    bool powerBtnState = false;

public:
    void init()
    {
        pinMode(POWER_BTN, INPUT);
    }
    bool buttonPressed(int buttonPin)
    {
        const bool btnRead = digitalRead(buttonPin);
        bool *btnState;

        switch (buttonPin)
        {
        case POWER_BTN:
            btnState = &this->powerBtnState;
            break;

        default:
            break;
        }

        if (btnRead != *btnState)
        {
            *btnState = btnRead;
            return btnRead == 1;
        }
        else
        {
            return false;
        }
    }
};