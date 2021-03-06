#include "../include/Menu.hpp"
#include "App.hpp"
#include "Game.hpp"

/** Tutaj odbywa sie tworzenie wszystckich elementow glownego menu
 * pCurrentItem : domyslnie 1, bo 0 to resume game i przy starcie jest nie aktywne
 */
Menu::Menu() : pIsDone ( false ),pMenuState ( Gamespace::MAIN ), pCurrentItem ( 1 ), logger("Menu"),
pAboutImg( 0U ), pExitIco(SpriteManager::getInstance()->getSprite("CLOSE") )
{
  logger.info("Constructor class: MENU");
   
	exit_x = pScreenWidth - pScreenWidth * 0.2f;
	exit_y = pScreenHeight - pScreenHeight * 0.2f;


    ushort pos_y = pScreenHeight * 0.4;
    ushort pos_x = ( pScreenWidth * 0.5 ) + 150;
    ushort item_space = App::getScreenHeight() * 0.05;

    Rect whereSpriteRect;
    whereSpriteRect.x = ( App::getScreenWidth()*0.5 ) - Property::getSetting("MENU_SPRITE_SIZE");
    whereSpriteRect.y = ( App::getScreenHeight()*0.80 );

    
    /** Wpis w menu:  -- Return -- */
    MenuItem resumeGameItem ( Sprite(SpriteManager::getInstance()->getSprite("NEW_GAME") ),
    						  Property::get( "RESUME_GAME" ),whereSpriteRect );
    {
         resumeGameItem.setActive ( false );
         string title = Property::get ( "RESUME_GAME_DESC" );
         resumeGameItem.setDescription ( title );
         Rect rectName( pos_x, pos_y);
         resumeGameItem.setRectName ( rectName );
         whereSpriteRect.x  =(pScreenWidth*0.5) - ((pWriterPtr->getTextWidth( title ) *0.5));
         resumeGameItem.setRectDesc( whereSpriteRect );
         pos_y += item_space;
    }

    /** Wpis w menu:  -- New Game -- */
    MenuItem playGameItem ( Sprite(SpriteManager::getInstance()->getSprite("NEW_GAME") ) ,
			  	  	  	  	Property::get ("NEW_GAME"), whereSpriteRect );
    {
    	string title = Property::get ( "NEW_GAME_DESC" );
        playGameItem.setDescription ( title );
        playGameItem.setSelected ( true );
        Rect rectName( pos_x, pos_y);
        playGameItem.setRectName ( rectName );
        whereSpriteRect.x  =(pScreenWidth*0.5) - ((pWriterPtr->getTextWidth( title ) *0.5 ));
        playGameItem.setRectDesc( whereSpriteRect );
        pos_y += item_space;
    }
   

    /** Wpis w menu:  -- HighScore -- */
    MenuItem highGameItem ( Sprite(SpriteManager::getInstance()->getSprite("NEW_GAME") ),
    		 Property::get ( "HIGH_GAME" ),whereSpriteRect );
    {
    	string title =  Property::get ( "HIGH_GAME" );
        highGameItem.setDescription (title );
        Rect rectName( pos_x, pos_y);
        highGameItem.setRectName ( rectName );
        whereSpriteRect.x  =(pScreenWidth*0.5) - ( (pWriterPtr->getTextWidth( title ) *0.5 ));
        highGameItem.setRectDesc( whereSpriteRect );
        pos_y += item_space;
    }
  
    /** Wpis w menu:  -- About -- */
    MenuItem AboutGameItem ( Sprite(SpriteManager::getInstance()->getSprite("NEW_GAME")  ),
    		 Property::get ( "ABOUT_GAME" ),whereSpriteRect );
    {
       string title =  Property::get ( "ABOUT_GAME_DESC" );
       AboutGameItem.setDescription ( title );
       Rect rectName( pos_x, pos_y);
       AboutGameItem.setRectName ( rectName );
       whereSpriteRect.x  =(pScreenWidth*0.5) - ( (pWriterPtr->getTextWidth( title ) *0.5) );
       AboutGameItem.setRectDesc( whereSpriteRect );
       pos_y += item_space;
    }
      
    /** Wpis w menu:  -- Exit -- */
    MenuItem exitItem ( Sprite(SpriteManager::getInstance()->getSprite("NEW_GAME") ),
    		 Property::get ( "EXIT_GAME" ),whereSpriteRect );
    {
    	string title =  Property::get ( "EXIT_GAME_DESC" );
        exitItem.setDescription ( title);
        Rect rectName( pos_x, pos_y);
        whereSpriteRect.x  =(pScreenWidth*0.5) - (pWriterPtr->getTextWidth( title ) *0.5);
        exitItem.setRectDesc( whereSpriteRect );
        exitItem.setRectName ( rectName );
    }
    
    /** Dodanie wszystckich wpisow w okreslonej kolejnosci */
    pMainMenuItem.push_back ( resumeGameItem );
    pMainMenuItem.push_back ( playGameItem );
    pMainMenuItem.push_back ( highGameItem );
    pMainMenuItem.push_back ( AboutGameItem );
    pMainMenuItem.push_back ( exitItem );
    
}


/** Aktualizacja menu */
bool Menu::update (const float& dt ) {

    switch ( pMenuState ) {

    	case ( MAIN ) : {
    		pMainMenuItem[ pCurrentItem ].update ( dt );
    		break;
    	}
    	case ( HIGHSCORE  ) : {
        	pHighScore.show();
        	break;
    	}
    	case ( ABOUT ) : {
    		break;
    	}
    	default: {
    		warring ( "Unknown value of MenuState [Method: Menu::update() ]" );
    		break;
    	}
    }

    return pIsDone;
}

