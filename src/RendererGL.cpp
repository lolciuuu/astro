#include "../include/RendererGL.hpp"
#include "../include/Const.hpp"
#include "../include/SpriteManager.hpp"

/** */
RendererGL::RendererGL():
pScreen(NULL), pAtlas( Resource::getSurf("ATLAS") ),
pBackground( Resource::getSurf("BACKGROUND") ),
pMenuBackground( Resource::getSurf("MENU_BACKGROUND")  ), isInit( false )
{
	pBackground_GL = 0;
	pMenuBackground_GL = 0;
	pAtlas_GL = 0;
}

/** Wygenerowanie textur openGL-a */
void RendererGL::init() {
		create_gl( pBackground , &pBackground_GL );
		create_gl( pAtlas, &pAtlas_GL );
		create_gl( pMenuBackground , &pMenuBackground_GL );
}

/** Zamienia SDL_Surface na format openGL-a */
void RendererGL::create_gl(SDL_Surface * surf, GLuint * tex )
{
	GLenum format=0;
	GLint  colors_amount = surf->format->BytesPerPixel;

    if (colors_amount == 4) {
            if (surf->format->Rmask == 0x000000ff)
                    format = GL_RGBA;
            else
                    format = GL_BGRA;
    }
    else if (colors_amount == 3) {
            if (surf->format->Rmask == 0x000000ff)
                    format = GL_RGB;
            else
                    format = GL_BGR;
    }
    else {
        critical("Image is not truecolor");
    }

    glGenTextures( 1, tex );

    glBindTexture( GL_TEXTURE_2D, *tex );

    	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D( GL_TEXTURE_2D, 0, colors_amount, surf->w, surf->h, 0, format, GL_UNSIGNED_BYTE, surf->pixels );
}

/** Wyslanie na ekran zawartosci buforu */
void RendererGL::flip() {
	 SDL_GL_SwapBuffers();

}

/** Czyszczenie ekranu za pomoca GL */
void RendererGL::cleanScreen() {
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glLoadIdentity();
}

/** Rysowanie tla gry za pomoca GL-a */
void RendererGL::drawBackground( bool menu ) {

#ifdef LIGHT_GL
	  glEnable(GL_LIGHTING);
#endif
if( menu )
	glBindTexture(GL_TEXTURE_2D, pMenuBackground_GL );
else
 	glBindTexture(GL_TEXTURE_2D, pBackground_GL );

	  glBegin( GL_QUADS );
	  	glTexCoord2f( 0, 0 );
	  	glVertex2f( 0.f, 0.f  );

	  	glTexCoord2f( 1, 0 );
	  	glVertex2f( pScreen->w, 0.f );

	  	glTexCoord2f( 1, 1 );
	  	glVertex2f( pScreen->w, pScreen->h );

	  	glTexCoord2f( 0, 1 );
	  	glVertex2f( 0.f, pScreen->h);
	  glEnd();

#ifdef LIGHT_GL
	  glDisable(GL_LIGHTING);
#endif
}

void RendererGL::draw( GLuint texture, Rect& Dest ) {

	  glBindTexture(GL_TEXTURE_2D, texture );

	  glColor4f(1.0f,1.0f,1.0f,Dest.a );

	  glBegin(GL_QUADS);
		     {
		         glTexCoord2f(0,0);//1
		         glVertex2f( Dest.x, Dest.y );

		         glTexCoord2f( 1, 0 );//2
		         glVertex2f( Dest.x + Dest.w, Dest.y );

	             glTexCoord2f(1, 1);//3
		         glVertex2f( Dest.x + Dest.w , Dest.y + Dest.h );

		         glTexCoord2f(0,1);//4
		         glVertex2f( Dest.x, Dest.y + Dest.h);
		     }
	   glEnd();

	   glColor4f(1.0f,1.0f,1.0f,1.0f );
}

GLuint RendererGL::getSurfaceInGLFormat(SDL_Surface* surface) {
	return get_gl(surface);
}

void RendererGL::draw(GLuint texture, const float& x, const float& y,
		const float& w, const float& h) {

	  glBindTexture(GL_TEXTURE_2D, texture );

	  glBegin(GL_QUADS);
		     {
		         glTexCoord2f(0,0);//1
		         glVertex2f( x, y );

		         glTexCoord2f( 1, 0 );//2
		         glVertex2f( x + w, y );

	             glTexCoord2f(1, 1);//3
		         glVertex2f( x + w , y + h );

		         glTexCoord2f(0,1);//4
		         glVertex2f( x, y + h);
		     }
	   glEnd();
}

