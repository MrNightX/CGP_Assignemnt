#include "AudioManager.h"

#include "AudioManager.h"

AudioManager::AudioManager()
{

}

AudioManager::~AudioManager()
{

}

void AudioManager::initializeAudio()
{
	result = FMOD::System_Create(&system);
	result = system->init(32, FMOD_INIT_NORMAL, extraDriverData);

}

void AudioManager::playSound1()
{
	result = system->playSound(sound1, 0, false, &channel);

}

void AudioManager::playSoundtrack()
{
	result = system->playSound(sound2, 0, false, &channel);

}

void AudioManager::loadSounds()
{
	result = system->createSound("", FMOD_DEFAULT, 0, &sound1);
	result = sound1->setMode(FMOD_LOOP_OFF);

	result = system->createSound("", FMOD_DEFAULT, 0, &sound2);
	result = sound2->setMode(FMOD_LOOP_OFF);

}

void AudioManager::updateSound()
{
	result = system->update();

}