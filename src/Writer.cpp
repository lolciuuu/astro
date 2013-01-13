#include "../include/Writer.hpp"
#include "Resource.hpp"


Writer* Writer::pInstance;


/** */
Writer::Writer(): pRendererPtr( NULL ), pScreen( NULL ), logger("Writer"), pScreenWidth(0.0f),
		pScreenHeight(0.0f)
{
	pFont = Resource::getFont("font_normal");
	pFontBig = Resource::getFont("font_big");
	pFontSmall = Resource::getFont("font_small");
}


float Writer::getCenterX(const string& str) {
	return ( (pScreenWidth*0.5) - ( getTextWidth(str) * 0.5) );
}

/** */
Writer::~Writer() {
	TTF_CloseFont( pFont );
	delete pInstance;
}


/** Metoda zwraca ile pixeli szerokosci ma text na ekranie. Jezeli sa bledy to zwraca -1 */
int Writer::getTextWidth(const string& str) {

	int w(0),h(0);

	    if( TTF_SizeText( pFont, str.c_str(), &w ,&h ) == 0 ) {
	  	  return w;
	    }
	    else {
	    	logger.error("Invalid font size [int Writer::getTextWidth(const string& str)]");
	    	return -1;
	    }
}

/** Metoda zwraca ile pixeli wysokosci ma text na ekranie. Jezeli sa bledy to zwraca -1 */
int Writer::getTextHeight(const string& str) {
	  int w(0),h(0);

	    if( TTF_SizeText( pFont, str.c_str(), &w ,&h ) == 0 ) {
	  	  return h;
	    }
	    else {
	    	logger.error("Invalid font size [Writer::getTextHeight(const string& str)]");
	    	return -1;
	    }
}


/** Wypisuje text o podanym kolorze */
void Writer::draw( Rect WhereRect, string Text, SDL_Color Color, FontSize Size  ){

	int w(0),h(0);

	TTF_Font* fontTmp = NULL;

	switch( Size ) {
	case (FontSize::NORMALL): {
			fontTmp = pFont;
	};
	break;
	case (FontSize::SMALL): {
			fontTmp = pFontSmall;
	};
	break;
	case (FontSize::BIG): {
			fontTmp = pFontBig;
	};
	break;
	default : {
			fontTmp = pFont;
	};
	break;
	}

	SDL_Surface* tmp_surf = TTF_RenderUTF8_Blended( fontTmp, Text.c_str(), Color );

    if( TTF_SizeText( fontTmp, Text.c_str(), &w ,&h ) == 0 ) {
  	  WhereRect.w = w;
  	  WhereRect.h = h;
    }
    else {
    	logger.warring("Invalid font size [Writer::draw( Rect WhereRect, string Text, SDL_Color Color )]");
    }

  pRendererPtr->draw( tmp_surf, WhereRect );
  SDL_FreeSurface( tmp_surf );
  
}

/** Wypisuje przekazany text pod wspolrzednymi w WhereRect
 *  ( wysokosc i szerokosc w whereRect sa ignorowane)
 */
void Writer::draw( Rect WhereRect, string Text, FontSize Size  ){

	draw( WhereRect, Text, SDL_Color{ 250,250,250 }, Size );
  
}

/** Pobranie referencji do Renderera */
void Writer::init() {
	string methodName = "Writer::init()";
	logger.methodStart( methodName );

	pRendererPtr = Renderer::getInstance();
	pScreenWidth = pRendererPtr->getScreenWidth();
	pScreenHeight = pRendererPtr->getScreenHeight();

	logger.methodEnd( methodName );
}

