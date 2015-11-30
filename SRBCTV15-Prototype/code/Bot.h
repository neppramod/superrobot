#ifndef _BOT_
#define _BOT_
#include "Entity.h"
#include "Brain.h"

class Bot :
	public Entity
{
public:
	Bot();
	void update();
	~Bot();
private:
	Brains::Brain * brain; //AI's functionality
	int health;

};
#endif
