#include "LiveBar.hpp"
#include "App.hpp"

ulong LiveBar::pDistNum;
float LiveBar::pLiveAmount(1);
bool LiveBar::isLive(true);
bool LiveBar::isImmortal( false );

/** */
LiveBar::LiveBar() :pDistStr( Property::get("HIGH_GAME_DIST") ), pBonusAmount( 0 ), timer(),
pImmortalTexture( 0 ), pImmortalOpacity( 0.0f )
{
  pDistanceRect.y = Property::getSetting( "HIGH_OFFSET_Y" );
  pDistanceRect.x = (App::getScreenWidth() / 2) -100;

  
}


/** Rysowanie paska zycia...cala gorna czesc ekranu */
void LiveBar::draw() {

	//@TODO optymalizacja

	if( pImmortalTexture == 0 ) {
		pImmortalTexture = Renderer::getSurfaceInGLFormat( Resource::getSurf("FILL") );
	}

    Rect tmp(0,0,pScreenWidth,pScreenHeight);
    tmp.a= pImmortalOpacity;
    pRendererPtr->draw( pImmortalTexture , tmp);

	pRendererPtr->draw( "LIVE_BAR_BACK", pScreenWidth*0.053, pScreenHeight*0.043, -1, -1 );
	pRendererPtr->draw( "LIVE_BAR_FILL", pScreenWidth*0.053, pScreenHeight*0.044, 200*pLiveAmount, -1 );
	pRendererPtr->draw( "LIVE_BAR",      pScreenWidth*0.011,  pScreenHeight*0.025, -1, -1 );

	// Wypisywanie informacji i przebytej drodze
	std::ostringstream ss;
    ss << pDistNum;

    //@TODO znalsc wszystkie okreslenia czcionki poprzez liczbe magiczna i zastaoic stala
    pWriterPtr->draw( pDistanceRect, pDistStr + string(ss.str()) + " m" );

    //@TODO optymalizacja
    for( int i=0; i<pBonusAmount; ++i ) {
    	Sprite bonus = SpriteManager::getInstance()->getSprite("MAP_40");
    	bonus.draw( pScreenWidth - ( pScreenWidth*0.1 ) - (i*pScreenWidth*0.05), pScreenHeight*0.03 );
    }

}


/** */
void LiveBar::update(const float& dt ) {
	if( isImmortal ) return;

	float nextLiveAmount = 0.0f;
//@TODO jakos dziwnie dziala- przetestowac
  if( Player::isFly() )
	  nextLiveAmount = pLiveAmount - (dt*0.1);
  else
	  nextLiveAmount = pLiveAmount - (dt*0.25);

  if( nextLiveAmount >= 0 )
  pLiveAmount = nextLiveAmount;

  if( pImmortalOpacity > 0 )
	  pImmortalOpacity -= 0.02;

}

/** */
void LiveBar::colision( short type ) {
//@TODO usunac liczby magiczne

	if( type == COLISION_WITH_ENEMY ) {
		  if( pLiveAmount >= 0.01 )
		    pLiveAmount -= 0.01;
	}
	else {
		  if( pLiveAmount >= 0.03 )
				    pLiveAmount -= 0.03;
	}
  
}

/** */
bool LiveBar::useBonus() {
	if( isImmortal == true ) return false;

	  if( pBonusAmount > 0 ){
		  --pBonusAmount;
		  isImmortal = true;
		  pImmortalOpacity = 1.0f;
		  timer = SDL_AddTimer( 4000, disableImmortal_callbackTimer, this );
		  pLiveAmount = 1.0f;
		  return true;
	  }
	  else {
		  return false;
	  }
}

/** */
Uint32 LiveBar::disableImmortal_callbackTimer(Uint32 interval, void* param) {
	isImmortal = false;
	return( 0 );
}

/** */
void LiveBar::increaseLive() {
    if( pLiveAmount <= 0.9 )
    pLiveAmount += 0.15;
}

/** */
void LiveBar::reset() {
  pLiveAmount = 1.0f;
  isLive = true;
  pBonusAmount = 0;
}
