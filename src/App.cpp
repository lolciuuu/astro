#include "../include/App.hpp"
#include "Const.hpp"

#ifdef __linux__
	#include <X11/Xlib.h>
#endif


/// Inicjacjowanie zmiennych statycznych
SDL_Surface* App::pScreen(NULL);

ushort App::pScreen_h;
ushort App::pScreen_w;
//END

/** Zainicjowanie bibliotek, utworzenie okna */
App::App(): logger("App"), pIsDone( false ), pEvent(), pIcon( NULL )
{
	logger.methodStart( "App()" );

	#ifdef __linux__ // bez tego wystepuja problemy z watkami
		XInitThreads();
	#endif

    /** -- Inicjowanie SDL-a i wtyczek -- */
    if ( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER ) != 0 ) {
        logger.critical( "Failed to init SDL" );
        throw std::runtime_error("App::App()");
    }

    if ( TTF_Init() == -1 ) {
        logger.critical( "Failed to init SDL ttf modules" );
        throw std::runtime_error("App::App()");
    }

    /** --- Pobranie rozdzielczosci ekranu --- */
    const SDL_VideoInfo* myPointer = SDL_GetVideoInfo();
    pScreen_w = myPointer->current_w;
    pScreen_h = myPointer->current_h;


	// Konfiguracja dodatkowa okna
	#ifdef FULL_SCREEN_FLAG
	   SDL_ShowCursor( false );

	#else
	   SDL_ShowCursor( true );
	   pScreen_h = HEIGHT;
	   pScreen_w = WIDHT;
	#endif

    logger.info( "Screen resoulution: " );
    logger.info( "\tHeight: " + toString( pScreen_h ) + "px" );
    logger.info( "\tWidth: " + toString( pScreen_w ) + "px" );

    if(  pScreen_w > MAX_SCREEN_WIDTH || pScreen_h > MAX_SCREEN_HEIGHT ){
       /* w przypadku rozdzielczosci wiekszej niz full HD obraz ma wymiary 1920x1080 */
        logger.critical("Screen resoulution is to large. Maximum is: 1920x1080 px");
        pScreen_h = MAX_SCREEN_HEIGHT;
        pScreen_w = MAX_SCREEN_WIDTH;
    }
    else if ( pScreen_w < MIN_SCREEN_WIDTH || pScreen_h < MIN_SCREEN_HEIGHT ) {
        logger.critical("Screen resoulution is too small");
    	throw std::runtime_error("App::App()");
    }

	// Inicjowanie grafiki
   	initVideoGL();

	SDL_WM_SetCaption( "Astro Rush" VERSION, NULL );

	pIcon = IMG_Load("data/pic/ico.png");

	SDL_WM_SetIcon( pIcon , NULL );

	logger.methodEnd( "App" );

}


/** */
void App::initVideoGL() {

	logger.methodStart( "initVideoGL" );

    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );


	  pScreen = SDL_SetVideoMode(
					#ifndef FULL_SCREEN_FLAG
					      WIDHT, HEIGHT ,
					#else
					      pScreen_w, pScreen_h,
					#endif
					      	  	  	  	  32,				// ile bitowy ma byc obraz
		                                  SDL_HWSURFACE 	// przechowywanie obrazu w pamieci grafiki
		                                | SDL_DOUBLEBUF 	// podwojne buforowanie
		                                | SDL_ANYFORMAT 	// obsluga roznych formatow grafik
		                                | SDL_ASYNCBLIT	 	// Enables the use of asynchronous updates
					#ifdef FULL_SCREEN_FLAG
		                                | SDL_FULLSCREEN
					#endif
					      	  	  	  	| SDL_OPENGL
		         );

		    if ( pScreen == NULL ) {
		        logger.critical( "Main surface is null, check SDL" );
		        throw std::runtime_error("App::App()");
		    }

  /** Ustawienie openGL-a do renderowania   */
  glViewport(0, 0, pScreen->w, pScreen->h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, pScreen->w, pScreen->h, 0, -1.0, 1.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0f, 0.0f, 0.0f);

  glDisable(GL_DEPTH_TEST);
  glDisable(GL_CULL_FACE);
  glDisable(GL_COLOR_MATERIAL);

  glEnable( GL_BLEND );			// mieszanie kolorow
  glEnable( GL_TEXTURE_2D );
  glDepthFunc(GL_LEQUAL);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glHint( GL_LINE_SMOOTH_HINT, GL_NICEST );
  glHint( GL_POINT_SMOOTH_HINT, GL_NICEST );
  glHint( GL_TEXTURE_COMPRESSION_HINT, GL_NICEST );

   GLenum error = glGetError();
   if( error != GL_NO_ERROR )
   {
	   cout<<"\nOpenGL critical: "<<error;
       throw std::runtime_error("App::initVideoGL()");
   }

  logger.methodEnd( "initVideoGL" );

}

