#ifndef _CHARACTERCREATION_
#define _CHARACTERCREATION_
#include "Button.h"
#include "Label.h"
class CharacterCreation :
	public Container
{
public:
	CharacterCreation();
	~CharacterCreation();
private:
	Label nameL;
	sf::Texture background;
	Button leftArrowRace;
	Button rightArrowRace;
	Label typeL;
	Button leftArrowClass;
	Button rightArrowClass;
	Label classL;
	sf::Texture examplePlayer;
	Commands::Back back;
	Commands::Start startGameCommand;
	Button startButton;
	Button backButton;
};
#endif