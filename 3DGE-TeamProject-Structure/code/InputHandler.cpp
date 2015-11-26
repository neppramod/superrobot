#include "InputHandler.h"
#include "SFML\Window\Keyboard.hpp"

InputHandler::InputHandler() : keyW(new Commands::moveUp()), keyD(new Commands::moveRight()),
keyS(new Commands::moveDown()), keyA(new Commands::moveLeft()), keyWA(new Commands::moveUpLeft()),
keyWD(new Commands::moveUpRight()), keySA(new Commands::moveDownLeft()), keySD(new Commands::moveDownRight())
{
}


InputHandler::~InputHandler()
{
	delete keyW;
	delete keyD;
	delete keyS;
	delete keyA;
	delete keyWA;
	delete keyWD;
	delete keySA;
	delete keySD;
}

Command * InputHandler::handleInput() {
	/*
	Remove coupling on direct key presses later
	for options menu and config file processing
	*/

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) return keyWA;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) return keyWD;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) return keySA;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) return keySD;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) return keyW;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) return keyD;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) return keyS;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) return keyA;

	return NULL;
}