#ifndef WRITER_HPP
#define WRITER_HPP
#include "Headers.hpp"
#include "Renderer.hpp"
#include "Logger.hpp"

class Writer
{
public:
 
  void draw( Rect WhereRect, string Text );

  void draw( Rect WhereRect, string Text , SDL_Color Color );

  void draw( Rect WhereRect, string Text , float size );
  
  float getHeight_GL( int size_px ) const { return size_px/pScreen->h; }
  float getWidth_GL( int size_px ) const { return size_px/pScreen->w; }
  float getStringSize_GL ( int charAmount ) {
	  return (float)(charAmount * 10)/ (float)pScreen->w;
  }

  static Writer* getInstance(){
		if( pInstance == NULL ){
		    atexit( clean );
			pInstance = new Writer();
			return pInstance;
		}
		return pInstance;
	}
	
   ~Writer();
	
	void init();
	
	void setFont(string fontName, SDL_Color fontColor); 
	
	void setFont( string FontName );
	
	void setScreenPtr(SDL_Surface* Screen){ pScreen = Screen; };
	
	void setFontSize( float S ) {  pFontSize = S;}

private:
   Writer();
   
   static void clean(){ delete pInstance; }
   
private:  
  static Writer* pInstance;
  Renderer* pRendererPtr;
  SDL_Surface* pScreen;
  TTF_Font* pFont;
  Logger logger;
  float pFontSize;
};

#endif // WRITER_HPP

