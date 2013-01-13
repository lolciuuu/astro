#ifndef HEADERS_HPP
#define HEADERS_HPP

// Biblioteka boost
#include <stdexcept>

// standardowe hederki
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <stack>

#include "Util.hpp"

// przelacznik dla trybu debug
#define DEBUG

// LUA
#include <lua5.1/lua.hpp>

extern "C" {
  
  #include <lua5.1/lualib.h>

  // Moduly SDL-a
  #include <SDL/SDL.h>
  #include <SDL/SDL_timer.h>
  #include <SDL/SDL_ttf.h>
  #include <SDL/SDL_image.h>
  #include <SDL/SDL_opengl.h>
}


// Przestrzen nazw obowiazujaca w calym projekcie
namespace Gamespace {

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::fstream;
using std::map;
using std::vector;

typedef vector<string>::iterator vStrIt;


enum FontSize{
	  SMALL,
	  NORMALL,
	  BIG
};

enum GameState {
    MENU,
    PLAY
};

enum MenuState {
    MAIN,
    HIGHSCORE
};

enum PlayerState {
    Stand,
    Run,
    Fly
};

enum EnemyState {
	Left,
	Right
};

struct ColisionSide {
	bool up;
	bool down;
	bool right;
	bool left;

	float pos_Y_px;

	ColisionSide():
	up(false), down(false), right(false),
	left( false ), pos_Y_px( -1 ) { /*...*/ }
};


struct HighscoreItem {
  string name;
  uint points;

  HighscoreItem( string n, string p = "" ) :
  			  name( n ), points( 0 )
  			  {}
  HighscoreItem(): name( "" ),points( 0 )
  			  {}
};


}
using namespace Gamespace;

// Globalne funkcje inline
#include "GlobFun.hpp"

#endif // HEADERS_HPP
