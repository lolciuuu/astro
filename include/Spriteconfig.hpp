#ifndef SPRITECONFIG_HPP
#define SPRITECONFIG_HPP
#include "Headers.hpp"

/** Struktura przechowujaca wszystkie informacje o Sprite */
struct SpriteConfig {

public:
  
  SpriteConfig(short X, short Y, short W, short H, short AX, short AY, float FT, short FC, ushort L, bool R = true ):
  pos_x( X ), pos_y( Y ), width( W ), height( H ), atlas_x( AX ), atlas_y( AY ), frame_duration_time( FT ),
  frame_count( FC ), level( L ), loop( R ){}

  short pos_x;
  short pos_y;
  
  short width;
  short height;
  
  short atlas_x;
  short atlas_y;
  
  float frame_duration_time;
  short frame_count;
  
  ushort level;
  bool loop;   
  
};

#endif
