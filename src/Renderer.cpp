#include "../include/Renderer.hpp"
#include "App.hpp"

/// Inicjacjowanie zmiennych statycznych
  Renderer* Renderer::pInstance;
//END

/** Wyciaga adres glownej powierzchni po ktorej rysuje */
Renderer::Renderer()
{  
  info("Constructor class: RENDERER");  


  pScreen = App::getMainSurface();

  if( pScreen == NULL ){
    error("NULL pointer");
    throw std::runtime_error("Renderer::Renderer()");
  }  
  
  pScreenRect.x = 0;
  pScreenRect.y = 0;
  pScreenRect.w = pScreen->w;
  pScreenRect.h = pScreen->h;
  
}




