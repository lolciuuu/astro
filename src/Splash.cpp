#include "../include/Splash.hpp"
#include "Headers.hpp"

bool Splash::pInitIsDone( false );
 int Splash::pframeRating;

Splash::Splash():  pSplashIsDone( false ), pCurrentLoop( 0 ), logger("Splash")
{
	pSplashGL=0;
	pSplashLoadLong=0;
	pColor=0;;
	pSplash= NULL;
	timerFPS=NULL;
	pScreen=NULL;
	pSplashLong=0;
	pScreenH=0;
	pScreenW=0;
}

Splash::~Splash()
{

}

bool Splash::isInitDone() const {
        return( Splash::pInitIsDone );
}
    
bool Splash::isSplashDone() const {
        return( pSplashIsDone );
}


/** */
void Splash::startSplash( ushort W, ushort H, SDL_Surface* Screen ) {

    logger.info("Load splash img => start");
    
    pScreenH = H;
    pScreenW = W;
    pScreen = Screen;

    SDL_CreateThread( initThread , NULL );

    pSplash = IMG_Load("data/pic/splash.jpg");

    if ( pSplash == NULL ) {
        logger.critical("Splash file not found");
        throw std::runtime_error("Splash::Spalsh");
    }


    { 	//Ustawianie wymiarow i polozenia obrazka splasha
    	ushort splashHeight = pSplash->h;
    	ushort splashWidth = pSplash->w;

    	pRectSplash.x = ( pScreen->w / 2u ) - ( splashWidth/2u );
    	pRectSplash.y = ( pScreen->h / 2u ) - ( splashHeight/2u );
    	pRectSplash.w = splashWidth;
    	pRectSplash.h = splashHeight;

    	pRectLoad.x = pRectSplash.x + 59;
    	pRectLoad.y = pRectSplash.y + 430.0;
    	pRectLoad.w = 1;
    	pRectLoad.h = 5;
    	pRectLoad.r = 0.0f;
    	pRectLoad.g = 0.46f;
    	pRectLoad.b = 0.98f;
    }

    // Kolor paska ladowania
    pColor =  SDL_MapRGB( pScreen->format, 0,166, 252 );

    GLenum format;
    GLint  colors_amount = pSplash->format->BytesPerPixel;

        if (colors_amount == 4) {
                if (pSplash->format->Rmask == 0x000000ff)
                        format = GL_RGBA;
                else
                        format = GL_BGRA;
        }
        else if (colors_amount == 3) {
                if (pSplash->format->Rmask == 0x000000ff)
                        format = GL_RGB;
                else
                        format = GL_BGR;
        }
        else {
            critical("Image is not truecolor");
        }

        glGenTextures( 1, &pSplashGL );

        glBindTexture( GL_TEXTURE_2D, pSplashGL );

        	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

        	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

        glTexImage2D( GL_TEXTURE_2D, 0, colors_amount, pSplash->w, pSplash->h, 0, format, GL_UNSIGNED_BYTE, pSplash->pixels );

        logger.info("Load splash img => end");
}
              

/** */
void Splash::endSplash() {
  SDL_FreeSurface( pSplash );
  logger.info("End splash");
}


/** */
void Splash::drawSplash() {

	pRectLoad.w = 208 * ( pCurrentLoop / static_cast<float>(100 * SPLASH_TIME)) ;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glBindTexture(GL_TEXTURE_2D, pSplashGL );

  		     glBegin(GL_QUADS);
  		     {
  		         glTexCoord2f(0,0);//1
  		         glVertex2f( pRectSplash.x, pRectSplash.y );

  		         glTexCoord2f( 1, 0 );//2
  		         glVertex2f( pRectSplash.x + pRectSplash.w, pRectSplash.y );

  	             glTexCoord2f(1, 1);//3
  		         glVertex2f( pRectSplash.x + pRectSplash.w , pRectSplash.y + pRectSplash.h );

  		         glTexCoord2f(0,1);//4
  		         glVertex2f( pRectSplash.x, pRectSplash.y + pRectSplash.h);
  		     }
  		     glEnd();

  	glDisable( GL_TEXTURE_2D );
  	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  	glColor3f( pRectLoad.r, pRectLoad.g, pRectLoad.b );

  	glBegin(GL_POLYGON);
  	    glVertex2f( pRectLoad.x, pRectLoad.y ); // bottom left
  	    glVertex2f( pRectLoad.x, pRectLoad.y + pRectLoad.h ); // bottom right...
  	    glVertex2f( pRectLoad.x + pRectLoad.w, pRectLoad.y + pRectLoad.h );
  	    glVertex2f( pRectLoad.x + pRectLoad.w, pRectLoad.y );
  	glEnd();

  	glColor3f(1, 1, 1);

    glEnable( GL_TEXTURE_2D );

    SDL_GL_SwapBuffers();

    // W mainie metoda jest wolana z opoznieniem 10 ms
    // SPLASH_TIME to czas podany w przyblizeniu w sekundach
    // bowiem opoznienia rysowania sprawiaja ze nie da sie tuodmierzyc sekundy
    ++pCurrentLoop;
    if ( pCurrentLoop > 100 * SPLASH_TIME ) pSplashIsDone = true;

}

/** Metoda jest wykonywana w osobnym watku, i wczytuje wszystkie zasoby
 *  Podczas wczytywania zasobow w glownym watku jest rysowany splash
 */
int Splash::initThread( void* ) {

    Property::init( loadLanguages() );
    Resource::load();
    SpriteManager::loadConfig();
    
    SDL_Delay( 10 );
    pInitIsDone = true;

    info("Loading resource is finish");

    return( 0 );
}


