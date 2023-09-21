
#ifndef _LEVEL1_
#define _LEVEL1_

#include "Game.h"

class Level1 : public Game
{

public:
	// Constructor & Destructor:
	Level1();
	~Level1();

	// Methods:
	void initialize() override;
	void update() override;
};

#endif _LEVEL1_

