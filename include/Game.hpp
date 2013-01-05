#ifndef GAME_HPP
#define GAME_HPP

#include "Headers.hpp"
#include "Play.hpp"
#include "Menu.hpp"
#include "StandardReferences.hpp"
#include "Logger.hpp"

/** Klasa jest singletonem, konstruktor zawiera zabezpieczenie przed wielokrotnym utworzeniem obiektu */
class Game : StandardReferences 
{
public:  
  Game();
  
  void update(const float& dt); 
  void draw();  
  bool isDone()const{ return pIsDone; }  
 
  static void setGameState( GameState newState ){ pGameState = newState; }
  static void resetGame();
  
  void pressedRight();
  void pressedLeft();
  void pressedDown();
  void pressedUp();
  void pressedEsc();
  void pressedReturn();
  void pressedBackspace();
  void pressedCtrl();

  void pressedShift();

  void SpaceUp();
  void SpaceDown();

  void pressedChar(char);
	
private:
  void reset();
  
private:
  bool pIsDone;
  Play pPlay;
  Menu pMenu;
  
  static GameState pGameState;
  static Game* pGameInstance;

  Uint32 pColorBackgroundPlay;  

  Logger logger;
};

#endif // GAME_HPP
