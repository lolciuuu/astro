#ifndef APP_HPP
#define APP_HPP
#include "Headers.hpp"
#include "Game.hpp"
#include "Property.hpp"
#include "Resource.hpp"
#include "SpriteManager.hpp"
#include "Splash.hpp"
#include "Logger.hpp"

/**  Glowna klasa aplikacji */
class App: public Splash
{
public:
    App();
    virtual ~App();

    void init();
    void run();
    
    void startSplash() { Splash::startSplash(pScreen_w, pScreen_h, pScreen); }

    static Uint32 FPS_callbackTimer(Uint32 interval, void *param);
    
    /** Informacje o wymiarach ekranu dostepne w calej aplikacji */
    static ushort getScreenHeight() { return( (ushort)pScreen->h ); }
    static ushort getScreenWidth() { return( (ushort)pScreen->w ); }

    /** Dostep do glownej powierzchni ma tylko klasa Renderer */
    static SDL_Surface* getMainSurface() {
        return( pScreen );
    }
    
private:
    void processEvent();
    void FPS_show();
    void initVideoSDL();
    void initVideoGL();

private:
    Logger logger;

    /** Glowny surface i jego wymiary */
    static SDL_Surface* pScreen;    
    static ushort pScreen_w;
    static ushort pScreen_h;
    
    /** Najwazniejsze elementy klasy */
    bool pIsDone;
    Game* pGame;
    Renderer* pRenderer;
    SDL_Event pEvent;

    SDL_Surface* pIcon;

};

#endif // APP_HPP
