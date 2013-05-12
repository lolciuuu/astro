#ifndef SOUNDMANAGER_HPP
#define SOUNDMANAGER_HPP
#include "Headers.hpp"
#include "Logger.hpp"

class SoundManager {
public:
	static SoundManager* getInstance();

	static void loadMusic();

	static void playSplashIntro();

	void playMenuMusic();
	void stopMenuMusic();

	void playGameMusic();
	void stopGameMusic();

	void playSound( const string& soundName );

private:
	SoundManager();

	void loadSound( const string& str, const string& name );

	static void onClose();

private:
	static SoundManager* pInstance;
    map< string, Mix_Music* > pSounds;
    Logger logger;

};

#endif
