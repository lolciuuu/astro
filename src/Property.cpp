#include "Property.hpp"
#include "../include/App.hpp"

/// Init zmiennych statycznych
map< string, string> Property::property;
map< string, double> Property::pSettings;
string Property::pLanguages;
//END


/** Funkcja na podstawie podanego jako parametr jezyka wczytuje komunikaty
 *  w danym jezyku. Domyslnie jest to ANG. Komunikaty sa przechowywane w
 *  tablicy asocjacyjnej w bierzacej klasie. Komunikatow pobranych z propertys nalezy uzywac
 *  w calej aplikacji. ZAKAZUJE SIE UZYWANIE STRINGOW NA SZTYWNO W KODZIE!
 * @param string : Jezyk jaki bedzie ustawiony w grze, jest to zarazem koncowka w nazwie pliku (
					data/property_xxx )

 */
void Property::init(  const string& Languages ) {

    pLanguages = Languages;
    readSettings();
    readProperty();

}


/** Metoda jest uruchamiana z poziomu skryptu LUA,
 * wymaga dwoch parametrow- stringow. Dodaje ona nowa pare klucz-wartosc do property
 * @return 0
 */
int Property::addComand( lua_State* L ) {

    if ( lua_gettop(L) == 2 ) {

        string key( lua_tostring(L,1) );
        string value( lua_tostring(L,2) );
        Property::addProperty(key,value);

    }
    else {
        critical("Lua:addComand wrong parameters number");
        throw std::runtime_error("Property::addComand");
    }

    return 0;

}

/** Metoda jest uruchamiania z poziomu skryptu, dodaje nowy settings- para string, double
 * @return 0
 */
int Property::addSetting( lua_State* L ) {

    if ( lua_gettop(L) == 2 ) {

        string key( lua_tostring(L,1) );
        double value( lua_tonumber(L,2) );
        Property::addSetting(key,value);

    }
    else {
        critical("Lua:addSetting wrong parameters number");
        throw std::runtime_error("Property::addSetting");
    }

    return 0;

}

/** Wczytywanie komuniktaow z pliku dla konkretnego jezyku
 *  Domyslnie wczytywany jest jezyk angielski
 * @TODO dodac wczytywanie aktualnego jezyka z pliku z ustawieniami,
 */
void Property::readProperty() {

  // sprawdzanie jaka wersja jezykowa ma zostac wlaczona
    string fileName("data/property");
    if ( pLanguages != "ENG") {
        fileName += "_";
        fileName += pLanguages;
    }

    fileName += ".lua";

    lua_State* L = lua_open();
    luaL_openlibs(L);

    // Rejestracja metody ktora jest wywolywna ze skryptu
    lua_register( L, "cxx_addProperty", Property::addComand );

    //Wolanie skryptu
    if ( luaL_dofile( L, fileName.c_str() ) != 0 ) {
        critical(lua_tostring( L, -1 ));
        throw std::runtime_error("Property::init");
    }

    lua_close(L);
}


/** Metoda wykonuje skrypt settings.xml, do ktorego jednoczesnie przekazujem wymiary ekranu.
 * W skrypcie zarejestrowane sa metody: cxx_addProperty,cxx_addSetting za pomoca ktorych mozna ustawic w aplikacji
 * wartosc liczbowa i stringa. Takie dane dostepne sa potem w calej aplikacji za pomoca funkcji statycznych  */
void Property::readSettings() {

    lua_State* L = lua_open();
    luaL_openlibs(L);

	lua_pushnumber(L, App::getScreenHeight() );
	lua_setglobal(L, "SCREEN_H");

	lua_pushnumber(L, App::getScreenWidth() );
	lua_setglobal(L, "SCREEN_W");

    // Rejestracja metod ktora beda wywolywane ze skryptu
    lua_register( L, "cxx_addProperty", Property::addComand );
    lua_register( L, "cxx_addSetting", Property::addSetting );

    //Wolanie skryptu
    if ( luaL_dofile( L, "data/settings.lua" ) != 0 ) {
        critical(lua_tostring( L, -1 ));
        throw std::runtime_error("Property::init");
    }

    lua_close(L);
}



/** Metoda sprawdza czy pod podanym kluczem dostepny jest komunikat  
 *  @return true - jesli istnieje dana klucz
 */
bool Property::contains( const string& key) {
    bool isFound = property.find( key ) != property.end();
    return ( isFound ? true : false );
}


/** Metoda sprawdza czy pod podanym kluczem dostepna jest wartosc liczbowa  
 *  @return true - jesli instieje dany settings
 */
bool  Property:: containsSetings( const string& key) {
    bool isFound = pSettings.find( key ) != pSettings.end();
    return ( isFound ? true : false );
}


/** */
void Property::resetLang(string Languages){
    pLanguages = Languages;
    property.clear();
    readProperty();
}

