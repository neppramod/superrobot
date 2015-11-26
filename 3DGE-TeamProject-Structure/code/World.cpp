#include "World.h"
#include "GraphicsSystem.h"
#include "GameEngine.h"

#include <GL\glew.h>
#include <iostream>
extern sf::Texture tex;
World::World() : player(), bot(), healthNum("health: ", false),clock(), Container()
{
	
	push(&player);
	push(&bot);
	push(&healthNum);
	
	wonky = true;
}

void World::update() {

	timer = clock.restart();
	graphics->update(timer.asSeconds());

	for (const_iterator a = cbegin(); a != cend(); a++)
	{
		(*a)->update();

	}

};

void World::update(const sf::Event& event, const sf::RenderWindow& window) {

	timer = clock.restart();
	graphics->update(timer.asSeconds());

	for (const_iterator a = cbegin(); a != cend(); a++)
	{
		(*a)->update(window);

	}

}



void World::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	GraphicsSystem *graphics = this->gameEngine->getGraphicsSystem();
	graphics->clearViewPort(0, 0, 1024, 720, { 0,0,0,1 });
	
	window->pushGLStates();
	glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	graphics->render();
	window->popGLStates();
	
	
	for (const_iterator a = cbegin(); a != cend(); a++)
	{
		(*a)->draw(target, states);
	}
	
	

}

void World::setEngine(GameEngine* engine) {
	this->gameEngine = engine;
}

void World::setWindow(sf::RenderWindow* window) {
	this->window = window;
}
void World::setGraphicsSystem(GraphicsSystem* system) {
	this->graphics = system;
}
World::~World()
{
}
