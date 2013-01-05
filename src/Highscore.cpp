#include "../include/Highscore.hpp"
#include "App.hpp"
#include <cstdlib>

vector<HighscoreItem> Highscore::pList;

/** */
Highscore::Highscore(): ITEM_AMOUNT(15)
{
  logger.setClassName( "Highscore" );
  load();
}

void Highscore::pressedBackspace() {
	if( pCurrentName.size() > 0 )
		pCurrentName = pCurrentName.substr( 0 , pCurrentName.size() - 1 );
}

void Highscore::pressedChar(char Char) {
	if( pCurrentName.size() < 20 )
		pCurrentName += Char;
}

/** */
void Highscore::draw() {
    SDL_Color color( {240,240,250} );

    Rect where( 150,200,300,300 );
    pWriterPtr->draw(where,"GAME OVER", color);

    where.y += 40;
    pWriterPtr->draw(where, "Result: " + LiveBar::getResult() + "m", color );

    where.y += 30;
    pWriterPtr->draw(where, "Name: ", color );

    if( pCurrentName.size() > 0 ) {
    	 where.x += 80;
    	 pWriterPtr->draw(where,pCurrentName, color );
    }

    if( pList.size() > 0 ) {
    	where.x  =150;
    	for( uint i=0; i<pList.size(); ++i ) {
    		where.y += 30;
    		if( pList[i].name.size() > 0 )
    			pWriterPtr->draw(where, pList[i].name , color );
    	}
    }
}

/** */
void Highscore::show(){

	SDL_Color color( {240,240,250} );
    Property::get("HIGH_GAME_DIST");
    pWriterPtr->setFont("bold_big");
    Rect where({40,40,200,200});
    pWriterPtr->draw(where ,"HIGHSCORE" );
    
	for( uint i=0; i<pList.size(); ++i ) {
		where.y += 30;
		if( pList[i].name.size() > 0 )
			pWriterPtr->draw(where, pList[i].name , color );
	}
}

/** */
void Highscore::colision( short type ) {
    debug("Highscore colision");
    LiveBar::increaseLive();
}
  

/** */
void Highscore::load() {

	pList.clear();

	logger.info("Load highscore file");

	fstream highFile;
	highFile.open( "data/astro.data", std::ios::in );

	  if( highFile.is_open() ) {

		  while( !highFile.eof() ) {
			  if( pList.size() > ITEM_AMOUNT )
				  break;

			  HighscoreItem item;
			  highFile>>item.name;
			  highFile>>item.points;

			  pList.push_back( item );
		  }

		  highFile.close();
	  }
}

/** */
void Highscore::save() {

	logger.info("Saving highscore");

	 if( pCurrentName.size() > 0 ) {
		 HighscoreItem item;
		 item.name = pCurrentName;
		 item.points = atoi( LiveBar::getResult().c_str() );
		 pList.push_back( item );
	}

	 fstream highFile;
	 highFile.open( "data/astro.data", std::ios::out ) ;

	 //@TODO posortowac liste

	 if( highFile.is_open() ) {

		    for( uint i=0; i<pList.size(); ++i ) {

		    	if( i >= ITEM_AMOUNT ) break;

		    		highFile<<pList[i].name<<" ";
		    		highFile<<pList[i].points;

		    		if( i != pList.size()-1 )
		    			highFile<<"\n";
		    }

		 highFile.close();
	 }
	 else logger.critical("Cannot save highscore");

	 logger.info("Saved highscore to file");
}