/** */
GLuint RendererGL::get_gl(SDL_Surface * surf ) {

	GLenum format=0;
	GLint  colors_amount = surf->format->BytesPerPixel;
	GLuint tex( 0 );

    if (colors_amount == 4) {
            if (surf->format->Rmask == 0x000000ff)
                    format = GL_RGBA;
            else
                    format = GL_BGRA;
    }
    else if (colors_amount == 3) {
            if (surf->format->Rmask == 0x000000ff)
                    format = GL_RGB;
            else
                    format = GL_BGR;
    }
    else {
        critical("Image is not truecolor");
    }

    glGenTextures( 1, &tex );

    glBindTexture( GL_TEXTURE_2D, tex );

    	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D( GL_TEXTURE_2D, 0, colors_amount, surf->w, surf->h, 0, format, GL_UNSIGNED_BYTE, surf->pixels );
    return tex;
}

/** Wypelnianie prostokata podanym kolorem */
void RendererGL::fillRect( Rect& rect ) {
	glDisable( GL_TEXTURE_2D );

  	glColor3f( rect.r, rect.g, rect.b );

  	glBegin(GL_POLYGON);
  	    glVertex2f( rect.x, rect.y ); // bottom left
  	    glVertex2f( rect.x, rect.y + rect.h ); // bottom right...
  	    glVertex2f( rect.x + rect.w, rect.y + rect.h );
  	    glVertex2f( rect.x + rect.w, rect.y );
  	glEnd();

  	glColor3f(1, 1, 1);

    glEnable( GL_TEXTURE_2D );
}

/** Rysowanie fragmetnu atlasu na podanym miejscu i w podanych wymiarach. Polozenie w atlasie
 *  wyciagane jest z Src  */
void RendererGL::draw( Rect& Src, float x, float y, float w, float h ){

 	   glBindTexture(GL_TEXTURE_2D, pAtlas_GL);

 	   const double texture_w = pAtlas->w;    // szerokość atlasu
	   const double texture_h = pAtlas->h;    // wysokość atlasu

	   const double left = Src.x / texture_w;
	   const double right =  left + (Src.w / texture_w );
	   const double bottom =  Src.y / texture_h;
	   const double top =  bottom + (Src.h  / texture_h);

	   glPushMatrix();  {
	     glTranslatef(0, 0, 0);
	     glBegin(GL_QUADS);
	     {
	         glTexCoord2f(right, top);//1
	         glVertex2f( x+w, y+h );

	         glTexCoord2f(left, top);//2
	         glVertex2f( x, y+h );

             glTexCoord2f(left, bottom);//3
	         glVertex2f( x, y );

	         glTexCoord2f(right, bottom);//4
	         glVertex2f( x+w, y );
	     }
	     glEnd();
	   }
	   glPopMatrix();


}

/** Wyswietlanei fragmetnu textury na ekranie. Polozenie na ekranie pochodzi z Dest, a w atlasie z Src */
void RendererGL::draw( Rect& Src, Rect& Dest ){

 	   glBindTexture(GL_TEXTURE_2D, pAtlas_GL);

	   const double texture_w = pAtlas->w;    // szerokość atlasu
	   const double texture_h = pAtlas->h;    // wysokość atlasu

	   const double left = Src.x / texture_w;
	   const double right =  left + (Src.w / texture_w );
	   const double bottom =  Src.y / texture_h;
	   const double top =  bottom + (Src.h  / texture_h);

	   glPushMatrix();  {
	     glTranslatef(0, 0, 0);
	     glBegin(GL_QUADS);
	     {
	         glTexCoord2f(right, top);//1
	         glVertex2f( Dest.x+Dest.w, Dest.y+Dest.h );

	         glTexCoord2f(left, top);//2
	         glVertex2f( Dest.x, Dest.y+Dest.h );

             glTexCoord2f(left, bottom);//3
	         glVertex2f( Dest.x, Dest.y );

	         glTexCoord2f(right, bottom);//4
	         glVertex2f( Dest.x+Dest.w, Dest.y );
	     }
	     glEnd();
	   }
	   glPopMatrix();
}

