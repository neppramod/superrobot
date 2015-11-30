#pragma once
#include "IBehavior.h"
class PawnBehavior :
	public IBehavior
{
public:
	PawnBehavior();
	~PawnBehavior();

	virtual void update(GameObject *object, float elapsedSeconds);

};

