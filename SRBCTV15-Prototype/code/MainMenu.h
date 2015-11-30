#ifndef _MAINMENU_
#define _MAINMENU_
#include "Button.h"
#include "Bot.h"
#include "Player.h"
class MainMenu :
	public Container
{
public:
	MainMenu();
	~MainMenu();
private:
	Button newGame;
	Button loadGame;
	Button options;
	Button exit;
	Commands::NewGame newGam;
	Commands::Options optons;
	Commands::Exit ext;
	Label title;

};





#endif