/** */
void RendererGL::draw( SDL_Surface* surf, Rect& Dest ) {
	draw( get_gl(surf), Dest );
}

/** */
void RendererGL::draw( string Name , float x, float y, float w = -1, float h = -1 ) {

	Sprite sprite = SpriteManager::getInstance()->getSprite( Name );
	Rect Src( sprite.getAtlasX(), sprite.getAtlasY(), sprite.getWidth(), sprite.getHeight() );

	if( w != -1 ) Src.w = w;
	if( h != -1 ) Src.h = h;

		 glBindTexture(GL_TEXTURE_2D, pAtlas_GL);

			   const double texture_w = pAtlas->w;    // szerokość atlasu
			   const double texture_h = pAtlas->h;    // wysokość atlasu

			   const double left = Src.x / texture_w;
			   const double right =  left + (Src.w / texture_w );
			   const double bottom =  Src.y / texture_h;
			   const double top =  bottom + (Src.h  / texture_h);

			   glPushMatrix();  {
			     glTranslatef(0, 0, 0);
			     glBegin(GL_QUADS);
			     {
			         glTexCoord2f(right, top);//1
			         glVertex2f( x+Src.w, y+Src.h );

			         glTexCoord2f(left, top);//2
			         glVertex2f( x, y+Src.h );

		             glTexCoord2f(left, bottom);//3
			         glVertex2f( x, y );

			         glTexCoord2f(right, bottom);//4
			         glVertex2f( x+Src.w, y );
			     }
			     glEnd();
			   }
			   glPopMatrix();
}

/** */
void RendererGL::draw( float x, float y, string Name ) {

	Sprite sprite = SpriteManager::getInstance()->getSprite( Name );
	Rect Src( sprite.getAtlasX(), sprite.getAtlasY(), sprite.getWidth(), sprite.getHeight() );

	 glBindTexture(GL_TEXTURE_2D, pAtlas_GL);

		   const double texture_w = pAtlas->w;    // szerokość atlasu
		   const double texture_h = pAtlas->h;    // wysokość atlasu

		   const double left = Src.x / texture_w;
		   const double right =  left + (Src.w / texture_w );
		   const double bottom =  Src.y / texture_h;
		   const double top =  bottom + (Src.h  / texture_h);

		   glPushMatrix();  {
		     glTranslatef(0, 0, 0);
		     glBegin(GL_QUADS);
		     {
		         glTexCoord2f(right, top);//1
		         glVertex2f( x+Src.w, y+Src.h );

		         glTexCoord2f(left, top);//2
		         glVertex2f( x, y+Src.h );

	             glTexCoord2f(left, bottom);//3
		         glVertex2f( x, y );

		         glTexCoord2f(right, bottom);//4
		         glVertex2f( x+Src.w, y );
		     }
		     glEnd();
		   }
		   glPopMatrix();
}

/** */
void RendererGL::draw( Rect& Dest, string Name ) {

	Sprite sprite = SpriteManager::getInstance()->getSprite( Name );
	Rect Src( sprite.getAtlasX(), sprite.getAtlasY(), sprite.getWidth(), sprite.getHeight() );

	 glBindTexture(GL_TEXTURE_2D, pAtlas_GL);

		   const double texture_w = pAtlas->w;    // szerokość atlasu
		   const double texture_h = pAtlas->h;    // wysokość atlasu

		   const double left = Src.x / texture_w;
		   const double right =  left + (Src.w / texture_w );
		   const double bottom =  Src.y / texture_h;
		   const double top =  bottom + (Src.h  / texture_h);

		   glPushMatrix();  {
		     glTranslatef(0, 0, 0);
		     glBegin(GL_QUADS);
		     {
		         glTexCoord2f(right, top);//1
		         glVertex2f( Dest.x+Dest.w, Dest.y+Dest.h );

		         glTexCoord2f(left, top);//2
		         glVertex2f( Dest.x, Dest.y+Dest.h );

	             glTexCoord2f(left, bottom);//3
		         glVertex2f( Dest.x, Dest.y );

		         glTexCoord2f(right, bottom);//4
		         glVertex2f( Dest.x+Dest.w, Dest.y );
		     }
		     glEnd();
		   }
		   glPopMatrix();

}


