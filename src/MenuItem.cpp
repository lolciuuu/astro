#include "../include/MenuItem.hpp"

MenuItem::MenuItem(Sprite sprite, string name, Rect Where) :
		pItemName(name), pImage(sprite), pDesciption(""), pIsActive(true),
		pIsSelected( false ), pCurrentItem(0) {
	/// @TODO przeniesc offset sprita do zasobow
	pImage.setX(Where.x);
	pImage.setY(Where.y);

	pColorActive = SDL_Color( { 0, 166, 252 });  //119, 184, 0
	pColorDisable = 0;

}

/** Metoda rysuje pojedynczy element w menu. W zaleznosci do
 *  statu w jakim sie znajduje moze miec kolor: szary - nie aktywny, pomaranczowy- aktualnie wybrany
 *  badz bialy domyslny.
 */
void MenuItem::draw() {

	//@TODO optymalizacja

		if (!pIsActive && !pIsSelected) { // Rysowanie wyszarzonego itema

			SDL_Color color( { 120, 120, 120 });
			pWriterPtr->draw(pRectName, pItemName, color);

		}
		else if (pIsSelected) { // Rysowanie aktywnego itema

			SDL_Color color( { 243, 112, 34 });
			pWriterPtr->draw(pRectName, pItemName, pColorActive);

				if (pItems.size() > 0) {
					Rect rect( { 300, 300, 100, 100 });
					pWriterPtr->draw( rect, pItems[pCurrentItem] );
				}

				else { // pokazanie opisu zaraz pod obrazkiem
					Rect rect;
					rect.x = pImage.getX();
					rect.y = pImage.getY() + (pImage.getRect()).h + 50;
					rect.w = 300;
					rect.h = 100;
					pWriterPtr->draw(rect, pDesciption, FONT_SMALLER );
				}

				pImage.draw();
		}
		else { // Rysowanie domyslnego itema
			pWriterPtr->draw(pRectName, pItemName);
		}
}

/**
 */
void MenuItem::next() {

	if (pCurrentItem < (ushort) pItems.size() - 1) {
		++pCurrentItem;
		Property::resetLang(pItems[pCurrentItem]);
	}

}

/** */
void MenuItem::prev() {

	if (pCurrentItem > 0) {
		--pCurrentItem;
		Property::resetLang(pItems[pCurrentItem]);
	}

}

/** */
void MenuItem::update(float dt) {

	pImage.update(dt);

}

