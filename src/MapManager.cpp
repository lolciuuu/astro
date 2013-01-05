#include "MapManager.hpp"
#include "Sprite.hpp"
#include "SpriteManager.hpp"
#include "App.hpp"


// Blok inicjowania zmiennych statycznych
Map *MapManager::pMapMain;
vector<Rect> MapManager::pMap_rects;
uint MapManager::LEVEL_VARIANTS;

/** Tworzy tablice w ktorej znajduja sie wszystkie mozliwe wersje kafelkow mapy */
MapManager::MapManager(): pIsRunMap( false ), pEnemyManager( EnemyManager::getInstance() ) {

	logger.setClassName("MapManager");
	logger.info("Constructor class: MapManager");

    LEVEL_VARIANTS = (uint)Property::getSetting("LEVEL_VARIANTS");

    // dynamicznie stworzenie nazw spritow o konkretnych numerach
    for(uint i = 0; i <= LEVEL_VARIANTS; ++i) {
        std::ostringstream ss;
        ss << i;
        string ID(ss.str());
        Sprite spriteTmp = SpriteManager::getInstance()->getSprite("MAP_" + ID);
        pMap_rects.push_back(spriteTmp.getRect());
    }
    
    pEnemyManager->setHorizontalTilesAmount( pMapMain->getAmountEntityHorizontal() );
    pEnemyManager->setTilesSize( pMapMain->getSize() );

    pMapMain->enableCheckColision();
  
}

/** */
void MapManager::update(const float& dt) {
  if( pIsRunMap == false ) return;
    pMapMain->update( dt );

    if( pMapMain->nextMeter() ) LiveBar::nextMeter();

    pEnemyManager->setCurrentX( pMapMain->getPos_X() );
    pEnemyManager->setOffsetX( pMapMain->getOffsetX() );
}


/** */
void MapManager::draw() {
    pMapMain->draw();
}

/** Metoda wczytuje mape do tablicy dwuwymiarowej,
 * levelNo - ID mapy w ustawieniach, potrzebny do okreslenia rozmiaru kafelka
 */
Map* MapManager::loadMapFromFile(string fileName, short levelNo) {
  
    Map* result;
    std::fstream mapFile;
    mapFile.open( fileName.c_str(), std::ios::in);

    uint row(0);
    uint column(0);

   EnemyManager* enemyManager = EnemyManager::getInstance();

    if(mapFile.is_open()) {

    	info("Load map from file | start");

        // pobranie wymiarow mapy
        mapFile >> row;
        mapFile >> column;

        short **map = new short*[column];
        for(uint i = 0; i < column; ++i)
            map[i] = new short[row];

        // wczytanie mapy
        vector< vector<short> > map1;
        for(uint i = 0; i < row; ++i) {
            vector<short> v_tmp;
            for(uint j = 0; j < column; ++j) {
                short shortTmp;
                mapFile >> shortTmp;

                // Wczytano potworka
                if( isEnemy(shortTmp) ) {
                	enemyManager->addEnemy( i, j, shortTmp );
                	map[j][i] = -1;
                	continue;
                }
                else
                	map[j][i] = shortTmp;
            }
        }

        string settingsName( "MAP_LEVEL_" + toString<short>(levelNo) + "_SIZE" );
        result = new Map( map,(int)Property::getSetting(settingsName),row,column);

        mapFile.close();
    	info("Load map from file | end");
        return( result );
	
    }
    else {
      critical("Can`t open file: " + fileName );
      throw std::runtime_error("MapManager::loadMapFromFile");
    }
}

/** Wczytanie wszystkich map. Metoda wolana podczas ladowania zasobow, poza glownym watkiem */
void MapManager::load() {
  pMapMain = loadMapFromFile( "data/level.lua", 1 );  
  pMapMain->setSpeed( Property::getSetting("MAP_LEVEL_1_SPEED") );
}

/** */
void MapManager::reset() {
  pMapMain->reset();
}

/** */ 
short MapManager::checkColision( const short& Player_x,const short& Player_y, ColisionSide& cSide ) {
   return( pMapMain->checkColision( Player_x, Player_y, cSide ) );
}


