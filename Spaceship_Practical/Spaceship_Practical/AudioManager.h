
#ifndef _AUDIOMANAGER_
#define _AUDIOMANAGER_

#include "fmod.hpp"

class AudioManager
{
private:
	FMOD::System* system;
	FMOD::Sound* sound1, * sound2;
	FMOD::Channel* channel = 0;
	FMOD_RESULT result;
	void* extraDriverData = 0;

public:
	// Constructor & Destructor:
	AudioManager();
	~AudioManager();

	// Methods:
	void initializeAudio();
	void playSound1();
	void playSoundtrack();
	void loadSounds();
	void updateSound();

};

#endif _AUDIOMANAGER_
