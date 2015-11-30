#include "Game.h"
#include "Logger.h"
#include "GameEngine.h"
#include "SFML/OpenGL.hpp"


//fix the include hierarchy at some point

Game::Game() : window(sf::VideoMode(1024, 720), "Super Robot Battle Chess TV 15",sf::Style::Default, sf::ContextSettings(24,8,0,3,3)), mainMenu()
{
	
	
	window.setFramerateLimit(60);
	MenuRenderHelper.push_back(&mainMenu);

}

Game::~Game() {}

void Game::run() {
	

	while (window.isOpen())
	{
		
		processEvents();
		update();
		
		render();
		
		
	}

}

sf::RenderWindow* Game::getWindow() {

	return &window;
}

void Game::processEvents() {//responsible for player input

	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		else if (event.type == sf::Event::Resized)
		{
			//glMatrixMode(GL_PROJECTION);
			//glLoadIdentity();                   //these three lines align the viewport to 4th quadrant(x+/y-) of the caretesian coordinate system
			//glOrtho(0.0f, event.size.width, event.size.height, 0.0f, 0.0f, 1.0f);
			
			//window.mapPixelToCoords();  // this is for keeping the mouse and window coordinates consistent with a reference frame relative to the same width/height of the window

			glViewport(0, 0, event.size.width, event.size.height);

		}
		MenuRenderHelper.back()->update(event, window);

	}

}

void Game::update() {//update logic changes

	MenuRenderHelper.back()->update();

}

//Remember to keep update and render COMPLETELY separate
void Game::render() {//update graphics

	//window.clear(); //<- has more than just glClear in it, don't use... it. it may be useful later though
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	MenuRenderHelper.back()->draw(window, sf::RenderStates::Default);

	window.display();
}

void Game::setLogger(Logger* logger) {
	this->logger = logger;
}

void Game::setGameEngine(GameEngine* engine) {
	this->engine = engine;
}