--[[ 
  void cxx_addProperty( string KEY, string VALUE);
  Wywolana w skrypcie metoda cxx_addProperty wywoluje metode w kodzie c++ ktora dodaje
  nowy string dostepny pod danym kluczem w aplikacji   
--]]


-- Errors
cxx_addProperty("UNKNOW_EXCEPTION" , "Działanie aplikacji zakończył nieznany błąd");

-- Info
cxx_addProperty("APLICATION_NAME","Astro Rush");
cxx_addProperty("END_STARTING" , "Zakończono ładowanie aplikacji");
cxx_addProperty("GAME_END_INFO" , "Zakończono normalnie");
cxx_addProperty("ATLAS_NOT_FOUND" , "Nie znaleziono pliku: atlas.png");
cxx_addProperty("CURRENT_LANG_INFO" , "Aktualny język to polski");
cxx_addProperty("READ_PROPERTY_END" , "Wczytywanie propertisów zakończone");
cxx_addProperty("TTF_NOT_FOUND" , "Font not found");

-- MENU
cxx_addProperty("NEW_GAME","New");
cxx_addProperty("NEW_GAME_DESC", "Nowa gra");

cxx_addProperty("RESUME_GAME","Kontynuuj");
cxx_addProperty("RESUME_GAME_DESC","Kontynuowanie gry");

cxx_addProperty("HIGH_GAME","Rekordy");
cxx_addProperty("HIGH_GAME_DESC","najlepszy wynik");
cxx_addProperty("HIGH_GAME_DIST","Dystans: ");

cxx_addProperty("ABOUT_GAME","O grze");
cxx_addProperty("ABOUT_GAME_DESC","To jest wersja rozwojowa gry!");

cxx_addProperty("EXIT_GAME","Wyjście");
cxx_addProperty("EXIT_GAME_DESC","Zakończe aplikacje");

-- HIGHSCORE
cxx_addProperty("HIGHSCORE_INFO_TEXT","Najlepszy wynik:");
cxx_addProperty("HIGHSCORE_RANK_TEXT","miejsce");
cxx_addProperty("HIGHSCORE_NAME_TEXT","nazwa gracza");
cxx_addProperty("HIGHSCORE_SCORE_TEXT","punkty");
cxx_addProperty("HIGHSCORE_OVER","Bieg dobiegł końca");
cxx_addProperty("HIGHSCORE_ENTER_NAME","Wpisz swoje imię i naciśnij enter:");
cxx_addProperty("HIGHSCORE_NEW","Nowy rekord!");

print( "[ Lua ] End of script:property.lua" );

