#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "Headers.hpp"
#include "StandardReferences.hpp"

/** Klasa przewijalnego tla w grze */
class Background : public StandardReferences {
public:

	Background();

	void update( const float& dt,const float& player_y );

	void init();

	void draw();

	void reset();

private:
	GLuint pBackgroungImg;

	Rect pFirst;
	Rect pSecond;
	float pPLayerY;
	SDL_Surface* pBackSurf;
};

#endif
