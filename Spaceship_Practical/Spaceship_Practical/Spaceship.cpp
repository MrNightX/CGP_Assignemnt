#include "Spaceship.h"

Spaceship::Spaceship()
{

}

Spaceship::Spaceship(int height, int width, int row, int col, int maxFrame, LPDIRECT3DTEXTURE9 texture, float mass, float rotationSpeed, int health, float enginePower)
	: Character(height, width, row, col, maxFrame, texture, mass, rotationSpeed, health)
{
	this->enginePower = enginePower;
}

Spaceship::~Spaceship()
{

}

void Spaceship::move()
{
	vectorForce.x = enginePower * sin(rotationSpeed);
	vectorForce.y = enginePower * -cos(rotationSpeed);

	// Force: resistance, friction, ...


	vectorAcceleration += vectorForce / mass;

	vectorVelocity += vectorAcceleration;

	vectorPosition += vectorVelocity;

	// when input, update force in different dimension
	// resultant Force += other force add together
	
}