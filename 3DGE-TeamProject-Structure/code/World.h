#ifndef _WORLD_
#define _WORLD_
#include "Container.h"
#include "Player.h"
#include "Bot.h"
#include "Button.h"
class GameEngine;
class GraphicsSystem;
//I'm finding that all of my container classes could be templates instead of classes
//May change later
class World :
	public Container
{
public:
	World();
	void update();
	void update(const sf::Event& evnt, const sf::RenderWindow& window);
	void draw(sf::RenderTarget & target, sf::RenderStates states) const;
	void setEngine(GameEngine * engine);
	void setGraphicsSystem(GraphicsSystem * system);
	~World();
private:
	Player player;
	Bot bot;
	Label healthNum;
	GameEngine* gameEngine;
	sf::Time timer;
	sf::Clock clock;
	GraphicsSystem *graphics;
};
#endif