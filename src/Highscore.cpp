#include "../include/Highscore.hpp"
#include "App.hpp"
#include <algorithm>

vector<HighscoreItem> Highscore::pList;

/** */
Highscore::Highscore() :
		ITEM_AMOUNT(10), pBackground(0), pInfoIco(
				SpriteManager::getInstance()->getSprite("INFO")),
				pExitIco(SpriteManager::getInstance()->getSprite("CLOSE")),
				pWarringIco( SpriteManager::getInstance()->getSprite("WARNING") ),
				pStarIco( SpriteManager::getInstance()->getSprite("STAR_MULTI") ),
				pShowCursor( true ), pShowCursorShowTime( 0.0f ), pMaxShowCursorShowTime( .2 )
{
	logger.setClassName("Highscore");
	load();

	pInfoText = Property::get("HIGHSCORE_INFO_TEXT");
	pRankText = Property::get("HIGHSCORE_RANK_TEXT");
	pNameText = Property::get("HIGHSCORE_NAME_TEXT");
	pScoreText = Property::get("HIGHSCORE_SCORE_TEXT");
	pGameOverText = Property::get("HIGHSCORE_OVER");
	pEnterNameText = Property::get("HIGHSCORE_ENTER_NAME");
	pNewHighscoreText = Property::get("HIGHSCORE_NEW");

}

/** usuwanie znakow z imienia gracza */
void Highscore::pressedBackspace() {
	if (pCurrentName.size() > 0)
		pCurrentName = pCurrentName.substr(0, pCurrentName.size() - 1);
}

/** Wpisywanie imienia gracza */
void Highscore::pressedChar(char Char) {
	if (pCurrentName.size() < 20)
		pCurrentName += Char;
}

/** mozliwosc wpisania imienia gracza */
void Highscore::draw() {

	// jezeli nie pobito rekordu to rysujemy tylko liste z najlepszymi wynikami
	if( LiveBar::getResultNum() < pList[pList.size()-1].points && pList.size() >= ITEM_AMOUNT) {
		show();
		Rect where( pWriterPtr->getCenterX(pGameOverText), pScreenHeight*0.81f, 300, 300);
		pWriterPtr->draw( where, pGameOverText, WHITE_FONT_COLOR, FontSize::NORMALL );
		pWarringIco.draw( where.x - 125 , where.y ,80 ,80 );
		return;
	}

	Rect tmp(0, 0, pScreenWidth, pScreenHeight);
	pRendererPtr->draw(pBackground, tmp);

	Rect where( pWriterPtr->getCenterX(pGameOverText), pScreenWidth*0.15f, 300, 300);
	pWriterPtr->draw( where, pGameOverText, WHITE_FONT_COLOR, FontSize::BIG );
	pWarringIco.draw( where.x - 125 , where.y ,110 ,110 );

	where.y += 50;
	pWriterPtr->draw(where, "Result: " + LiveBar::getResult() + "m", WHITE_FONT_COLOR , FontSize::NORMALL);

	where.y += pScreenWidth*0.10f;
	pWriterPtr->draw(where, pNewHighscoreText, YELLOW_FONT_COLOR , FontSize::BIG) ;

	pStarIco.draw( where.x + 150 + (pWriterPtr->getTextWidth(pNewHighscoreText) ) , where.y-30 ,100 ,100  );

	where.x = pWriterPtr->getCenterX(pEnterNameText);
	where.y += 60;
	pWriterPtr->draw(where,pEnterNameText , WHITE_FONT_COLOR, FontSize::NORMALL );

	where.y += 60;
	where.x = pWriterPtr->getCenterX( pCurrentName );
	if (pCurrentName.size() > 0) {
		pWriterPtr->draw(where, pCurrentName, WHITE_FONT_COLOR,  FontSize::SMALL );
	}

	if( pShowCursor ) {
		where.x += pWriterPtr->getTextWidth( pCurrentName )+3;
		pWriterPtr->draw(where, "_", WHITE_FONT_COLOR,  FontSize::NORMALL );
	}

	// rysowanie przycisku exit
	pExitIco.draw(exit_x, exit_y, 50, 50);
	where.x = exit_x + 60;
	where.y = exit_y + 10;
	pWriterPtr->draw(where, "Esc");

}

