#include "Command.h"
#include "CharacterCreation.h"
#include "OptionsMenu.h"
#include "World.h"
extern OptionsMenu optionsMenu;
extern CharacterCreation characterCreation;
extern World world;
namespace Commands {

	void Commands::Command::execute() {}

	void NewGame::execute()
	{

		MenuRenderHelper.push_back(&world);

	};

	void Options::execute()
	{

		MenuRenderHelper.push_back(&optionsMenu);

	};


	void Back::execute() {
		MenuRenderHelper.pop_back();
	}

	void Start::execute() {
		MenuRenderHelper.push_back(&world);
	}
	void Command::execute(Entity& actor) {}
	void moveUp::execute(Entity& actor) { actor.moveUp(); }
	void moveDown::execute(Entity& actor) { actor.moveDown(); }
	void moveUpLeft::execute(Entity& actor) { actor.moveUpLeft(); }
	void moveDownLeft::execute(Entity& actor) { actor.moveDownLeft(); }
	void moveUpRight::execute(Entity& actor) { actor.moveUpRight(); }
	void moveDownRight::execute(Entity& actor) { actor.moveDownRight(); }
	void moveLeft::execute(Entity& actor) { actor.moveLeft(); }
	void moveRight::execute(Entity& actor) { actor.moveRight(); }


	Command::~Command()
	{

	}




}