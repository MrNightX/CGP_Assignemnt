
#ifndef _CHARACTER_ // Include Guards
#define _CHARACTER_

#include "GameObject.h"

using namespace std;



class Character : public GameObject
{
protected:
	int health;
	float enginePower;

public:
	// Constructors:
	Character();
	Character(int height, int width, int row, int col, int maxFrame, LPDIRECT3DTEXTURE9 texture, float mass, float rotationSpeed, int health);
	~Character();

	// Getters:
	int getHealth();
	float getEnginePower();

	// Setters:
	void setHealth(int health);
	void setEnginePower(float enginePower);

	// Methods:
	virtual void move() = 0;

};

#endif _CHARACTER_
