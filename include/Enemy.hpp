#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Headers.hpp"
#include "SpriteManager.hpp"

class Enemy {
public:
	Enemy( ushort R, ushort C, ushort ID );

	void draw();

	void update( const float& dt );

	bool isColidate( Rect rct ) { return pRect.isColidate(rct); }

	float getPosX() const {
		return pRect.x;
	}

	void setPosX(float posX) {
		pRect.x = posX;
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
