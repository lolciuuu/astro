#ifndef MENUITEM_HPP
#define MENUITEM_HPP
#include "Headers.hpp"
#include "Sprite.hpp"

#include "StandardReferences.hpp"

/** Klasa reprezentuje pozycje w glownym menu. Name to jest jest nazwa wyswietlana
 * w glownym menu, sprite to obrazek pokazywany obok menu. Desciption to opis lub opcja wyboru
 */
class MenuItem : StandardReferences
{

public:
    MenuItem(Sprite sprite, string name, Rect where );

    void addItem(string Item) {
        pItems.push_back(Item);
    }

    int getSize() const {
        return( pItems.size() );
    }
    int getItemsNumber() const {
        return( pItems.size() );
    }
    string getItemName() const {
        return( pItemName );
    }
    string getCurrent();

    bool isActive() const {
        return( pIsActive );
    }
    bool isSelected() const {
        return( pIsSelected );
    }
    int getItemsNo() const{ 
      return( pItems.size() );
    }

    void setActive( bool Active ) {
        pIsActive = Active;
    }
    void setSelected( bool Selected ) {
        pIsSelected = Selected;
    }
    void setDescription(string desc) {
        pDesciption = desc;
    }
    void setRectName( Rect Where ) {
        pRectName = Where;
    }
    void setRectDesc( Rect Where ) {
        pRectDesc = Where;
    }
    void setRectSprite( Rect Where ) {
        pRectSprite = Where;
    }

    void next();
    void prev();

    void draw();
    void update( float dt );

private:


private:
    Rect pRectName;
    Rect pRectDesc;
    Rect pRectSprite;

    string pItemName;
    Sprite pImage;

    string pDesciption;
    vector<string> pItems;

    vStrIt current;
    bool pIsActive;
    bool pIsSelected;

    int pCurrentItem;

    SDL_Color pColorActive;
    Uint32 pColorDisable;
};

#endif // MENUITEM_HPP
