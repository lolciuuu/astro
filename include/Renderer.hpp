#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "Headers.hpp"
#include "Property.hpp"
#include "RendererGL.hpp"

/** Rozszerza klase rysujaca do singletona */
class Renderer : public RendererGL
{
public:
    static Renderer* getInstance(){
      if( pInstance == NULL ){
    	  pInstance = new Renderer();
    	  return( pInstance );
      }
      else return( pInstance );
    }
  
  void setScreenHeight( int H ){ pScreenRect.h = H;}
  void setScreenWidth( int W ){ pScreenRect.w = W;}

  short getScreenHeight() const { return pScreen->h; }
  short getScreenWidth() const { return pScreen->w; }

  Uint32 getRGB( short R, short G, short B ) { return( SDL_MapRGB( pScreen->format,R,G,B) ); }


private:
    Renderer();

  
private:
    static Renderer* pInstance;

};

#endif // RENDERER_HPP
