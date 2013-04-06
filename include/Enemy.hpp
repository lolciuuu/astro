#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Headers.hpp"
#include "SpriteManager.hpp"

class Enemy {
public:
	Enemy( ushort R, ushort C, ushort ID );

	void draw();

	void update( const float& dt );

	/** losowo wybierane jest czy ma isc w prawo czy w lewo */
	void reset() {
			pState = EnemyState::Stop;
			if( rand()%10 < 5 ) {
				pOffset = -1.0f;
			}
			else {
				pOffset = 101.0f;
			}
	} ;

	bool isColidate( Rect rct ) {
		Rect rTmp = pRect;
		rTmp.x = pRect.x + pOffset;
		return rct.isColidate(rTmp);
	}

	float getPosX() const {
		return pRect.x;
	}

	void setPosX(float posX) {
		pRect.x = posX;
	}

	float getAbsoluteX() const {
		return pRect.x + pOffset;
	}

	float getPosY() const {
		return pRect.y;
	}

	void setPosY(float posY) {
		pRect.y = posY;
	}

	ushort getColumn() const {
		return column;
	}

	ushort getId() const {
		return ID;
	}

	ushort getRow() const {
		return row;
	}

	float getOffset() const {
		return pOffset;
	}

private:
	ushort row;
	ushort column;
	ushort ID;

	Rect pRect;

	float pOffset;

	EnemyState pState;

	SpriteManager* pSprManager;

};

#endif
