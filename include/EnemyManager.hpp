#ifndef ENEMYMANAGER_HPP
#define ENEMYMANAGER_HPP

#include "Headers.hpp"
#include "Enemy.hpp"
#include "Logger.hpp"

/** */
class EnemyManager {
public:
	  static EnemyManager* getInstance();

	  void addEnemy( ushort R, ushort C, ushort ID );

	  void update( const float& dt );

	  void draw();

	  void reset();

	  bool isColidate( Rect rect );

	 ulong getCurrentX() const {
		return pCurrentX;
	 }

	 void setCurrentX(ulong currentX) {
		this->pCurrentX = currentX;
	 }

	 float getOffsetX() const {
		return pOffsetX;
	 }

	 void setOffsetX(float offsetX) {
		pOffsetX = offsetX;
	 }

	float getTilesSize() const {
		return pTilesSize;
	}

	void setTilesSize(float tilesSize) {
		pTilesSize = tilesSize;
	}

	ushort getHorizontalTilesAmount() const {
		return pHorizontalTilesAmount;
	}

	void setHorizontalTilesAmount(ushort horizontalTilesAmount) {
		pHorizontalTilesAmount = horizontalTilesAmount;
	}

private:
	 EnemyManager();

	 static EnemyManager* pInstance;

	 vector<Enemy> pEnemyList;
	 ushort pLastEnemy;
	 uint pCurrentX;	 // aktualna kolumna od kroej zaczyna sie rysowanie mapy na ekranie
	 float pOffsetX;

	 float pTilesSize;
	 ushort pHorizontalTilesAmount;
	 Logger logger;

};

#endif
