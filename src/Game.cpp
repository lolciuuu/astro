#include "../include/Game.hpp"
#include "Writer.hpp"

//Init zmiennych statycznych
GameState Game::pGameState;
Game* Game::pGameInstance;
//END

/** */
Game::Game(): pIsDone( false ), logger("Game")
{
  string methodName = "Game";
  logger.methodStart( methodName );
  
  // Zabezpieczenie przed wielokrot
  if( pGameInstance == NULL ) {
      pGameInstance = this;    
  }
  else {
	  logger.critical("Game::Game() pGameInstance alerady initialized");
      throw std::runtime_error("Game::Game()");
  }
  
  // Definiowanie tla aplikacji
  pColorBackgroundPlay =  pRendererPtr->getRGB( 0, 40, 86 );
  
  logger.methodEnd( methodName );

}


/** Kontrola ktora klasa ma rysowac na ekranie */
void Game::draw() {

    switch ( pGameState ) {
    	case( Gamespace::PLAY ): {
    		pPlay.draw();
 			break;
     	 }
    	case( Gamespace::MENU ): {
        	pMenu.draw();
        	break;
    	}
    };
}

void Game::pressedShift() {

    switch ( pGameState ) {
    	case( Gamespace::PLAY ): {
    		pPlay.pressedShift();
    		break;
    	}
    	default: {
          break;
       }
    };
}

/** */
void Game::update(const float& dt ) {
  
    switch ( pGameState ) {
    	case( Gamespace::PLAY ): {
    		pPlay.update( dt );
    		break;
    	}
    	case( Gamespace::MENU ): {

    	  if( !LiveBar::isALive() ) {  // Jezeli gracz nie zyje to wylaczam resume
    		  pMenu.blockItem(0);
    	  }
          pIsDone = pMenu.update( dt );	// menu decyduje o wyjsciu z gry
          break;

      }
      default: {
          logger.warring("Unknown value of GameState [Method: Game::update(double) ]");
          break;
      }
    };
}

/** */
void Game::pressedReturn() {

    if ( pGameState == Gamespace::MENU ) {
        pMenu.pressedReturn();
    }
}


/** */
void Game::pressedEsc() {

    switch ( pGameState ) {

    case( Gamespace::MENU ): {
        pMenu.pressedEsc();
        break;
    }
    case( Gamespace::PLAY ): {
    	if( pPlay.isCanStop() ) { // Wyjsc do menu mozna wtedy gdy play pozwala na to
    		pPlay.goToMenu();
    		pGameState = Gamespace::MENU;
    	}
		break;
	 }
    };
}

void Game::pressedBackspace() {
	if( pGameState == Gamespace::PLAY )
		pPlay.pressedBackspace();
}

/**  */
void Game::pressedChar(char Char) {
	if( pGameState == Gamespace::PLAY )
		pPlay.pressedChar( Char );

}

/** */
void Game::pressedLeft() {

    if ( pGameState == Gamespace::MENU ) {
        pMenu.pressedLeft();
    }

}


/** */
void Game::pressedRight() {

    if ( pGameState == Gamespace::MENU ) {
        pMenu.pressedRight();
    }

}

/** */
void Game::pressedUp() {
    if ( pGameState == Gamespace::MENU ) {
        pMenu.pressedUp();
    }
}


/** */
void Game::pressedDown() {

    if ( pGameState == Gamespace::MENU ) {
        pMenu.pressedDown();
    }

}


/**  */
void Game::SpaceDown() {
 
  switch ( pGameState ) {
    case( Gamespace::PLAY ): {
	pPlay.SpaceDown();
        break;
    }
    case( Gamespace::MENU ): {
        break;
    }
  }

}

/**  */
void Game::SpaceUp() {
 
  switch ( pGameState ) {
    case( Gamespace::PLAY ): {
	pPlay.SpaceUp();
        break;
    }
    case( Gamespace::MENU ): {
        break;
    }
  }

}

void Game::pressedCtrl() {

	  if( Gamespace::PLAY ) {
		pPlay.useBonus();
	  }
}

/** Resetowanie gry */
void Game::reset(){
  logger.info("Restaring game");
  pPlay.resetGame();

}


/** Metoda statyczny wywolujaca reset na instancji obiektu  */
void Game::resetGame(){
  pGameInstance->reset();  
}


