#include "SoundManager.h"
#include <iostream>

SoundManager *SoundManager::soundManagerInstance = NULL;

SoundManager::SoundManager()
{
	
}


SoundManager::~SoundManager()
{
}

// Singletion SoundManager
SoundManager &SoundManager::createInstance()
{
	if (!soundManagerInstance)
		soundManagerInstance = new SoundManager();

	return *(soundManagerInstance);
}

// Singleton based on file name. i.e., One Sound3DGE object per file name
Sound3DGE *SoundManager::getSound(string name)
{
	if (!this->soundList[name]) {
		soundList[name] = new Sound3DGE(name);
	}

	return soundList[name];
}

// Play the sound with source position
void SoundManager::playSound(string name, glm::vec3 position)
{
	Sound3DGE *sound3DGE = this->getSound(name);
	sound3DGE->setPosition(position);
	sound3DGE->play();
}

void SoundManager::setListenerPosition(glm::vec3 position)
{
	sf::Listener::setPosition(vector3fFromvec3(position));
}

void SoundManager::setListenerDirection(glm::vec3 orientation)
{
	sf::Listener::setDirection(vector3fFromvec3(orientation));
}

void SoundManager::setGlobalVolume(float volume)
{
	sf::Listener::setGlobalVolume(volume);
}

void SoundManager::setUpVector(glm::vec3 up)
{
	sf::Listener::setUpVector(vector3fFromvec3(up));
}