#include "../include/Enemy.hpp"
#include "../include/SpriteManager.hpp"

Enemy::Enemy(ushort R, ushort C, ushort id ):
row( R ), column( C ), ID( id ), pRect() , pOffset( 0.0f ), pState( EnemyState::Right ),
pSprManager( SpriteManager::getInstance() )
{
	pRect.w = Property::getSetting("TILES_SIZE");
	pRect.h = Property::getSetting("TILES_SIZE");

}

void Enemy::draw() {
//@TODO usunac liczbe magiczna i sie zastanowic dlaczego tutaj jesdt
	switch( pState ) {
		case( EnemyState::Right ):{
			pSprManager->getSprite( "MAP_40" ).draw( pRect.x + pOffset, pRect.y+15 );
			break;
		}
		case( EnemyState::Left ): {
			pSprManager->getSprite( "MAP_40" ).draw( pRect.x + pOffset, pRect.y+15 );
			break;
		}
	}
}

void Enemy::update(const float& dt) {


	if( pOffset <= 0 )
		pState = EnemyState::Right;
	else if( pOffset > 100 )
		pState = EnemyState::Left;

	if( pState == EnemyState::Right ) {
		pOffset += dt*1000;
	}
	else {
		pOffset -= dt*1000;
	}

}
