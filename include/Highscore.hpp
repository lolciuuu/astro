#ifndef HIGHSCORE_HPP
#define HIGHSCORE_HPP

#include "Headers.hpp"
#include "StandardReferences.hpp"

class Highscore: StandardReferences
{
public:
  Highscore();
  
  void show();
  
  void colision( short type );
  
  void load();
  
  void save();
  
  void draw();

  void pressedBackspace();

  void pressedChar(char Char);

private:
  
private:
  
  string pCurrentName;

  static vector<HighscoreItem> pList;

  ushort ITEM_AMOUNT;

};

#endif // HIGHSCORE_HPP
