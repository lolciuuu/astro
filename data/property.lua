--[[ 
  void cxx_addProperty( string KEY, string VALUE);
  Wywolana w skrypcie metoda cxx_addProperty wywoluje metode w kodzie c++ ktora dodaje
  nowy string dostepny pod danym kluczem w aplikacji   
--]]


--Errors
cxx_addProperty("UNKNOW_EXCEPTION" , "App was terminated by unknow error!");

--Info
cxx_addProperty("APLICATION_NAME","Astro Rush");
cxx_addProperty("END_STARTING" , "Starting game is finished");
cxx_addProperty("GAME_END_INFO" , "Game ending normaly");
cxx_addProperty("ATLAS_NOT_FOUND" , "Atlas file not found");
cxx_addProperty("CURRENT_LANG_INFO" , "Current languages is english");
cxx_addProperty("READ_PROPERTY_END" , "Reading property finished. Close file.");
cxx_addProperty("TTF_NOT_FOUND" , "Font not found");

--Game text
cxx_addProperty("NEW_GAME","New");
cxx_addProperty("NEW_GAME_DESC", "Start new game");

cxx_addProperty("RESUME_GAME","Resume");
cxx_addProperty("RESUME_GAME_DESC","Continuing current game");

cxx_addProperty("HIGH_GAME","Highscore");
cxx_addProperty("HIGH_GAME_DESC","best score");
cxx_addProperty("HIGH_GAME_DIST","Distance: ");

cxx_addProperty("ABOUT_GAME","About");
cxx_addProperty("ABOUT_GAME_DESC","Version: 0.0.0 devel");

cxx_addProperty("EXIT_GAME","Exit");
cxx_addProperty("EXIT_GAME_DESC","Exit game");

print( "[ Lua ] End of script:property.lua" );
