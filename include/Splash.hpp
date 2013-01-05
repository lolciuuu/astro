#ifndef SPLASH_HPP
#define SPLASH_HPP
#include "Headers.hpp"
#include "Property.hpp"
#include "Resource.hpp"
#include "SpriteManager.hpp"
#include "Const.hpp"
#include "Logger.hpp"

/** */
class Splash
{

public:
    Splash();
    virtual ~Splash();
    bool isInitDone() const;
    bool isSplashDone() const;
  
    void startSplash( ushort W, ushort H, SDL_Surface* Screen );
    void endSplash();
    void drawSplash();
    void splashAnimStep();
    
    
    static int initThread( void* ); 

    
protected: 
    static bool pInitIsDone;
    bool pSplashIsDone;
    int pSplashLong;

    SDL_Surface* pSplash;
    GLuint pSplashGL;
    Rect pRectSplash;
    Rect pRectLoad;

    int pCurrentLoop;
    int pSplashLoadLong;
    Uint32 pColor; 
    
    ushort pScreenW;
    ushort pScreenH;
    
    SDL_Surface* pScreen;

    static int pframeRating;
    SDL_TimerID timerFPS;

    Logger logger;
	
};

#endif // SPLASH_HPP
