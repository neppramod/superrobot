#include "Sound3DGE.h"

#define SOUND_FORMAT ".wav"
#define SOUND_RESOURCE_PATH "assets/audio/"

Sound3DGE::Sound3DGE()
{

}

// Set name, load file and set buffer to sound object
Sound3DGE::Sound3DGE(string name)
{
	this->name = name;
	string filename = SOUND_RESOURCE_PATH + this->name + SOUND_FORMAT;

	if (!this->buffer.loadFromFile(filename))
	{
		cout << "SFML Error: Cannot load sound file: " << filename << endl;
		exit(-1);
	}
	sound = new Sound(this->buffer);
}

Sound3DGE::~Sound3DGE()
{
}

string Sound3DGE::getName()
{
	return this->name;
}

Sound Sound3DGE::getSound()
{
	return *(this->sound);
}

void Sound3DGE::play()
{
	//this->sound->setBuffer(this->buffer);
	this->sound->play();
}

void Sound3DGE::pause()
{
	this->sound->pause();
}

void Sound3DGE::stop()
{
	this->sound->stop();
}

void Sound3DGE::setPitch(float pitch)
{
	this->sound->setPitch(pitch);
}

void Sound3DGE::setPosition(glm::vec3 position)
{
	Vector3f vecPosition;
	vecPosition.x = position.x;
	vecPosition.y = position.y;
	vecPosition.z = position.z;

	this->sound->setPosition(vecPosition);
}

void Sound3DGE::setRelativeToListener(bool relative)
{
	this->sound->setRelativeToListener(relative);
}

void Sound3DGE::setMinDistance(float minDistance)
{
	this->sound->setMinDistance(minDistance);
}

void Sound3DGE::setAttenuation(float attentuation)
{
	this->sound->setAttenuation(attentuation);
}

void Sound3DGE::setLoop(bool loop)
{
	this->sound->setLoop(loop);
}

void Sound3DGE::setVolume(float volume)
{
	this->sound->setVolume(volume);
}

float Sound3DGE::getPitch()
{
	return this->sound->getPitch();
}

float Sound3DGE::getAttenuation()
{
	return this->sound->getAttenuation();
}

bool Sound3DGE::getLoop()
{
	return this->sound->getLoop();
}

float Sound3DGE::getMinDistance()
{
	return this->sound->getMinDistance();
}

glm::vec3 Sound3DGE::getPosition()
{
	Vector3f vecPosition = this->sound->getPosition();
	return glm::vec3{ vecPosition.x, vecPosition.y, vecPosition.z };
}