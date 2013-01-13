#include "../include/MenuItem.hpp"

MenuItem::MenuItem(Sprite sprite, string name, Rect Where) :
		pItemName(name), pImage(sprite), pDesciption(""), pIsActive(true),
		pIsSelected( false ), pCurrentItem(0) {

	/// @TODO przeniesc offset sprita do zasobow
	pImage.setX(Where.x);
	pImage.setY(Where.y);

	pColorActive = SDL_Color( { 255, 142, 0 });  //119, 184, 0
	pColorDisable = SDL_Color( { 29, 57, 100 }); ;

}

/** Metoda rysuje pojedynczy element w menu. W zaleznosci do
 *  statu w jakim sie znajduje moze miec kolor: szary - nie aktywny, pomaranczowy- aktualnie wybrany
 *  badz bialy domyslny.
 */
void MenuItem::draw() {

	//@TODO optymalizacja

		if (!pIsActive && !pIsSelected) { // Rysowanie wyszarzonego itema
			pWriterPtr->draw(pRectName, pItemName, pColorDisable, FontSize::NORMALL );
		}
		else if (pIsSelected) { // Rysowanie aktywnego itema

			pWriterPtr->draw(pRectName, pItemName, pColorActive, FontSize::NORMALL );

				if (pItems.size() > 0) { // specjalny rodzaj itemsa w mnue- aktualnie nie wykorzystywane
					Rect rect( { 300, 300, 100, 100 });
					pWriterPtr->draw( rect, pItems[pCurrentItem] );
				}
				else { // pokazanie opisu zaraz pod obrazkiem
					pWriterPtr->draw(pRectDesc, pDesciption );
				}

				// Wyswietlanie sprajta dla kazdego itemsa w menu
				//pImage.draw();
		}
		else { // Rysowanie domyslnego itema
			pWriterPtr->draw(pRectName, pItemName, FontSize::NORMALL );
		}
}

/** przejscie do poprzedniej pozycji w menu */
void MenuItem::next() {

	if (pCurrentItem < (ushort) pItems.size() - 1) {
		++pCurrentItem;
		Property::resetLang(pItems[pCurrentItem]);
	}
}

/** Przejscie do nastepnej pozycji w menu */
void MenuItem::prev() {

	if (pCurrentItem > 0) {
		--pCurrentItem;
		Property::resetLang(pItems[pCurrentItem]);
	}
}

/** Aktualizacja sprajta ktory sie wyswietla w menu */
void MenuItem::update(float dt) {
	pImage.update(dt);
}

