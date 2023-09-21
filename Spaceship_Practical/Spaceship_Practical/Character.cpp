#include "Character.h"

Character::Character()
{

}

Character::Character(int height, int width, int row, int col, int maxFrame, LPDIRECT3DTEXTURE9 texture, float mass, float rotationSpeed, int health)
	: GameObject(height, width, row, col, maxFrame, texture, mass, rotationSpeed)
{
	this->health = health;
}

Character::~Character()
{

}

int Character::getHealth()
{
	return health;
}

float Character::getEnginePower()
{
	return enginePower;
}

void Character::setHealth(int health)
{
	this->health = health;
}

void Character::setEnginePower(float enginePower)
{
	this->enginePower = enginePower;
}
