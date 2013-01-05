#ifndef PLAY_HPP
#define PLAY_HPP

#include "Player.hpp"
#include "MapManager.hpp"
#include "Highscore.hpp"
#include "LiveBar.hpp"
#include "SpriteManager.hpp"
#include "EnemyManager.hpp"
#include "StandardReferences.hpp"
#include "Background.hpp"

/** Obsluga taki jednostek jak: mapa, gracz, pasek zycia, highscore...stan gry*/
class Play: StandardReferences {
public:
    Play();
    ~Play();

    void resetGame();
    
    void update (const float& dt );
    void draw();
    
    bool isCanStop() const { return( pIsCanStop ); } // czy mozna wyjsc z gry do menu

    void SpaceUp();
    void SpaceDown();

    void pressedBackspace();
  
    void pressedShift();
    void pressedChar(char Char);

    void goToMenu();

    void useBonus();

private:
    Player pPlayer;
    
    bool pIsCanStop;
    float pElapsedTime;
    
    MapManager pMap;
    Highscore pHighScore;
    LiveBar pLiveBar;
    float PLAYER_SLEEP_TIME;
    ushort PLAYER_SIZE;

    EnemyManager* pEnemyManager;
    
    Sprite pCount;
    Background pBackground;

};

#endif // PLAY_HPP
