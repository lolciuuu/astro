#include "Map.hpp"
#include "App.hpp"

/** */
Map::Map(short **M, ushort EntitySize, uint R, uint C) :
		pMap(M), pos_X(0), pos_Y(0), pOffset_X(5), pOffset_Y(0), pSize(
				EntitySize), rows(R), columns(C), pSpeed(0.0F), pCheckColision(
				false), pNextMeter(0), pR(R), pC(C), pPlayer_x(0), pPlayer_y(0), pPlayer_sx(
				0), pPlayer_sy(0), logger("Map") {

	// Obliczanie ile fragmentow mapy miesci sie na ekranie
	pAmountEntityHorizontal = (App::getScreenWidth() / EntitySize) + 1;
	pAmountEntityVertical = (App::getScreenHeight() / EntitySize) + 1;

	while (pAmountEntityVertical > R) {
		--pAmountEntityVertical;
	}

	logger.info("Entity size:" + toString(EntitySize));
	logger.info("Vertical amount of ground:" + toString(pAmountEntityVertical));
	logger.info(
			"Horizontal amount of ground:" + toString(pAmountEntityHorizontal));

	itWasReturn = vector<vector<bool> >(C, vector<bool>(R, false));
	drawID = new vector<vector<bool> >(pC, vector<bool>(pR, true));

	pPlayer_sx = Property::getSetting("PLAYER_W");
	pPlayer_sy = Property::getSetting("PLAYER_H");

}

/** Sciaga ze stosu ostatni element na ktorym wykryto kolizje */
short Map::checkColision(const short& Player_x, const short& Player_y,ColisionSide& cSide) {

	pPlayer_x = Player_x;
	pPlayer_y = Player_y;

	/** Pobieranie kolizcji z bonusem badz przeszkoda ( kolizje bez powtorzen )
	 * odlozonej na stos podczas rysowania	 */
	short result = -1;

	if (pColisionStack.size() > 0) {
		Point point = pColisionStack.top();
		pColisionStack.pop();

		short X = point.X;
		short Y = point.Y;

		if (!itWasReturn[X][Y]) {
			itWasReturn[X][Y] = true;
			result = pMap[X][Y];

			if ( isBonus( result ) || isAdditionalBonus( result ) ) {
				drawID->at(X)[Y] = false;
			}
		}
	}

	{ /** wykrywanie kolizji z platforma */
		short X = Player_x + 5;
		short Y = Player_y;
		short current_px = -1 * pOffset_X;
		short next_px = current_px + pSize;

		ushort index_x = pos_X;

		// szukanie kolumny w ktorej jest kolizja
		while (!(current_px <= X && next_px > X)) {
			++index_x;
			current_px = next_px;
			next_px += pSize;
		}

		ushort current_py = App::getScreenHeight();
		ushort next_py = current_py - pSize;

		int index_y = pAmountEntityVertical - 1;

		// szukanie wiersza w ktorym jest kolizja od gory
		while (!(current_py >= Y && next_py < Y)) {
			--index_y;
			current_py = next_py;
			next_py -= pSize;
		}

		if (isPlatform(pMap[index_x][index_y]) || isPlatform(pMap[index_x + 1][index_y])) {
			cSide.up = true;
			cSide.pos_Y_px = current_py;
		}

		current_py = App::getScreenHeight();
		next_py = current_py - pSize;

		index_y = pAmountEntityVertical - 1;
		Y = Player_y + pPlayer_sy;

		// szukanie wiersza w ktorym jest kolizja od dolu
		while (!(current_py >= Y && next_py < Y)) {
			--index_y;
			current_py = next_py;
			next_py -= pSize;
		}

		if (isPlatform(pMap[index_x][index_y]) || isPlatform(pMap[index_x + 1][index_y])) {
			cSide.down = true;
			cSide.pos_Y_px = (current_py - 3 * pSize) + 1;
		}

		current_py = App::getScreenHeight();
		next_py = current_py - pSize;

		index_y = pAmountEntityVertical - 1;
		Y = Player_y;

		// szukanie wiersza w ktorym kolizja jest od boku
		while (!( current_py < Y + pPlayer_sy && current_py > Y && next_py < Y + pPlayer_sy && next_py > Y ) ) {
			--index_y;
			current_py = next_py;
			next_py -= pSize;
			if( index_y < 0 ) break;
		}

		if( index_y > 0 && ( isPlatform(pMap[index_x][index_y]) || isPlatform(pMap[index_x + 1][index_y]) )) {

			float halfTiles = current_py - 0.5 * pSize;
			float halfPlayer = pPlayer_y + 0.5 * pPlayer_sy;

			if( halfTiles < halfPlayer ) {
				cSide.up = true;
				cSide.pos_Y_px = current_py;
			}
			else {
				cSide.down = true;
				cSide.pos_Y_px = (current_py - 3 * pSize) + 1;
			}
		}

	} //END ADD

	return (result);
}

