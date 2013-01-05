#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Headers.hpp"
#include "Sprite.hpp"
#include "Logger.hpp"
#include "StandardReferences.hpp"

class Player: StandardReferences
{
public:
    Player();
    void draw();
    void update(const float& dt,ColisionSide& side );
    void reset();
    void run();
    void jump();
    
    void fall();

    short getPosX() const { return( pX ); }
    short getPosY() const { return( pY ); }
    
    static Uint32 enableEnemyDetect_callbackTimer(Uint32 interval, void *param);

    void SpaceUp() {   pIsFly = false; }
    void SpaceDown(){   pIsFly = true; }

    float getSize_X() const { return PLAYER_W; }
    float getSize_Y() const { return PLAYER_H; }

    void disableEnemyDetect();

	static bool isColisionWithEnemy() { return pColisionWithEnemy; }

	static bool isFly() { return pIsFly; }

private:
    Sprite pRunSprite;
    Sprite pStandSprite;
    Sprite pFlySprite;
    PlayerState pState;
    Sprite* pCurrentSprite;
  
    float pX;
    float pY;

	bool pJumpAllowed;

	float pSpeed;
	float pVY;
	float pAY;
  
	// stale wczytane z zasobow
	const float PLAYER_Y_ACCELERATION;
	const float PLAYER_Y_VELOCITY;
	float PLAYER_MAX_Y_POS;
	const float PLAYER_Y_OFFSET;
	const float MAX_Y_PLAYER;
	const float PLAYER_OFFSET_X;
  
	static bool pIsFly;

	Logger logger;

	const float PLAYER_H;
	const float PLAYER_W;

	float pMaxPlayerOnScreenX;

	float lastVY;

    SDL_TimerID timer;

    static bool pColisionWithEnemy;
    ushort const DISABLE_COLLISION_WITH_ENEMY_TIME;
};

#endif // PLAYER_HPP
