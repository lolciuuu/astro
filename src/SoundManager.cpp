#include "SoundManager.hpp"

SoundManager* SoundManager::pInstance( NULL );

/** Ustawia nazwe klasy na loggerze i jest prywatny. Dostep tylko poprzez standardRefernces */
SoundManager::SoundManager():logger("SoundManger") {

}

/** Implementacja singletona */
SoundManager* SoundManager::getInstance() {

	if( pInstance != NULL ) {
		return pInstance;
	}

	pInstance = new SoundManager();
	return pInstance;
}

/** Metoda statyczna do inicjowania modulu dzwiekowego,
 * wczytywania zasobow z plikow. Wolana jest z poziomu splasha */
void SoundManager::loadMusic() {

	info("SoundManager::loadMusic | init audio:start");

	 if( Mix_OpenAudio( MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096 ) == -1 )
	 {
		  critical("init audio failes :(");
		  error( string(SDL_GetError()) );

	      throw std::runtime_error("Init audio failed");
	 }

	 atexit( onClose );

	 info("SoundManager::loadMusic | init audio: success");

	 pInstance->loadSound( "data/sound/menu.wav", "MENU" );
	 pInstance->loadSound( "data/sound/play.mp3", "PLAY" );
	 pInstance->loadSound( "data/sound/splash.mp3", "SPLASH" );

	 info("Load sound finish");

}

/** Wczytuje z podanej sciezki plik dzwiekowy i przechowuje go pod przekazana nazwa */
void SoundManager::loadSound(const string& str, const string& name ) {

	logger.info("Load sound:" + name );
	Mix_Music* tmp = Mix_LoadMUS( str.c_str() );


	if( tmp == NULL ) {
		error( string(SDL_GetError()) );
	    throw std::runtime_error("Not found:" + str );
	}

	pSounds.insert( std::pair<string,Mix_Music*>( name,tmp ) );
}

/** */
void SoundManager::playMenuMusic() {

	if( Mix_FadeInMusic( pSounds.find( "MENU" )->second, -1, 4600 ) == -1 ) {
		error( string(SDL_GetError()) );
	    throw std::runtime_error("Cannot play menu music" );
	}

}

/** */
void SoundManager::stopMenuMusic() {
	Mix_FadeOutMusic( 100 );
}

/** */
void SoundManager::playGameMusic() {

	if( Mix_FadeInMusic( pSounds.find( "PLAY" )->second, -1, 4600 ) == -1 ) {
		error( string(SDL_GetError()) );
	    throw std::runtime_error("Cannot play menu music" );
	}

}

/** */
void SoundManager::stopGameMusic() {
	Mix_FadeOutMusic( 100 );
}

/** Wylaczenie dzwiekow przy wysciu*/
void SoundManager::onClose() {

	map< string, Mix_Music* >::iterator it( pInstance->pSounds.begin() );
	while( it != pInstance->pSounds.end() ) {
		Mix_FreeMusic( it->second );
		++it;
	}
	Mix_CloseAudio();
}

/** Metoda dla klasy splash ktora umozliwia odtworzenie dzwieku pod wczytaniu zasobow */
void SoundManager::playSplashIntro() {

	if( Mix_PlayMusic( pInstance->pSounds.find( "SPLASH" )->second, 1 ) == -1 ) {
		error( string(SDL_GetError()) );
	    throw std::runtime_error("Cannot play music" );
	}
}
