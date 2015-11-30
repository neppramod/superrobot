#include "Player.h"
#include "Command.h"
#include <iostream>
typedef Commands::Command Command;

Player::Player() : Entity()
{
	

}


Player::~Player()
{
}

void Player::update(const sf::Window& window) { }

void Player::update() {

	Command * command = inputHandler.handleInput();
	if (command)
	{
		command->execute(*this);
	}

}