/** */
void Menu::draw() {

    switch ( pMenuState ) {
    	case ( MAIN ) : {
    		drawMainMenu();
    		break;
    	}
    	case ( HIGHSCORE ) : {
    		pHighScore.show();
    		break;
    	}
    	case (ABOUT ) : {
    		drawAbout();
    		break;
    	}
    	default: {
    		warring ( "Unknown value of MenuState [Method: Menu::draw()]" );
    		break;
    	}
    }
}


/** Rysowanie wszystkiech elementow glownego menu */
void Menu::drawMainMenu() {

	  pRendererPtr->drawBackground( true );

	  for ( register uint i = 0; i < pMainMenuItem.size(); ++i ) {
        pMainMenuItem[i].draw();
     }

}


/** Obsluga nacicniecia entera w menu glownym */
void Menu::pressedReturn() {

    string currentItem = pMainMenuItem[pCurrentItem].getItemName();


    if ( currentItem ==  Property::get ( "RESUME_GAME" ) ) {
    	pSoundManagerPtr->playGameMusic();
        Game::setGameState ( Gamespace::PLAY );
	
    }
    else if ( currentItem == Property::get ( "NEW_GAME" ) ) {

        // stworzenie nowej gry
        pSoundManagerPtr->stopMenuMusic();
    	pSoundManagerPtr->playGameMusic();
        Game::setGameState ( Gamespace::PLAY );
        pMainMenuItem[0].setActive ( true );
        pMainMenuItem[ pCurrentItem ].setSelected ( false );
        pMainMenuItem[0].setSelected ( true );
        pCurrentItem = 0;
        pMainMenuItem[0].setSelected ( true );
	  
        // zresetowanie gry
        Game::resetGame();

    }
    else if ( currentItem ==  Property::get ( "HIGH_GAME" ) ) {
       // przejscie z menu do highscore
        pMenuState = Gamespace::HIGHSCORE;

    }
    else if ( currentItem ==  Property::get ( "EXIT_GAME" ) ) {
        // normalne wyjscie z gry poprzez wybranie exit w menu
        pIsDone = true;
    }
    else if( currentItem == Property::get("ABOUT_GAME") ) {
    	//wlaczenie widoku highscore
    	pMenuState = Gamespace::ABOUT;
    }

}

/** 0blsuga nacisniecia ESC */
void Menu::pressedEsc() {

    switch ( pMenuState ) {

    case ( MAIN ) : {
        pIsDone = true;
        break;
    }
    case ( HIGHSCORE ) : {
        // Powrot z highscore do glownego menu
        pMenuState = Gamespace::MAIN;
        break;
    }
    case ( ABOUT ): {
    	//powrot z about do menu
    	pMenuState = Gamespace::MAIN;
    	break;
    }
    default: {
        logger.warring ( "Error in Menu::pressedEsc" );
        break;
    }

    }

}

/** Przewijanie menu poziomego dla danego itemsa */
void Menu::pressedRight() {

    switch ( pMenuState ) {

    	case ( MAIN ) : {
    		if ( pMainMenuItem[pCurrentItem].getItemsNo() ) {
    			pMainMenuItem[pCurrentItem].next();
    		}
    		break;
    	}
    	case ( HIGHSCORE ) : {
    		break;
    	}
    	default: {
    		logger.warring ( "Error in Menu::pressedRight" );
    		break;
    	}
    }
}


/** Przewijanie menu poziomego */
void Menu::pressedLeft() {

    switch ( pMenuState ) {
    	case ( MAIN ) : {
    		if ( pMainMenuItem[pCurrentItem].getItemsNo() ) {
    			pMainMenuItem[pCurrentItem].prev();
    		}
    		break;
    	}
    	case ( HIGHSCORE ) : {
    		break;
    	}
    	default: {
    		logger.warring ( "Error in Menu::pressedRight" );
    		break;
    	}
    }
}


/** Obsluga nacisniecia strzalki w dol */
void Menu::pressedDown() {

    if ( pCurrentItem < ushort ( pMainMenuItem.size() - 1 ) ) {
        pMainMenuItem[pCurrentItem].setSelected ( false );
        pMainMenuItem[ ++pCurrentItem ].setSelected ( true );
    }
}


/** Przechodzenie do elementu menu znajdujacego sie powyzej */
void Menu::pressedUp() {

    if ( pCurrentItem > 1 ) {
        pMainMenuItem[pCurrentItem].setSelected ( false );
        pMainMenuItem[ --pCurrentItem ].setSelected ( true );
    }
    else if ( pCurrentItem == 1 ) {
        if ( pMainMenuItem[0].isActive() ) {
            pMainMenuItem[pCurrentItem].setSelected ( false );
            pMainMenuItem[ --pCurrentItem ].setSelected ( true );
        }

    }

}


/** */
void Menu::resetMenu() {
	logger.debug("Reset menu");
	pressedDown();
}


/** */
void Menu::drawAbout() {

	if( pAboutImg == 0 ) {
		logger.warring("Get surface in GL fomrat");
		pAboutImg = Renderer::getSurfaceInGLFormat( Resource::getSurf("ABOUT") );
	}

	 Rect tmp(0,0,pScreenWidth,pScreenHeight);
     pRendererPtr->draw( pAboutImg , tmp);

 	// rysowanie przycisku exit
 	pExitIco.draw(exit_x, exit_y, 50, 50);
 	Rect where(exit_x+60, exit_y+10,200,200);

 	pWriterPtr->draw(where, "Esc");

}