/** Wyjscie z aplikacji */
App::~App()
{
    delete pGame;

    SDL_FreeSurface( pIcon );
    SDL_FreeSurface( pScreen );

    TTF_Quit();
    SDL_Quit();
}

/**
 *
 */
void App::init() {

#ifdef LIGHT_GL
  logger.info("Lighting is enabled");
  glEnable(GL_LIGHTING);

  GLfloat light_ambient[] = { 0.3, 0.3, 0.3, 1.0 };
  GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat light_position[] = { .5, .5, 4, 0.0 };

  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);

  GLfloat light1_ambient[] = { 0.8, 0.8, 0.8, 1.0 };
  GLfloat light1_diffuse[] = { 0.0, 0.0, 0.0, 1.0 };
  GLfloat light1_specular[] = { 0.5, 1.0, 1.0, 1.0 };
  GLfloat light1_position[] = { .5, .5, .1, 1.0 };
  GLfloat spot_direction[] = { -1.0, -1.0, 0.0 };

  glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
  glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
  glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
  glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.5);
  glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.5);
  glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.2);

  glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
  glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
  glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);

  glEnable(GL_LIGHT1);

  glEnable(GL_LIGHT0);

#endif

    Writer::getInstance()->setScreenPtr( pScreen );

    pGame = new Game();
    Renderer::getInstance(); /// zainicjowanie renderera !!!
    Writer::getInstance()->init(); /// zainicjowanie writera !!!
    Renderer::getInstance()->init();
}


void App::run() {

	pRenderer = Renderer::getInstance();

    const double TIME_STEP = 0.01;
  
    register double last_ticks = SDL_GetTicks() * 0.001;
    register double current_ticks( 0.0 );

#ifdef DEBUG
    // Co okreslony czas obliczana jest ilosc FPS, i pokazywana na pasku tytulowym
    if ( SHOW_FPS ) timerFPS = SDL_AddTimer( 1000, FPS_callbackTimer, this );
#endif

    while ( !pGame->isDone() ) { 

        //time update
    	current_ticks = SDL_GetTicks() * 0.001;

    	if( current_ticks >= last_ticks ) {
    		last_ticks += 0.001;

         	pGame->update( TIME_STEP );
    		pRenderer->cleanScreen();
    		pGame->draw();
    		pRenderer->flip();

    	}
    	else {
    		int sleep_time = (int) (current_ticks- last_ticks)*1000;
    		SDL_Delay( sleep_time );

    		logger.warring("Sleep");
    	}

    	processEvent();

    	// Zliczanie klatek
		#ifdef DEBUG
        	if( SHOW_FPS ) ++pframeRating; // Licznik wyswietlonych klatek w danej jednostce czasu
		#endif

	SDL_Delay( 0 );

    }//END WHILE

}

/** Pierwszy poziom obslugi zdarzen. Sprawdzane jest jaki klawisz zostal nacisniety, a
 * nastepnie zostaje uruchomiona odpowiednia metoda klasy Game odpowiadajaca za obsluge danego klawisza.
 * Jest to filtrowanie zdarzen na rzecz klasy Game.
 * @return void
 * @param void
 */
