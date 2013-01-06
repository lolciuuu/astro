#ifndef WRITER_HPP
#define WRITER_HPP
#include "Headers.hpp"
#include "Renderer.hpp"
#include "Logger.hpp"

/** Klasa obslugujaca wypisywanie tekstu na ekranie.
 * Jest to facade do wywolanie renderera  w przypadku tworzenia napisow
 */
class Writer {
public:
 
  void draw( Rect WhereRect, string Text );

  void draw( Rect WhereRect, string Text , SDL_Color Color );

  int getTextWidth( const string& str );

  int getTextHeight( const string& str );

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

	void setFont( string FontName );
	
	void setScreenPtr( SDL_Surface* Screen ){ pScreen = Screen; };

private:
   Writer();
   
   static void clean(){ delete pInstance; }
   
private:  
  static Writer* pInstance;

  Renderer* pRendererPtr;

  SDL_Surface* pScreen;

  TTF_Font* pFont;

  Logger logger;

};

#endif // WRITER_HPP

