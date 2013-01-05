#ifndef PROPERTY_HPP
#define PROPERTY_HPP
#include "Headers.hpp"

/** @TODO opisac klase */
class Property {

public:

    static void init( const string& Languages = "ENG" );

    // Metoda wstawia do tablicy asocjacyjnej podany klucz i wartosc
    static void addProperty( const string& key, const string& value ) {
        property.insert( std::pair<string,string>(key,value));
    }

    // Metoda wstawia do tablicy asocjacyjnej podany klucz i wartosc
    static void addSetting( const string& key, double value ) {
        pSettings.insert( std::pair<string,double>(key,value));
    }

    // Metoda zwraca string dla danego klucza
    static string get( const string& key ) {

        if (contains(key) ) {
            return( property.find( key )->second );
        }
        else {
            error(key + "-Not found property" );
            return( "xxxxxxxxx" );
        }
    }
    
    // Metoda zwraca double dla danego klucza
    static double getSetting( const string& key ) {

        if (containsSetings(key) ) {
            return( pSettings.find( key )->second );
        }
        else {
            error(key + "-Not found property" );
            return( 0 );
        }
    }
    
    static string getCurrentLang(){ return( pLanguages ); }
    
    static void resetLang(string Lang);


private:
    Property() { /* constructor */ };

    static bool contains( const string& key);
    static bool containsSetings( const string& key);

    static int addComand( lua_State* L );
    static int addSetting( lua_State* L );

    static void readProperty();
    static void readSettings();

private:
    static string pLanguages;
    static map< string, double > pSettings;
    static map< string, string > property;

};



#endif
