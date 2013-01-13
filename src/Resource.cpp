#include "Resource.hpp"
#include "Property.hpp"
#include "Property.hpp"
#include "MapManager.hpp"
#include <App.hpp>

/// Inicjowanie zmiennych statycznych
map< string,SDL_Surface* >  Resource::pSurfaces;
map< string,TTF_Font* >  Resource::pFonts;
/// END


/** W razie niepowodzenia wczytania czcionki wyswietlanie informacji
 * i rzucenie wyjatku
 */
void Resource::fontError() {

    critical("Brak czcionki");
    critical( TTF_GetError() );
    throw std::runtime_error("Resource:load");

}


/** */
void Resource::load() {

    atexit( clearResource );

	loadImage( "atlas.png", "ATLAS" );
	loadImage( "background.jpg", "BACKGROUND" );
	loadImage( "menu_background.jpg", "MENU_BACKGROUND" );
	loadImage( "menu_background_empty.jpg", "MENU_BACKGROUND_EMPTY" );
	loadImage( "level_background.png", "LEVEL_BACKGROUND" );
	loadImage( "fill.png", "FILL" );

    loadFonts();

    // wczytanie map
    MapManager::load();
}

/**@TODO komentarz */
void Resource::loadImage( const string& name, const string& resourceName ) {

	info("Load image:" + name );

    SDL_Surface* tmpSurf = IMG_Load( string("data/pic/"+name).c_str() );
    if ( tmpSurf == NULL ) {
        critical( name + " file not found");
        throw std::runtime_error("Resource::load");
    }
    pSurfaces.insert( std::pair<string,SDL_Surface*>( resourceName,tmpSurf ) );

}


//@TODO wyalic nie uzywana metode
void Resource::loadFonts() {

    //bold small
    {
        TTF_Font* font = TTF_OpenFont(
                             Property::get("FONT_PATH").c_str(),
                             Property::getSetting("SMALL_FONT")
                         );

        if ( font == NULL )  Resource().fontError();
        pFonts.insert( std::pair<string,TTF_Font*>( "font_small",font ));
    }

    //bold normal
    {
        TTF_Font* font = TTF_OpenFont(
                             Property::get("FONT_PATH").c_str(),
                             Property::getSetting("NORMAL_FONT")
                         );

        if ( font == NULL )  Resource().fontError();
        pFonts.insert( std::pair<string,TTF_Font*>( "font_normal",font ));
    }

    //bold big
    {
        TTF_Font* font = TTF_OpenFont(
                             Property::get("FONT_PATH").c_str(),
                             Property::getSetting("BIG_FONT")
                         );

        if ( font == NULL )  Resource().fontError();
        pFonts.insert( std::pair<string,TTF_Font*>( "font_big",font ));
    }

    ///@TODO dodac reszte czcionek

}


/** statyczny deskrtuktor- wylacza zaladowane w load moduly i czysci pamiec  */
void Resource::clearResource() {
    /// @TODO Zwlanianie z pamieci wszystkich fontow
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

