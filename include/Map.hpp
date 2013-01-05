#ifndef MAP_HPP
#define MAP_HPP

#include "Headers.hpp"
#include "StandardReferences.hpp"
#include "Logger.hpp"

class Map : StandardReferences {
public:
  Map( short** , ushort EntitySize,uint R, uint C );  
  
  void draw();
  void update( const float& dt );
  void reset();
  
  short getEntity( uint X, uint Y ) const { return( pMap[X][Y] ); }
  
  void nextX() { ++pos_X; }
  void nextY() { ++pos_X; }
   
  ushort getAmountEntityVertical() const { return( pAmountEntityVertical ); }
  ushort getAmountEntityHorizontal() const { return( pAmountEntityHorizontal ); }
  uint getPos_X() const { return( pos_X ); }
  uint getPos_Y() const { return( pos_Y ); }
  short getSize() const { return( pSize ); }
  short getOffsetX() const { return( pOffset_X ); }
  short getOffsetY() const { return( pOffset_Y ); }
  
  void setRows( uint R ) { rows = R; }
  void setColumns( uint C ) { columns = C; }  
  void setSpeed( float S) { pSpeed = S; }

  bool isAnyPlatformAbove( float X, float Y );
  bool isAnyPlatformBelow( float X, float Y );
  bool isAnyPlatformOnRight( float X, float Y );

  short checkColision(const short& Player_x,const short& Player_y,ColisionSide& cSide );
  
  void enableCheckColision() { pCheckColision = true; }
  
  bool nextMeter() { if(pNextMeter){
		      pNextMeter = false;
		      return( true );
		    }
		    else return( false );
	}
  
private:  
  short** pMap; // macierz zaczytana z pliku
  
  uint pos_X;// ktora kolumna w macierzy jest ta pierwsza ( na ekranie od lewej)
  uint pos_Y;//..wiersz..
  
  float pOffset_X; // biezace przesuniecie w poziomie
  float pOffset_Y; // .. pionie
  
  short pSize; // rozmiar kafla z settingsow
  uint rows; // ilosc wszystkich wierszy danej mapy
  uint columns; // ... kolumn
  float pSpeed; // szybkosc przesuwania mapy pobrana z settingsow

  ushort pAmountEntityVertical; // ile fragmentow miesci sie na szerokosc ekranu
  ushort pAmountEntityHorizontal;// .. na dlugosc

  bool pCheckColision;
  bool pNextMeter;
  short pR;
  short pC;

 
  /// @TODO comment
  short pPlayer_x;
  short pPlayer_y;
  short pPlayer_sx;
  short pPlayer_sy;
 
  struct Point {
    Point(): X(0), Y(0), X_px(0), Y_px(0) {}
    Point( short x, short y, float pX, float pY ) : X(x), Y(y), X_px(pX), Y_px(pY) {}
    short X;
    short Y;
    float X_px; //polozenie na ekranie w px
    float Y_px; //polozenie na ekranie w px
  };
  std::stack<Point> pColisionStack;
  
  std::vector< vector<bool> > itWasReturn;
  std::vector< vector<bool> >* drawID;

  Logger logger;

};

#endif
