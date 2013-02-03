#include "Resource.hpp"
#include "Property.hpp"
#include "Property.hpp"
#include "MapManager.hpp"
#include <App.hpp>


map< string,SDL_Surface* >  Resource::pSurfaces;
map< string,TTF_Font* >  Resource::pFonts;


/** Logowanie bledow w przypadku bledu podczas wczytywania czcionki  */
void Resource::fontError() {

    critical("Brak czcionki");
    critical( TTF_GetError() );
    throw std::runtime_error("Resource:load");

}


/** Wczytuje czcionki i obrazki z plikow */
void Resource::load() {

    atexit( clearResource );

	loadImage( "atlas.png", "ATLAS" );
	loadImage( "background.jpg", "BACKGROUND" );
	loadImage( "menu_background.jpg", "MENU_BACKGROUND" );
	loadImage( "menu_background_empty.jpg", "MENU_BACKGROUND_EMPTY" );
	loadImage( "level_background.png", "LEVEL_BACKGROUND" );
	loadImage( "fill.png", "FILL" );
	loadImage( "key.png", "ABOUT" );

    loadFont( Property::get("FONT_PATH").c_str(), "font_small", Property::getSetting("SMALL_FONT") );
    loadFont( Property::get("FONT_PATH").c_str(), "font_normal", Property::getSetting("NORMAL_FONT") );
    loadFont( Property::get("FONT_PATH").c_str(), "font_big", Property::getSetting("BIG_FONT") );

}

/** Metoda wczytuje obrazek z podanej sciezki i wrzuco do mapy pod podana nazwa */
void Resource::loadImage( const string& name, const string& resourceName ) {

	info("Load image:" + name );

    SDL_Surface* tmpSurf = IMG_Load( string("data/pic/"+name).c_str() );
    if ( tmpSurf == NULL ) {
        critical( name + " file not found");
        throw std::runtime_error("Resource::load");
    }
    pSurfaces.insert( std::pair<string,SDL_Surface*>( resourceName,tmpSurf ) );

}


/** Metoda wczytuje z podanej sciezki czcionke o podanych rozmiarach i zapisuej pod przekazana nazwa */
void Resource::loadFont( const string& path, const string& name, double size ) {

	TTF_Font* font = TTF_OpenFont( path.c_str(), size );

	 if ( font == NULL ) {
		 Resource().fontError();
		 throw std::runtime_error("Font not load:" + path );
	 }
	 else
	        pFonts.insert( std::pair<string,TTF_Font*>(name, font) );

}


/** statyczny deskrtuktor- wylacza zaladowane w load moduly i czysci pamiec  */
void Resource::clearResource() {

	// zamykanie czcionek
	map< string, TTF_Font* >::iterator it( pFonts.begin() );
	while( it != pFonts.end() ) {
		TTF_CloseFont( it->second );
		++it;
	}

	map< string, SDL_Surface* >::iterator itSurf( pSurfaces.begin() );
	while( itSurf != pSurfaces.end() ) {
		SDL_FreeSurface( itSurf->second );
		++it;
	}
}


/** Metoda wyszukuje w tablicy asocjacyjnej fontu o podanej
 *  nazwie i zwraca wskaznik do niego
 */
TTF_Font* Resource::getFont(string name) {

    if (containsFont( name ) ) {
        return pFonts.find( name )->second;
    }
    else
    {
        error(name + ":Not found font" );
        throw std::runtime_error("Resource::getFont");
    }

}

/** Metoda zwraca adres powierchni przechowywanej w pamieci. Powierzchnie sa 
 *  wypelnione wczytanymi obrazkami.
 * @throw std::runtime_error const char* : nazwa metody
 */
SDL_Surface* Resource::getSurf( string Name ){
  
  if(  containsSurf(Name) ){
    return pSurfaces.find( Name )->second;
  }
  else{
    error(Name + ":Not found surfaces" );
    throw std::runtime_error(string("Resource::getSurf")); 
  }

}

