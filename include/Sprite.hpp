#ifndef SPRITE_HPP
#define SPRITE_HPP
#include "Spriteconfig.hpp"
#include "Renderer.hpp"
#include "StandardReferences.hpp"

class Sprite : StandardReferences
{

public:
    Sprite( SpriteConfig Config );
    
    void draw();
    void draw( float pos_x, float pos_y );
    void draw( float pos_x, float pos_y, float w, float h );

    void update( float dt );
    
    short getX() const { return pData.pos_x; }
    short getY() const { return pData.pos_y; }
    
    short getAtlasX() const { return pData.atlas_x; }
    short getAtlasY() const { return pData.atlas_y; }

    short getWidth() const { return pData.width; }
    short getHeight() const { return pData.height; }

    void setX( float X ) { pData.pos_x = X; }
    void setY( float Y ) { pData.pos_y = Y; }
    
    Rect getRect() const;
    
    void centered();
    
    void reset() { pCurentFrame = 0; pCurentFrameDuration = 0.0F; }
    
private:
  
  
private:
    SpriteConfig pData;
    ushort pCurentFrame;
    float pCurentFrameDuration;

    Rect pSrc;
    Rect pDes; 
};

#endif // SPRITE_HPP
