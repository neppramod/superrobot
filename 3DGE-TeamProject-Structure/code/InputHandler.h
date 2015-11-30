#ifndef _INPUTHANDLER_
#define _INPUTHANDLER_
#include "Command.h"
typedef Commands::Command Command;
class InputHandler
{
public:
	InputHandler();
	Command * handleInput();
	~InputHandler();
private:

	Command * keyW;
	Command * keyA;
	Command * keyS;
	Command * keyD;
	Command * keyWA;
	Command * keyWD;
	Command * keySA;
	Command * keySD;
};





#endif