/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2012  <copyright holder> <email>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "../include/SpriteManager.hpp"

/** @note Zainicjowanie jedynej instancji obiektu. Pamiec jest automatycznie czyszczona
 *  dzieki uzyciu inteligentnego wskaznika z biblioteki boost	
 */
SpriteManager* SpriteManager::pInstance(NULL);


/** Metoda jest uruchamiana z poziomu skryptu LUA. Sprawdzana jest ilosc
 *  przyslanych parametrow ze skryptu, jezeli ta ilosc jest poprawna wtedy
 *  zostaje utworzony sprite w pamieci gry
 *
 * @return 0
 * @param lua_State* : wskaznik na maszyne wirtualna LUA, ktora uzywa tej metody
 */
int SpriteManager::addSprite( lua_State* L ) {


    if ( lua_gettop(L) == 9 ) {

        string key( lua_tostring(L,1) );
        short width( lua_tointeger(L,2) );
        short height( lua_tointeger(L,3) );
        short atlas_pos_x( lua_tointeger(L,4) );
        short atlas_pos_y( lua_tointeger(L,5) );
        short level( lua_tointeger(L,6) );
        float frame_time( lua_tonumber(L,7) );
        short frame_count( lua_tointeger(L,8) );
        bool loop( lua_toboolean(L,9) );

        SpriteConfig spriteConf( 100,100,width,height,atlas_pos_x,atlas_pos_y,frame_time,frame_count,level,loop);
        SpriteManager::getInstance()->pSprites.insert( std::pair<string,Sprite>( key, Sprite( spriteConf ) ));

    }
    else {
        critical("Lua:addSprite wrong parameters number");
        throw std::runtime_error("SpriteManager::addSprite");
    }

    return 0;
}



/** Metoda uruchamia skrypt lua, ktory dodaje wszystkie informacje
 *  o spritach. W skrypcie dostepna jest metoda cxx_addSprite
 * @param void
 * @return void
 */
void SpriteManager::loadConfig() {

    lua_State* L = lua_open();
    luaL_openlibs(L);

    // Rejestracja metody ktora jest wywolywna ze skryptu
    lua_register( L, "cxx_addSprite", SpriteManager::addSprite );

    //Wolanie skryptu
    if ( luaL_dofile( L, "data/sprite_config.lua" ) != 0 ) {
        critical(lua_tostring( L, -1 ));
        throw std::runtime_error("SpriteManager::loadConfig");
    }

    lua_close(L);
}


/** Metoda implementuje singleton
 *  @return SpriteManager& : referencja do jedynej instancji tej klasy
 *  @param void
 */
SpriteManager* SpriteManager::getInstance()
{
	if( pInstance == NULL ) {
		pInstance = new SpriteManager();
		return pInstance;
	}
	else {
		return pInstance;
	}
}


/** Metoda sprawdza czy istnieje sprite o podanej nazwie
 */
bool SpriteManager::contain( string key ){
    bool isFound = pSprites.find( key ) != pSprites.end();
    return ( isFound ? true : false );
}


/** Metoda zwraca sprita o podanej nazwie
 * @throw std::runtime_error const char* : nazwa metody
 */
Sprite SpriteManager::getSprite( string Name ){
  if( contain(Name) ){
    return pSprites.find( Name )->second;
  }
  else{
	 cout<<pSprites.size();
    critical("Not found sprite:" + Name);
    throw std::runtime_error("SpriteManager::getSprite");
   }  
}









