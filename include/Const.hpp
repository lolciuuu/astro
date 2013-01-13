#ifndef CONST_HPP
#define CONST_HPP

// Zmienne wlaczajaca tryb debugu

#define FULL_SCREEN_FLAG

#define RENDER_GL
#define LIGHT_GL

//#define IMMORTAL

#define TEXTURE

#define VERSION " build 0.3 "

#ifdef DEBUG
  // Zmienna wlaczajaca pokazywanie ilosci fps-ow na pasku
  const bool SHOW_FPS( true  );
#endif

const unsigned short WIDHT( 800 );
const unsigned short HEIGHT( 600 );

const float SPLASH_TIME( 1 );

// Ustawienia wymiarow levelu musza byc zgodnie z AstroDesignerem
const unsigned int LEVEL_WIDHT( 30000 );
const unsigned int LEVEL_HEIGHT( 25 );

// Maksymalne dopuszczalne wymiary ektanu
const ushort MAX_SCREEN_HEIGHT( 1080 );
const ushort MAX_SCREEN_WIDTH( 1920 );

const ushort MIN_SCREEN_WIDTH(  800 );
const ushort MIN_SCREEN_HEIGHT( 600 );

const ushort COLISION_WITH_ENEMY( 10000 );

const SDL_Color BLACK_FONT_COLOR( {8,16,29} );
const SDL_Color WHITE_FONT_COLOR( { 240, 240, 250 } );
const SDL_Color YELLOW_FONT_COLOR( { 235, 190, 0 } );

#endif
