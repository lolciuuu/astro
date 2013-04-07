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

/** Shift odpowiada za zatrzymanie rychu gracza. tzn. na ulamek sekundy przestaje spadac badz wznosic sie do gory */
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

/** aktualizacja gry */
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

/** Obsluga nacisniecia entera */
void Game::pressedReturn() {

    if ( pGameState == Gamespace::MENU ) {
        pMenu.pressedReturn();
    }
    else if( pGameState == Gamespace::PLAY ) {
    	if(  pPlay.goToMenu() ) {
    		pGameState = Gamespace::MENU;
        	pSoundManagerPtr->playMenuMusic();
    	}
    }
}


/** nacisniecie escape */
void Game::pressedEsc() {

	logger.info("ESC pressed");

    switch ( pGameState ) {

    case( Gamespace::MENU ): {
        pMenu.pressedEsc();
        break;
    }
    case( Gamespace::PLAY ): {
    	if( pPlay.isCanStop() ) { // Wyjsc do menu mozna wtedy gdy play pozwala na to
    		pPlay.goToMenu();
        	pSoundManagerPtr->playMenuMusic();
    		pGameState = Gamespace::MENU;
    	}
		break;
	 }
    };
}

/** uklaiwsz backscpace - na potrzeby usuwania znaczkow podczas ich wpisywania do highscore  */
void Game::pressedBackspace() {
	if( pGameState == Gamespace::PLAY )
		pPlay.pressedBackspace();
}

/** obsluga nacisniecia jakielkowiek literki */
void Game::pressedChar(char Char) {
	if( pGameState == Gamespace::PLAY )
		pPlay.pressedChar( Char );

}

/** strzalka w lewo */
void Game::pressedLeft() {

    if ( pGameState == Gamespace::MENU ) {
        pMenu.pressedLeft();
    }

}


/** strzalka w prawo */
void Game::pressedRight() {

    if ( pGameState == Gamespace::MENU ) {
        pMenu.pressedRight();
    }

}

/** strzalka do gory */
void Game::pressedUp() {
    if ( pGameState == Gamespace::MENU ) {
        pMenu.pressedUp();
    }
}


/** strzalka w dol */
void Game::pressedDown() {

    if ( pGameState == Gamespace::MENU ) {
        pMenu.pressedDown();
    }

}


/**  wcisniecie spacji */
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


/** puszczenie klaiwasza spacja */
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


/** uzycie prawego kontrola (doladowanie zycia gracza) */
void Game::pressedCtrl() {

	  if( Gamespace::PLAY ) {
		pPlay.useBonus();
	  }
}


/** Resetowanie gry */
void Game::reset(){
  logger.info("Restaring game");
  pPlay.resetGame();
  pMenu.resetMenu();

}


/** Metoda statyczny wywolujaca reset na instancji obiektu  */
void Game::resetGame(){
  pGameInstance->reset();  
}


