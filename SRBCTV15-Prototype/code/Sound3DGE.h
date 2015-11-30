#pragma once

#ifndef SOUND_3DGE_H
#define SOUND_3DGE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <glm/glm.hpp>

using namespace std;
using namespace sf;

/** Encapsulates a sound object */
class Sound3DGE
{
private:
	string name;				// Name of this sound object. It uniquely identifies a sound object. Required to search this sound object in the SoundManager
	SoundBuffer buffer;			// Buffer is filled with the sound file read from disk. Buffer sound is relatively smaller than music (which is much large)
	Sound *sound;				// Encapsulates OpenAL Sound object functionality	

public:
	Sound3DGE(string name);
	Sound3DGE();
	virtual ~Sound3DGE();
	
public:
	// Some API functions interesting for this Sound (Sound3DGE) Object
	// It basically encapsulates sf::Sound object
	// Since we assume only one Listener throught the world, listener's properties are set in the SoundManager itself (globally).
	string getName();
	Sound getSound();  // If we need more than the following api functions.

	void play();
	void pause();
	void stop();
	void setPitch(float pitch);

	/** 
		Volume factor = MinDistance / (MinDistance + Attenuation * (max(Distance, MinDistance) - MinDistance))
		Distance = is the distance between the sound and the listener
		See http://www.sfml-dev.org/tutorials/2.0/audio-spatialization.php for more information.
	*/
	void setPosition(glm::vec3 position);
	void setRelativeToListener(bool relative); // Since we are doing 3D sound and our listener position changes, it is set to true by default. If set to false it is absolute
	void setMinDistance(float minDistance);
	void setAttenuation(float attenuation);
	void setLoop(bool loop);
	void setVolume(float volume);

	float getPitch();
	float getAttenuation();
	bool getLoop();
	float getMinDistance();
	glm::vec3 getPosition();
	
};

#endif