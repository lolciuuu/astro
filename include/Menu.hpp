#ifndef MENU_HPP
#define MENU_HPP
#include "MenuItem.hpp"
#include "Headers.hpp"
#include "Highscore.hpp"
#include "StandardReferences.hpp"
#include "Logger.hpp"

class Menu : StandardReferences
{

public:
    Menu();
    bool update(const float& dt);

    void draw();

    bool isDone() const {
        return( pIsDone );
    }

    void pressedReturn();
    void pressedEsc();
    void pressedRight();
    void pressedLeft();
    void pressedDown();
    void pressedUp();
    void blockItem( short ID) { pMainMenuItem[ID].setActive(false); }

    void resetMenu();

private:
    void drawMainMenu();
    void drawAbout();
    

private:
    bool pIsDone;
    MenuState pMenuState;
    vector<MenuItem> pMainMenuItem;
    int pCurrentItem;
    Highscore pHighScore;
    Logger logger;

    GLuint pAboutImg;

    /** ikona w lewym dolnym rogu dla about */
    Sprite pExitIco;

    /** polozenie przycisko exit w wejsciu z menu */
     int exit_x;
     int exit_y;

};

#endif // MENU_HPP
