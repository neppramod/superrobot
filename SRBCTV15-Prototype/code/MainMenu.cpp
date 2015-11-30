#include "MainMenu.h"

MainMenu::MainMenu() :newGame("New Game", 50, 100, &newGam),
options("Options", 50, 136, &optons),
exit("Exit", 50, 206, &ext),
title("Super Robot Battle Chess TV", 20, 10, false, "CAPTKD__.ttf", sf::Color::Yellow, 40)
, Container()
{

	push(&title);
	push(&newGame);
	push(&options);
	push(&exit);
}


MainMenu::~MainMenu()
{
}
