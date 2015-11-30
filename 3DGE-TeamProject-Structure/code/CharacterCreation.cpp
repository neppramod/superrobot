#include "CharacterCreation.h"

//REFACTOR NEEDED
//FOR CONFIG PROCESSING
CharacterCreation::CharacterCreation() : nameL("Name:", 30, 30, false), typeL("Type:", 30, 61, false),
classL("Class:", 30, 92, false), leftArrowRace("<", 121, 60, &back),
leftArrowClass("<", 125, 90, &back), rightArrowRace(">", 245, 60, &back),
rightArrowClass(">", 245, 90, &back),
startButton("Start", 30, 200, &startGameCommand), backButton("Back", 30, 236, &back),

Container()
{
	push(&nameL);
	//push(&background)
	push(&leftArrowRace);
	push(&rightArrowRace);
	push(&typeL);
	push(&leftArrowClass);
	push(&rightArrowClass);
	push(&classL);
	//push(&examplePlayer);
	push(&startButton);
	push(&backButton);
}


CharacterCreation::~CharacterCreation()
{
}
