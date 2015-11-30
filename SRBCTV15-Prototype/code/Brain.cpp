#include "Brain.h"

namespace Brains {
	Brain::Brain()
	{
	}


	Brain::~Brain()
	{
	}

	UselessBrain::UselessBrain() {}
	UselessBrain::~UselessBrain() {}
	void UselessBrain::execute() {}

	BanzaiBrain::BanzaiBrain() {}
	BanzaiBrain::~BanzaiBrain() {}
	void BanzaiBrain::execute() {}

	StupidBrain::StupidBrain() {}
	StupidBrain::~StupidBrain() {}
	void StupidBrain::execute() {}

	AggressiveBrain::AggressiveBrain() {}
	AggressiveBrain::~AggressiveBrain() {}
	void AggressiveBrain::execute() {}

	DefensiveBrain::DefensiveBrain() {}
	DefensiveBrain::~DefensiveBrain() {}
	void DefensiveBrain::execute() {}

	FrightenedBrain::FrightenedBrain() {}
	FrightenedBrain::~FrightenedBrain() {}
	void FrightenedBrain::execute() {}
}