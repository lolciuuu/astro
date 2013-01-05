#ifndef SPRITEMANAGER_HPP
#define SPRITEMANAGER_HPP
#include "Headers.hpp"
#include "Sprite.hpp"

class SpriteManager
{
public:
  static void loadConfig();
  static SpriteManager* getInstance();
    
  Sprite getSprite( string Name );
  
private:
   SpriteManager(){ /* Empty */ }
   static int addSprite( lua_State* L );
   bool contain( string Name );
    
private:
  map<string,Sprite> pSprites;
  static SpriteManager* pInstance;
  
};

#endif // SPRITEMANAGER_HPP
