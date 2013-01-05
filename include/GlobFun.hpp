/** Plik zawiera funkcje globalne inline, ktore pelnia role pomocnicze, i sa one dostepne w calym systemie. */

#ifndef GLOBFUN_HPP
#define GLOBFUN_HPP
#include "Headers.hpp"


/** wypisuje komunikat w konsoli */
inline void info( const string& t ) {
    cout<<"[ Info ] "<< t <<endl;
}

/** Wyswietla komunikat wtedy kiedy aplikacja skompilowana jest w trybie debug */
inline void debug( const string& t ) {
#ifdef DEBUG
    cout<<"[ Debug ] "<< t <<endl;
#endif
}

/** Zwraca informacje o tym czy kafelek jest platforma */
inline bool isPlatform( short ID ) {
	if( ID == 39 ) return true;
	return false;
}

/** Czy kafelek jest bonusem dodajacym zycia? */
inline bool isBonus( const short& ID ) {
	if( ID == 38 || ID ==  37 ) return true;
	return false;
}

/** Czy kafelek jest bonusem ktory gracz moze zebrac? */
inline bool isAdditionalBonus( const short& ID ) {
	if( ID == 41 ) return true;
	return false;
}

/** okresla czy kafalek to wrog */
inline bool isEnemy( const short& ID ) {
	if( ID == 40 ) return true;
	return false;
}

/** Metoda wyswietla w konsoli informacje.
 * Podana jako parametr informacja to ostrzezenie.
 */
inline void warring ( const string& Text ) {
    cerr<<"[ Warning ] "<< Text <<endl;
}


/** Metoda wyswietla w konsoli informacje.
* Podana jako parametr informacja to informacja o bledzie.
*/
inline void error ( const string& Text ) {
    cerr<<"[ Error ] "<< Text <<endl;
}

/** */
inline void startMethod( const string& name ) {
	info( name + "| start" );
}

/** */
inline void endMethod( const string& name ) {
	info( name + "| end" );
}

/** Metoda wyswietla w konsoli informacje.
* Podana jako parametr informacja to informacja o bledzie krytycznym.
*/
inline void critical ( const string& Text ) {
    cerr<<"[ Critical ] "<< Text <<endl;
}

/** Metoda odczytuje kod jezyka jaki ma byc ustawiony w grze i zwraca go jako
 *  string. W razie problemow ze znalezieniem pliku zwraca informacje ze jezykiem
 *  w grze jest angielski.
 */
inline string loadLanguages() {

    fstream langFile ( "data/lang" , std::ios::in );

    if ( langFile.is_open() ) {

        char bufor[ 1024 ]={ '\0' };
        langFile.getline ( bufor,1023 );
        langFile.close();
        return( string ( bufor ) );

    }
    else return( "ANG" );
}


/** Zamienia liczbe na string */
template <typename T>
inline string toString( T number ) {
  std::ostringstream ss;
  ss<<number;
  return( ss.str() );
}

/** Drukuje na ekranie info o SDL_Rect oraz jego nazwe podana jako parametr */
inline void printRect( const string& Name, Rect& rect ) {
  info( "Rect:\"" + Name +"\"\n"
	+ "\tX: " + toString<Sint16>(rect.x)
	+ " | Y: " + toString<Sint16>(rect.y)
	+ " | W: " + toString<Uint16>(rect.w)
	+ " | H: " + toString<Uint16>(rect.h) );
}
#endif
