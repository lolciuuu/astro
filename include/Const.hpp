#ifndef CONST_HPP
#define CONST_HPP

// Zmienne wlaczajaca tryb debugu

#define FULL_SCREEN_FLAG

#define RENDER_GL
#define LIGHT_GL

#define IMMORTAL

#define VERSION " build 0.2 "

#ifdef DEBUG
  // Zmienna wlaczajaca pokazywanie ilosci fps-ow na pasku
  const bool SHOW_FPS( true  );
#endif

const unsigned short WIDHT( 1300 );
const unsigned short HEIGHT( 800 );

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


#endif
