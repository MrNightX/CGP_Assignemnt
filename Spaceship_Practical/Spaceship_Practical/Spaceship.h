
#ifndef _SPACESHIP_
#define _SPACESHIP_

#include "Character.h"

class Spaceship : public Character
{
private:
	// Stats:
	// Unity: each game object has init & update

public:
	// Constructor & Destructor:
	Spaceship();
	// !!
	Spaceship(int height, int width, int row, int col, int maxFrame, LPDIRECT3DTEXTURE9 texture, float mass, float rotationSpeed, int health, float enginePower);
	~Spaceship();

	// Methods:
	void move() override;
	
};

#endif _SPACESHIP_

