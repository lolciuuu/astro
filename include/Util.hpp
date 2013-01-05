#ifndef UTIL_HPP
#define UTIL_HPP
#include <SDL/SDL.h>

/** Struktura zastepujaca SDL_Rect. Jest lepsza od wersji SDL-a poniewaz operuje
 * na liczba zmienno przecinkowych co jest potrzebne do openGL-a */
struct Rect {
public:
	// polozenie
	float x;
	float y;

	//wymiary
	float w;
	float h;

	// kolor dla SDL
	Uint32 color;

	// kolor dla GL
	float r;
	float g;
	float b;
	float a;

	/** Domyslny konstrukto zerujacy zmienne */
	Rect(): x(0.0f), y(0.0f), w(0.0f), h(0.0f), color(0),
			r(0.0f), g(0.0f), b(0.0f), a(1.0f)
			{ /** EMPTY */ }

	/** Wymagane podanie polozenia, opcjonalne wymiary i kolor */
	Rect( float X, float Y, float W=0.0f, float H=0.0f, Uint32 Color=0 ) :
			x(X), y(Y), w(W), h(H), color(Color),
			r(0.0f), g(0.0f), b(0.0f), a(1.0f)
			{ /** EMPTY */ }

	bool isColidate( Rect rct ) {
		if (!(x >= (rct.x + rct.w )	|| x + w <= rct.x
			|| y + h <= rct.y || y >= rct.y + rct.h ) )
			return true;
		return false;
	}

};

#endif
