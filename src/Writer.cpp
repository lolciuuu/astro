#include "../include/Writer.hpp"
#include "Resource.hpp"

/// Init zmiennych statycznych
  Writer* Writer::pInstance;
//END

/** */
Writer::Writer(): pRendererPtr( NULL ), pScreen( NULL ), logger("Writer"),
		pFontSize(0.04f)
{
  pFont = Resource::getFont("bold_small");
}

/** */
void Writer::setFont( string FontName ){
    pFont = Resource::getFont(FontName);
}

/** */
Writer::~Writer() {

}

/** */
void Writer::draw( Rect WhereRect, string Text, SDL_Color Color ){
//@TODO ujedolicic rozmiary czionek w calej aplikacji
  SDL_Surface* tmp_surf = TTF_RenderText_Blended( pFont, Text.c_str(), Color );
  WhereRect.w = pScreen->w * (0.01 * Text.length() );
  WhereRect.h = pScreen->h * pFontSize;
  pRendererPtr->draw(tmp_surf,WhereRect);
  SDL_FreeSurface( tmp_surf );
  
}

/** */
void Writer::draw( Rect WhereRect, string Text ){

  SDL_Color Color={ 250,250,250 };  		    
  SDL_Surface* tmp_surf = TTF_RenderText_Blended( pFont, Text.c_str(), Color );
  WhereRect.w = pScreen->w * (0.01 * Text.length() );
  WhereRect.h = pScreen->h * pFontSize;


  pRendererPtr->draw(tmp_surf,WhereRect);
  SDL_FreeSurface( tmp_surf );
  
}

/** Z parametru WhereRect brane jest tylko polozenie x,y. Szerokosc i wysokosc okreslana dynamicznie */
void Writer::draw( Rect WhereRect, string Text, float size ){

  SDL_Color Color={ 250,250,250 };
  SDL_Surface* tmp_surf = TTF_RenderText_Blended( pFont, Text.c_str(), Color );
  WhereRect.w = pScreen->w * ( (size*0.2) * Text.length() );
  WhereRect.h = pScreen->h * size;


  pRendererPtr->draw(tmp_surf,WhereRect);
  SDL_FreeSurface( tmp_surf );

}


/** Pobranie referencji do Renderera */
void Writer::init() {
	string methodName = "Writer::init()";
	logger.methodStart( methodName );

		pRendererPtr = Renderer::getInstance();

	logger.methodEnd( methodName );
}

