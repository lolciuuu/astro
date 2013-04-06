#include "../include/Enemy.hpp"
#include "../include/SpriteManager.hpp"

Enemy::Enemy(ushort R, ushort C, ushort id ):
row( R ), column( C ), ID( id ), pRect() , pOffset( 0.0f ), pState( EnemyState::Stop ),
pSprManager( SpriteManager::getInstance() )
{
	pRect.w = Property::getSetting("TILES_SIZE");
	pRect.h = Property::getSetting("TILES_SIZE");

}

void Enemy::draw() {
//@TODO usunac liczbe magiczna i sie zastanowic dlaczego tutaj jesdt
	switch( pState ) {
		case( EnemyState::Right ):{
			pSprManager->getSprite( "M1_R" ).draw( pRect.x + pOffset, pRect.y+13 );
			break;
		}
		case( EnemyState::Left ): {
			pSprManager->getSprite( "M1_L" ).draw( pRect.x + pOffset, pRect.y+13 );
			break;
		}
		case( EnemyState::Stop ): {
			pSprManager->getSprite( "M1_S" ).draw( pRect.x + pOffset, pRect.y+13 );
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
		pOffset += dt*500;
	}
	else {
		pOffset -= dt*500;
	}

}