//@TODO optymalizacja
/** Highscore widziane z menu */
void Highscore::show() {

	Rect tmp(0, 0, pScreenWidth, pScreenHeight);
	pRendererPtr->draw(pBackground, tmp);

	// naglowek
	tmpXText = pWriterPtr->getCenterX(pInfoText);
	pWriterPtr->draw(Rect(tmpXText, tmpY), pInfoText, FontSize::NORMALL);
	pInfoIco.draw(tmpXText - 60, tmpY, 50, 50);

	// naglowek tabelki
	pWriterPtr->draw(Rect(rank_x, tmpY + 80), pRankText, BLACK_FONT_COLOR);
	pWriterPtr->draw(Rect(name_x, tmpY + 80), pNameText, BLACK_FONT_COLOR);
	pWriterPtr->draw(Rect(score_x, tmpY + 80), pScoreText, BLACK_FONT_COLOR);

	SDL_Color color( { 240, 240, 250 });

	Rect where( { 0, (float) tmpY + 80, 200, 200 });

	// rysowanie tebelki w wynikami
	for (uint i = 0; i < ITEM_AMOUNT; ++i) {
		if( i >= pList.size() ) break;

		if (pList[i].name.size() < 1)
			continue;
		where.y += 35;
		where.x = rank_x + 5;

		pWriterPtr->draw(where, toString(i + 1), color);
		where.x = name_x;
		pWriterPtr->draw(where, pList[i].name, color);

		where.x = score_x;
		pWriterPtr->draw(where, toString(pList[i].points) + " m", color);
	}

	// rysowanie przycisku exit
	pExitIco.draw(exit_x, exit_y, 50, 50);
	where.x = exit_x + 60;
	where.y = exit_y + 10;
	pWriterPtr->draw(where, "Esc");

}

/** */
void Highscore::colision(short type) {
	debug("Highscore colision");
	LiveBar::increaseLive();
}

/** Wczxytywanie zapisanych wynikow z pliku */
void Highscore::load() {

	logger.info("Load highscore file");

	pList.clear();

	tmpY = pScreenHeight * 0.21;
	rank_x = pScreenWidth * 0.3;
	name_x = pScreenWidth * 0.40;
	score_x = pScreenWidth * 0.65;
	exit_x = pScreenWidth - pScreenWidth * 0.2f;
	exit_y = pScreenHeight - pScreenHeight * 0.2f;

	fstream highFile;
	highFile.open("data/astro.data", std::ios::in);

	if (highFile.is_open()) {

		int index = 0;
		while (!highFile.eof()) {

			if ( index > ITEM_AMOUNT)
				break;

			HighscoreItem item;
			highFile >> item.name;
			highFile >> item.points;

			if (item.name == "" || item.points == 0)
				continue;

			pList.push_back(item);
			++index;
		}

		highFile.close();
	}

	if( pList.size() == 0 ) {
		HighscoreItem item;
		item.name="Bob";
		item.points=100;
		pList.push_back( item );
	}

	pBackground = RendererGL::getSurfaceInGLFormat( Resource::getSurf("MENU_BACKGROUND_EMPTY") );
}

/** */
void Highscore::save() {

	logger.info("Saving highscore");

	if (pCurrentName.size() > 0) {
		HighscoreItem item;
		item.name = pCurrentName;
		item.points = atoi(LiveBar::getResult().c_str());
		pList.push_back(item);
	}

	//sortowanie wynikow
	sort(pList.begin(), pList.end(), this->compareItem);

	fstream highFile;
	highFile.open("data/astro.data", std::ios::out);

	if (highFile.is_open()) {

		for (uint i = 0; i < pList.size(); ++i) {

			if (i >= ITEM_AMOUNT)
				break;

			highFile << pList[i].name << " ";
			highFile << pList[i].points;

			if (i != pList.size() - 1)
				highFile << "\n";
		}

		highFile.close();
	}
	else logger.critical("Cannot save highscore");

	pCurrentName = "";

	logger.info("Saved highscore to file");
}

/** */
void Highscore::update(const float& dt) {

	pShowCursorShowTime += dt;

	if( pShowCursorShowTime > pMaxShowCursorShowTime ) {

		if( pShowCursor ) {
			pShowCursor = false;
			pShowCursorShowTime = 0.0f;
		}
		else {
			pShowCursor = true;
			pShowCursorShowTime = 0.0f;
		}
	}

}

/** Wynkcja porownojaca dwa wpisyw w highscore, pomocna do sortowania wynikow */
bool Highscore::compareItem(HighscoreItem A, HighscoreItem B) {
	if (A.points > B.points)
		return true;
	return false;
}
