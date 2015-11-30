#ifndef _BRAIN_
#define _BRAIN_
namespace Brains {
	class Brain
	{
	public:
		Brain();
		~Brain();
		void virtual execute() = 0;
	};

	class UselessBrain : Brain
	{
		UselessBrain();
		~UselessBrain();
		void execute();
	};

	class BanzaiBrain : Brain {
		BanzaiBrain();
		~BanzaiBrain();
		void execute();
	};

	class StupidBrain : Brain {
		StupidBrain();
		~StupidBrain();
		void execute();
	};

	class AggressiveBrain : Brain {
		AggressiveBrain();
		~AggressiveBrain();
		void execute();
	};

	class DefensiveBrain : Brain {
		DefensiveBrain();
		~DefensiveBrain();
		void execute();
	};

	class FrightenedBrain : Brain {
		FrightenedBrain();
		~FrightenedBrain();
		void execute();
	};

}
#endif