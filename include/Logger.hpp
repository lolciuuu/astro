#ifndef LOGGER_HPP
#define LOGGER_HPP
#include "Headers.hpp"

/** Globalna klasa uzywana do logowania. Dodatkowo dla funkcji statycznych dosteone sa metody
 * z GlobFun.hpp. Wiekszosc modulow dziedziczy po StandardReferences w ktorym jest obiekt klasy Logger.
 * Nalezy jedynie na liscie inicjalizacyjnej dac jako parametr nazwe klasy, ktora jest pozniej dopisywana do logow */
class Logger {
public:
	Logger( string className );

	void methodStart(  const string& methodName );

	void methodEnd(  const string& methodName );

	void info( const string& Str );

	void debug( const string& Str );

	void warring( const string& Str );

	void error( const string& Str );

	void critical(  const string& Str );

	void setClassName( string Name ) { className = Name; }

private:
	string className;

};

#endif
