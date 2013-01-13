#ifndef HIGHSCORE_HPP
#define HIGHSCORE_HPP

#include "Headers.hpp"
#include "StandardReferences.hpp"
#include "Sprite.hpp"

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

  void update(const float& dt );

private:
  /** metody do porownywania dwoch wynikow przy sortowaniu */
  static bool compareItem(HighscoreItem A, HighscoreItem B );

private:
  
  /** imie ktore wpisuje gracz po przegranej grze */
  string pCurrentName;

  static vector<HighscoreItem> pList;

  /** maksymalna ilsoc wymikow wyswietlanych na lisciwe wynikow */
  ushort ITEM_AMOUNT;

  /** puste tlo dla hoghscore */
  GLuint pBackground;

  /** ikona informacji obok naglowka dla tabelki wynikow */
  Sprite pInfoIco;

  /** etykiety dla kolumn w tabelce */
  string pInfoText;
  string pRankText;
  string pNameText;
  string pScoreText;

  /** ikona w lewym dolnym rogu */
  Sprite pExitIco;

  /** polozenie naglowka dla listy wynikow */
  int tmpXText;
  int tmpY;

  /** wyrownanie kolumn w tabeli z wynikami */
  int rank_x;
  int name_x;
  int score_x;

  /** polozenie przycisko exit w wejsciu z menu */
  int exit_x;
  int exit_y;

  /** Zmienne dla ekranu na ktorym mozna wpisac nazwe uzytkownika */
  Sprite pWarringIco;
  Sprite pStarIco;
  string pGameOverText;
  string pEnterNameText;
  string pNewHighscoreText;

  /** zmienna odpowiadajaca za miganie kursora podczas wpisywania teskstu */
  bool pShowCursor;
  float pShowCursorShowTime;
  float pMaxShowCursorShowTime;

};

#endif // HIGHSCORE_HPP
