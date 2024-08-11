#define POWER_BTN 4
#define MENU_BTN 5
#define UP_BTN 6
#define DOWN_BTN 7
#define SELECT_BTN 8

class Buttons
{
private:
    bool powerBtnState = false;
    bool menuBtnState = false;
    bool upBtnState = false;
    bool downBtnState = false;
    bool selectBtnState = false;

public:
    void init()
    {
        pinMode(POWER_BTN, INPUT);
        pinMode(MENU_BTN, INPUT);
        pinMode(UP_BTN, INPUT);
        pinMode(DOWN_BTN, INPUT);
        pinMode(SELECT_BTN, INPUT);
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

        case MENU_BTN:
            btnState = &this->menuBtnState;
            break;

        case UP_BTN:
            btnState = &this->upBtnState;
            break;

        case DOWN_BTN:
            btnState = &this->downBtnState;
            break;

        case SELECT_BTN:
            btnState = &this->selectBtnState;
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