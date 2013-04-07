#include "LiveBar.hpp"
#include "App.hpp"

ulong LiveBar::pDistNum;
float LiveBar::pLiveAmount(1);
bool LiveBar::isLive(true);
bool LiveBar::isImmortal( false );

/** */
LiveBar::LiveBar() :pDistStr( Property::get("HIGH_GAME_DIST") ), pBonusAmount( 0 ), timer(),
pImmortalTexture( 0 ), pImmortalOpacity( 0.0f ), pBonusIcon( SpriteManager::getInstance()->getSprite("HEARTH_ADD") )
{
  pDistanceRect.y = Property::getSetting( "HIGH_OFFSET_Y" );
  pDistanceRect.x = (App::getScreenWidth() / 2) -100;
  
}


/** Rysowanie paska zycia...cala gorna czesc ekranu */
void LiveBar::draw() {

	//@TODO optymalizacja

	// kiedy wlaczona niesmiertelnosc pokazuje sie obwodka dookola ektanu */
	if( pImmortalTexture == 0 ) {
		logger.warring("Get surface in GL fomrat");
		pImmortalTexture = Renderer::getSurfaceInGLFormat( Resource::getSurf("FILL") );
	}

    Rect tmp(0,0,pScreenWidth,pScreenHeight);

    tmp.a= pImmortalOpacity;

    pRendererPtr->draw( pImmortalTexture , tmp);

	pRendererPtr->draw( "LIVE_BAR_BACK", pScreenWidth*0.053, pScreenHeight*0.043, -1, -1 );

	if( pLiveAmount > 0.0f )
		pRendererPtr->draw( "LIVE_BAR_FILL", pScreenWidth*0.053, pScreenHeight*0.044, 200*pLiveAmount, -1 );

	pRendererPtr->draw( "LIVE_BAR",      pScreenWidth*0.016,  pScreenHeight*0.025, -1, -1 );

	// Wypisywanie informacji i przebytej drodze

    //@TODO znalsc wszystkie okreslenia czcionki poprzez liczbe magiczna i zastaoic stala
    pWriterPtr->draw( pDistanceRect, pDistStr + toString( pDistNum ) + " m" );


    Rect textRect( pScreenWidth - 140, 45 );
    pWriterPtr->draw( textRect, "x" , FontSize::SMALL );
    textRect.x += 30;
    textRect.y -= 10;
    pWriterPtr->draw( textRect, toString( pBonusAmount ), FontSize::BIG );

    //@TODO optymalizacja
    pBonusIcon.draw( pScreenWidth - 200, 30 );

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

  pLiveAmount = nextLiveAmount;

  if( pImmortalOpacity > 0 )
	  pImmortalOpacity -= 0.02;

}

/** */
void LiveBar::colision( short type ) {
//@TODO usunac liczby magiczne

	if( type == COLISION_WITH_ENEMY ) {
		debug("Enemy colision");
		pLiveAmount -= 0.3;
	}
	else {
		 pLiveAmount -= 0.1;
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

/** Metoda statyczna wywolywana przez timer wtedy kiedy mija czas w ktorym gracz nie traci zycia */
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
