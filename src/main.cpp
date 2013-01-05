#include "Headers.hpp"
#include "App.hpp"
#include "Property.hpp"
#include "Resource.hpp"

/** AstroRush 2D game */
int main( int argc, char* argv[] ) {



  #ifdef DEBUG
    warring("Starting in debug mode");
  #endif

    App* app = new App();

    try {

	app->startSplash();
	
	// Implementacja timera animujacego splash
	while( ( !app->isSplashDone() ) ){ 
	  SDL_Delay( 20 ); // czas aktualizacji animacji
	  app->drawSplash();
	}
	
	// Zabezpieczenie w razie gdyby splash skonczyl sie wczesniej niz wczytywanie zasobow
	while( !app->isInitDone() ) SDL_Delay( 5 );
	  
        app->init();	
        app->endSplash();

        info( Property::get("END_STARTING") );
        app->run();//Uruchomienie glownej petli programu

    }
    catch( char const* Error ){
       delete app;
       critical( Error );
       critical("Aplication terminated");
       return( EXIT_FAILURE );
    }
    catch( std::exception& e ) {
    	 delete app;
    	 critical( e.what() );
    	 critical("Aplication terminated");
    	 return( EXIT_FAILURE );
    }
    catch ( ... ) {
        delete app;
        critical("Unexcepted error");
        critical("Aplication terminated");
        return( EXIT_FAILURE );
    }

    delete app;
    info(  Property::get("GAME_END_INFO") );
    return( EXIT_SUCCESS );

}
