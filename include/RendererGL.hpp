#ifndef RENDERERGL_HPP
#define RENDERERGL_HPP
#include "Headers.hpp"
#include "Resource.hpp"


class RendererGL {
public:
	RendererGL();

	virtual ~RendererGL(){}

	virtual void draw( Rect& Src, Rect& Dest );

	virtual void draw( SDL_Surface* surf, Rect& where );

	virtual void draw( GLuint, Rect& where );

	virtual void draw( GLuint,const float& x, const float& y,const float& w,const float& h );

	virtual void fillRect( Rect& rect );

	virtual void draw( Rect& Src, float x, float y, float w, float h );

	virtual void draw( Rect& Src, string Name );

	virtual void draw( float x, float y, string Name );

	virtual void draw( string Name , float x, float y, float w, float h );

	virtual void drawBackground( bool menu );

	void flip();

	void cleanScreen();

	void init();

	static GLuint getSurfaceInGLFormat( SDL_Surface * surface );
  
protected:
    SDL_Surface* pScreen;
    SDL_Surface* pAtlas;
    SDL_Surface* pBackground;
    SDL_Surface* pMenuBackground;

    Rect pScreenRect;

private:
	void create_gl(SDL_Surface * surface, GLuint * tex );
	static GLuint get_gl(SDL_Surface * surface );


private:
	unsigned pAtlas_GL;
	unsigned pBackground_GL;
	unsigned pMenuBackground_GL;
	bool isInit;
  
};

#endif
