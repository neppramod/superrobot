#ifndef _PLAYER_
#define _PLAYER_
#include "Entity.h"
#include "InputHandler.h"
class Player :
	public Entity
{
public:
	Player();
	void update();

	void update(const sf::Window&);
	~Player();
private:
	InputHandler inputHandler;
	sf::Texture texture;
};
#endif