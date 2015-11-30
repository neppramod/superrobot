#ifndef _GAME_
#define _GAME_
#include "MainMenu.h"
class GameEngine;
class Logger;
class Game
{
public:
	Game();
	~Game();
	void	run();
	void setLogger(Logger*);
	void setGameEngine(GameEngine*);
	sf::RenderWindow* getWindow();
private:
	void processEvents();
	void update();
	void render();
	sf::RenderWindow window;
	MainMenu mainMenu;
	Logger* logger;
	GameEngine* engine;
};
#endif