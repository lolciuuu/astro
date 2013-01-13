#include "../include/Background.hpp"
#include "../include/Resource.hpp"

Background::Background(): pBackgroungImg( 0 ),
pPLayerY( Property::getSetting("PLAYER_MAX_Y_POS") + (short)pScreenWidth%(short)Property::getSetting("TILES_SIZE")  ),
pBackSurf( NULL )
{
	logger.setClassName("Background");
}

//@TODO wywalic liczbe magiczna
void Background::update( const float& dt,const float& player_y )
{
	if( pFirst.w + pFirst.x < 0 ) {
		pFirst.x = pSecond.x;
		pSecond.x += pFirst.w;
	}
	else {
		pFirst.x -= 200 * dt;
		pSecond.x = pFirst.w + pFirst.x;
	}

	pPLayerY = pScreenHeight - player_y;

}

void Background::draw() {
//@TODO usunac liczbe magiczna
float factor_y = 0.03;

	if( (pFirst.w + pFirst.x) <= pScreenWidth ) {
		pRendererPtr->draw( pBackgroungImg,  pFirst.x,  (pPLayerY*factor_y) , pFirst.w, pScreenHeight );
		pRendererPtr->draw( pBackgroungImg,  pSecond.x,  (pPLayerY*factor_y) , pFirst.w, pScreenHeight );
	}
	else
	    pRendererPtr->draw( pBackgroungImg, pFirst.x, (pPLayerY*factor_y) , pFirst.w, pScreenHeight );
}

void Background::init() {

	SDL_Surface* surf =  Resource::getSurf("LEVEL_BACKGROUND") ;

	pBackSurf = surf;
	pSecond.w = pFirst.w = surf->w;
	pSecond.h = pFirst.h = surf->h;

	pFirst.y = pScreenHeight - pFirst.h;

	pBackgroungImg = RendererGL::getSurfaceInGLFormat( surf );
}

void Background::reset() {
	pFirst = Rect();
	pSecond = Rect();

	pPLayerY = Property::getSetting("PLAYER_MAX_Y_POS") + (short)pScreenWidth%(short)Property::getSetting("TILES_SIZE");
	pSecond.w = pFirst.w = pBackSurf->w;
	pSecond.h = pFirst.h = pBackSurf->h;
	pFirst.y = pScreenHeight - pFirst.h;

}