void App::processEvent() {


    while ( SDL_PollEvent( &pEvent ) )
    {
        if ( pEvent.type == SDL_QUIT )
        {
            pIsDone = true;
        }
		#ifdef DEBUG
        /** @TODO Po nacisnieciu F1 wyjscie z aplikacji! */
        else if (pEvent.type == SDL_KEYDOWN && pEvent.key.keysym.sym == SDLK_F1 ) {
            error("Pressed F1 key. App is terminated.");
            throw std::runtime_error("App::processEvent");
        }
	#endif
        else if (pEvent.type == SDL_KEYDOWN && pEvent.key.keysym.sym == SDLK_ESCAPE ) {
            info("ESC pressed");
            pGame->pressedEsc();
        }
	    else if (pEvent.type == SDL_KEYDOWN && pEvent.key.keysym.sym == SDLK_SPACE ) {
            pGame->SpaceDown();
        }
        else if (pEvent.type == SDL_KEYUP && pEvent.key.keysym.sym == SDLK_SPACE ) {
            pGame->SpaceUp();
        }
        else if (pEvent.type == SDL_KEYDOWN && pEvent.key.keysym.sym == SDLK_LSHIFT ) {
            pGame->pressedShift();
        }
        else if (pEvent.type == SDL_KEYDOWN && pEvent.key.keysym.sym == SDLK_RCTRL ) {
                   pGame->pressedCtrl();
        }
        else if ( pEvent.type == SDL_KEYDOWN &&  ( pEvent.key.keysym.sym >= 97 && (int)pEvent.key.keysym.sym <= 122 ) )
        {
            pGame->pressedChar( (char) pEvent.key.keysym.sym );
        }
        else if(  pEvent.type == SDL_KEYDOWN && pEvent.key.keysym.sym == SDLK_BACKSPACE ) {
        	pGame->pressedBackspace();
        }
        else if (pEvent.type == SDL_KEYDOWN && pEvent.key.keysym.sym == SDLK_RETURN ) {
            pGame->pressedReturn();
        }
        else if (pEvent.type == SDL_KEYDOWN && pEvent.key.keysym.sym == SDLK_LEFT ) {
            pGame->pressedLeft();
        }
        else if (pEvent.type == SDL_KEYDOWN && pEvent.key.keysym.sym == SDLK_RIGHT ) {
            pGame->pressedRight();
        }
        else if (pEvent.type == SDL_KEYDOWN && pEvent.key.keysym.sym == SDLK_UP ) {
            pGame->pressedUp();
        }
        else if (pEvent.type == SDL_KEYDOWN && pEvent.key.keysym.sym == SDLK_DOWN ) {
            pGame->pressedDown();
        }
    }
}


/** Metoda jest callbackiem wywolywanym automatycznie przez Timer SDL-a
 *  Jako parametr przyjmuje wskaznik do obiektu klasy App na rzecz ktorego ma wywolac
 *  metoda obliczajaca FPS-y
 *
 * @param Uint32 interval: wysylany przez SDL-a czas
 * @param void *param : Rzutowanie na App*
 * @return Uint32 : przekazany Timer
 *
 */
Uint32 App::FPS_callbackTimer(Uint32 interval, void *param) {

    App* app = reinterpret_cast<App*>(param);
    app->FPS_show();
    return( interval );

}


/** Metoda pokazuje na pasku tytulowym apliakcji ilosc fps-ow.
 * @warning Funkcja jest niestabilna i w systemie linuks moze powodowac po jakims czasie
 * niespodziewane zakonczenie aplikacji. Brak pomyslu na naprawe.
 *
 * @param void
 * @return void
 */
void App::FPS_show() {

    std::ostringstream ss;
    ss << pframeRating;
    string strFPS("Debug [");
    strFPS += ss.str();
    strFPS += " fps]";

    SDL_WM_SetCaption( strFPS.data(),NULL );
    
    pframeRating = 0;
}




