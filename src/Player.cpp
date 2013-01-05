#include "Player.hpp"
#include "SpriteManager.hpp"
#include "Property.hpp"
#include "App.hpp"

bool Player::pColisionWithEnemy( true );
bool Player::pIsFly( false );

/** */
Player::Player():
  pRunSprite( SpriteManager::getInstance()->getSprite("PLAYER_RUN") ),
  pStandSprite( SpriteManager::getInstance()->getSprite("PLAYER_STAND") ),
  pFlySprite( SpriteManager::getInstance()->getSprite("PLAYER_FLY") ),
  pState( PlayerState::Stand ),
  pCurrentSprite( &pStandSprite ),
  pX( Property::getSetting("PLAYER_OFFSET_X") ),
  pY( App::getScreenHeight() - Property::getSetting("PLAYER_OFFSET_Y") ),
  pJumpAllowed( true ),
  pSpeed( Property::getSetting("PLAYER_SPEED") ), pVY(0.0F), pAY(0.0F),
  PLAYER_Y_ACCELERATION( Property::getSetting("PLAYER_Y_ACCELERATION") ),
  PLAYER_Y_VELOCITY( Property::getSetting("PLAYER_Y_VELOCITY") ),
  PLAYER_MAX_Y_POS( Property::getSetting("PLAYER_MAX_Y_POS") ),
  PLAYER_Y_OFFSET( Property::getSetting("PLAYER_OFFSET_Y") ),
  MAX_Y_PLAYER( App::getScreenHeight() -PLAYER_Y_OFFSET ),
  PLAYER_OFFSET_X( Property::getSetting("PLAYER_OFFSET_X") ),
  logger("Player"), PLAYER_H( Property::getSetting("PLAYER_H") ),
  PLAYER_W( Property::getSetting("PLAYER_W") ),
  pMaxPlayerOnScreenX( pScreenWidth*0.6f ),timer( NULL ),
  DISABLE_COLLISION_WITH_ENEMY_TIME( 2500 )
{
	logger.methodStart("Player()");
    pStandSprite.setX( 300 );
    lastVY = 0.0f;

    PLAYER_MAX_Y_POS = Property::getSetting("PLAYER_MAX_Y_POS") + (short)App::getScreenHeight()%(short)Property::getSetting("TILES_SIZE");

    logger.info( "PLAYER_MAX_Y_POS:" + toString(PLAYER_MAX_Y_POS) );

    logger.methodEnd("Player()");
}


/** bohater zaczyna biec, mapa sie jednoczesnie przesuwa */
void Player::run(){
  pCurrentSprite = &pRunSprite;   
  pState = PlayerState::Run;
}

/** Bohater przestaje leciec w gore i zaczyna opadac */
void Player::fall() {
	if( pCurrentSprite != &pRunSprite )
		pVY = -1*PLAYER_Y_ACCELERATION;
}

/** Rysowanie */
void Player::draw(){
	//@TODO cos zrobic z ta 10
  pCurrentSprite->draw( pX, pY+10, PLAYER_W, PLAYER_H );
}


/** Metoda wylacza wykrywanie kolizji z wogami i uruchamiamia timer ktory te wykrywanie wlaczy ponownie */
void Player::disableEnemyDetect() {
	pColisionWithEnemy = false;
	timer = SDL_AddTimer( DISABLE_COLLISION_WITH_ENEMY_TIME, enableEnemyDetect_callbackTimer, this );
}

/** Metoda statyczna wywolywana przez timer celem wlaczenia wykrywania kolizji z wrogami  */
Uint32 Player::enableEnemyDetect_callbackTimer(Uint32 interval, void *param) {
	pColisionWithEnemy = true;
    return( 0 );
}


/** Aktualizacja gracza */
void Player::update(const float& dt, ColisionSide& side ){
 
  pCurrentSprite->update(dt);
 
  if( pIsFly ) {
      pVY = PLAYER_Y_VELOCITY;
      pAY = PLAYER_Y_ACCELERATION;  
      pCurrentSprite = &pFlySprite;
  }

  /** Polozenie w poziomie */
  //@TODO usunac liczbe magiczna
  if( pCurrentSprite != ( &pStandSprite ) ) {
     if( pX < ( LiveBar::getLiveAmount()*pMaxPlayerOnScreenX ) ) {
    	 pX += dt * 80;
     }
     else if( pX > ( LiveBar::getLiveAmount()*pMaxPlayerOnScreenX ) && pX > PLAYER_OFFSET_X  ) {
    	 pX -= dt *80;
     }

  /** Polozenie w pionie */
  float nextY = pY + ( (pVY+pAY) * (dt) * 15);


  if( side.up == true &&  nextY < pY ) {
	 fall();
	 pY = side.pos_Y_px;
	 return;
  }

  if( side.down == true &&  nextY > pY ) {
	  pCurrentSprite = &pRunSprite;
	  pY = side.pos_Y_px;
 	  return;
  }

  if( side.down != true && pY != MAX_Y_PLAYER &&  nextY > pY )
	  pCurrentSprite = &pFlySprite;


    if( nextY > PLAYER_MAX_Y_POS && nextY < MAX_Y_PLAYER ) {
   		pY = nextY;
    }
    else if( nextY >= MAX_Y_PLAYER ) { // gracz laduje na ziemi
      pCurrentSprite = &pRunSprite;
      pY = MAX_Y_PLAYER;      
    }

    if( pCurrentSprite != &pRunSprite )
    	pVY -= pAY * (dt*0.5);

  }
    
} 

/** */
void Player::reset(){
    logger.info("Player::reset() => Reseting hero");
    pCurrentSprite = &pStandSprite;
    pX = Property::getSetting("PLAYER_OFFSET_X");
    pY = MAX_Y_PLAYER;
    pVY=0.0F;
    pAY=0.0F;
}

/** Obsluga podskakiwania gracza */
void Player::jump() {
  
  if( pCurrentSprite == &pStandSprite ) return; // gracz jeszcze nie zaczal biec

  pVY = PLAYER_Y_VELOCITY;
  pAY = PLAYER_Y_ACCELERATION;
  
  pCurrentSprite = &pFlySprite;
}