/** */
void Map::draw() {

	register uint currentX = pos_X;
	register uint currentY = pos_Y;

	for (uint x = 0; x <= pAmountEntityHorizontal + 1U; ++x, ++currentX) {

		for (uint y = 1; y < pAmountEntityVertical; ++y, --currentY) {

			short ID = pMap[x + pos_X][rows - y];

			if (ID == -1 || (drawID->at(x + pos_X))[rows - y] != true)
				continue;   // -1 oznacza brak kafla na mapie

			float des_x = (float) (x * pSize) - float(pOffset_X);

			//@TODO czemu tujest ta 10?
			float des_y = ( 10+ App::getScreenHeight() - (y * pSize) );

			Rect src(MapManager::getRectByID(ID));
			src.h = pSize;
			src.w = pSize;

			pRendererPtr->draw(src, des_x, des_y, pSize, pSize);

			/// wykrywania kolizji
			if (pCheckColision) {

				if (!(pPlayer_x >= (des_x + pSize)
						|| pPlayer_x + pPlayer_sx <= des_x
						|| pPlayer_y + pPlayer_sy <= des_y
						|| pPlayer_y >= des_y + pSize)) {
					short xTmp = x + pos_X;
					short yTmp = rows - y;

					// Zapisanie na stosie ID elementu z ktorym wykryto kolizje
					pColisionStack.push(Point(xTmp, yTmp, des_x, des_y));
				}
			} // END wykrywania kolizji

		}
	}
}

/** Obliczenie przesuniecie, i ewentulnie przesuniecie pierwszej kolumny macierzy */
void Map::update(const float& dt) {

	pOffset_X += (float) pSpeed * dt;

	if (pOffset_X > pSize) {
		pOffset_X -= pSize;
		++pos_X;
		++pNextMeter;
	}

}

bool Map::isAnyPlatformAbove(float X, float Y) {

	short current_px = -1 * pOffset_X;
	short next_px = current_px + pSize;

	int index_x = pos_X;

	while (!(current_px <= X && next_px > X)) {
		++index_x;
		current_px = next_px;
		next_px += pSize;
	}

	short current_py = App::getScreenHeight();
	short next_py = current_py - pSize;

	int index_y = pAmountEntityVertical - 1;

	while (!(current_py >= Y && next_py < Y)) {
		--index_y;
		current_py = next_py;
		next_py -= pSize;
	}

	if (isPlatform(pMap[index_x][index_y])
			|| isPlatform(pMap[index_x + 1][index_y]))
		return true;

	return false;
}

bool Map::isAnyPlatformBelow(float X, float Y) {

	Y += pPlayer_sy;

	short current_px = -1 * pOffset_X;
	short next_px = current_px + pSize;

	int index_x = pos_X;

	while (!(current_px <= X && next_px > X)) {
		++index_x;
		current_px = next_px;
		next_px += pSize;
	}

	short current_py = App::getScreenHeight();
	short next_py = current_py - pSize;

	int index_y = pAmountEntityVertical - 1;

	while (!(current_py >= Y && next_py < Y)) {
		--index_y;
		current_py = next_py;
		next_py -= pSize;
	}

	if (isPlatform(pMap[index_x][index_y])
			|| isPlatform(pMap[index_x + 1][index_y]))
		return true;

	return false;
}

/** Ustawienie bierzacej kolumny i wiersza na poczatek macierzy mapy */
void Map::reset() {
	pos_X = 0;
	pos_Y = 0;
	logger.info("Reseting main map");

	delete drawID;
	drawID = new vector<vector<bool> >(pC, vector<bool>(pR, true));
	itWasReturn = vector<vector<bool> >(pC, vector<bool>(pR, false));
	SDL_Delay(0);
}

