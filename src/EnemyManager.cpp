#include "../include/EnemyManager.hpp"
#include "../include/App.hpp"
#include "../include/Property.hpp"

EnemyManager* EnemyManager::pInstance;

EnemyManager* EnemyManager::getInstance() {
    if( pInstance == NULL ) {
    	pInstance = new EnemyManager();
    	return pInstance;
    }
	return pInstance;
}

EnemyManager::EnemyManager():pLastEnemy( 0 ),pCurrentX( 0 ), pOffsetX( 0.0f ),
pTilesSize( 0.0f ), pHorizontalTilesAmount( 0 ), logger("EnemyManager")
{
	logger.setClassName("EnemyManager");
}

/** Dodanie nowego enmy - row i column to kolumna i wiersz na macierzy reprezentujacej mape. */
void EnemyManager::addEnemy(ushort R, ushort C,ushort ID) {
	pEnemyList.push_back( Enemy(R,C,ID) );
}

/** */
void EnemyManager::update( const float& dt ) {
	for( uint i = pLastEnemy; i<pEnemyList.size(); ++i ) {

		//@TODO optymalizacja
		if( pEnemyList[i].getRow() < pCurrentX+(App::getScreenWidth()/pTilesSize) ) {
			pEnemyList[i].update( dt );
		}
		else break;
	}
}

/** */
void EnemyManager::draw() {

	while(  pEnemyList[pLastEnemy].getColumn() < pCurrentX  ) {
			++pLastEnemy;
	}

	for( uint i = pLastEnemy; i<pEnemyList.size(); ++i ) {

		//@TODO optymalizacja
		if( pEnemyList[i].getRow() < pCurrentX+(App::getScreenWidth()/pTilesSize) ) {
			pEnemyList[i].setPosX( ( pEnemyList[i].getColumn() - pCurrentX )*pTilesSize - pOffsetX );
			pEnemyList[i].setPosY( ( ( pEnemyList[i].getRow() + 3 ) * pTilesSize ) + 4 );
			pEnemyList[i].draw();
		}
		else break;
	}

}

bool EnemyManager::isColidate( Rect rect ) {

	for( uint i = pLastEnemy; i<pEnemyList.size(); ++i ) {

		//@TODO optymalizacja
		if( pEnemyList[i].getRow() < pCurrentX+(App::getScreenWidth()/pTilesSize) ) {
			if( pEnemyList[i].isColidate( rect ) )
				return true;
		}
		else break;
	}

	return false;
}

void EnemyManager::reset() {
	pCurrentX = 0;
	pLastEnemy = 0;
}
