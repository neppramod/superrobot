#pragma once

#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include <map>
#include "Sound3DGE.h"
#include <string>
#include <glm/glm.hpp>

using namespace std;

/**
Important Note: Always use mono sound, so that it can be spatialized.
A sound can be spatialized only if it has single channel.
*/

class SoundManager
{
private:
	map<string, Sound3DGE*> soundList;  // Each Sound3DGE object is unique (based on name)
	static SoundManager *soundManagerInstance; 

private:
	SoundManager();

public:
	virtual ~SoundManager();

public:
	static SoundManager& createInstance();
	Sound3DGE *getSound(string name); // If we need access to the Sound3DGE object to perform different operations	
	void playSound(string name, glm::vec3 position);	
	
	// Global sound properties
	void setListenerPosition(glm::vec3 position);
	void setListenerDirection(glm::vec3 orientation); // Listener's orientation

	/**
	E.g. setDirection(1.f, 0.0f, 0.0f); sets orientation to +X axis.  Sound emitted from 15,0,5 will be heard from right speaker
	Up vector of listener is by default always set to 0,1,0. It is pointing towards +Y.
	*/

	void setGlobalVolume(float volume);
	void setUpVector(glm::vec3 up);

private:
	sf::Vector3f vector3fFromvec3(glm::vec3 vecValue) { return sf::Vector3f{ vecValue.x, vecValue.y, vecValue.z}; }
	glm::vec3 vec3fFromVector3f(sf::Vector3f vectorValue) { return glm::vec3{ vectorValue.x, vectorValue.y, vectorValue.z }; }
};

#endif