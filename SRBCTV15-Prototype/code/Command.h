#ifndef _COMMAND_
#define _COMMAND_
#include "Entity.h"
#include "Container.h"
#include <memory>


extern std::vector<Container*> MenuRenderHelper;

namespace Commands {



	class Command
	{

	public:
		virtual ~Command();

		virtual void execute();
		virtual void execute(sf::RenderWindow& window) {};
		virtual void execute(const Entity& actor) {};
		virtual void execute(Entity& actor);

	private:

	};

	class NewGame : public Command
	{

		virtual void execute();



	};

	class Options : public Command {

		virtual void execute();


	};

	class Exit : public Command {
		virtual void execute() { exit(0); };

	};

	class Back : public Command {
		virtual void execute();

	};

	class Start : public Command {
		virtual void execute();

	};

	class moveUp : public Command {
		virtual void execute(Entity& actor);
	};
	class moveDown : public Command {
		virtual void execute(Entity& actor);
	};
	class moveUpLeft : public Command {
		virtual void execute(Entity& actor);
	};
	class moveDownLeft : public Command {
		virtual void execute(Entity& actor);
	};
	class moveUpRight : public Command {
		virtual void execute(Entity& actor);
	};
	class moveDownRight : public Command {
		virtual void execute(Entity& actor);
	};
	class moveLeft : public Command {
		virtual void execute(Entity& actor);
	};
	class moveRight : public Command {
		virtual void execute(Entity& actor);
	};
}
#endif