#include "../include/Logger.hpp"

/** Podana nazwa klasy jest doklejana do logow */
Logger::Logger( string className ): className( className )
{ }

/** wypisuje informacje o rozpoaczeciu dzialania metody */
void Logger::methodStart(  const string& methodName ) {
	info( className + "::" + methodName + " | start"  );
}

/** wypisuje informacje o tym ze metoda sie zakonczyla */
void Logger::methodEnd( const string& methodName ) {
	info( className + "::" + methodName + " | end"  );
}

/** wypisuje informacje */
void Logger::info( const string& Str ) {
    cout<< "[ Info ] " << Str  << " | class::" << className << " | " << endl;
}

/** wypisuje ostrzezenie */
void Logger::warring( const string& Str ) {
    cout<< "[ Warning ] " << Str  << " | class::" << className << " | "<<endl;
}

/** informacja o bledzie */
void Logger::error( const string& Str ) {
    cerr<< "[ Error ] " << Str  << " | class::" << className << " | " <<endl;
}

/** informacja o bledzie krytycznym */
void Logger::critical( const string& Str ) {
    cerr<< "[ Critical ] " << Str  << " | class::" << className << " | "<<endl;
}

/** Wypisuje tylko kiedy ustawiona flaga debug */
void Logger::debug(const string& Str) {
#ifdef DEBUG
	 cout<< "[ Debug ] " << Str  << " | class::" << className << " | "<<endl;
#endif
}

