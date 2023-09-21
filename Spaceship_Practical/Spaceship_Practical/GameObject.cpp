#include "GameObject.h"

GameObject::GameObject()
{

}

GameObject::GameObject(int height, int width, int row, int col, int maxFrame, LPDIRECT3DTEXTURE9 texture, float mass, float rotationSpeed)
{
	this->vectorPosition = D3DXVECTOR2(0.0f, 0.0f);

	this->spriteManager = SpriteManager(height, width, row, col, maxFrame, texture, vectorPosition);
	this->mass = mass;
	this->rotationSpeed = rotationSpeed;

	this->vectorForce = D3DXVECTOR2(0.0f, 0.0f);
	this->vectorAcceleration = D3DXVECTOR2(0.0f, 0.0f);
	this->vectorVelocity = D3DXVECTOR2(0.0f, 0.0f);

}

GameObject::~GameObject()
{

}

D3DXVECTOR2 GameObject::getVectorPosition()
{
	return vectorPosition;
}

SpriteManager GameObject::getSpriteManager()
{
	return spriteManager;
}

RECT GameObject::getHitBox()
{
	return hitBox;
}

D3DXVECTOR2 GameObject::getVectorForce()
{
	return vectorForce;
}

D3DXVECTOR2 GameObject::getVectorAcceleration()
{
	return vectorAcceleration;
}

D3DXVECTOR2 GameObject::getVectorVelocity()
{
	return vectorVelocity;
}

float GameObject::getMass()
{
	return mass;
}

float GameObject::getRotationSpeed()
{
	return rotationSpeed;
}

void GameObject::setHitBox(RECT hitBox)
{
	this->hitBox = hitBox;
}

void GameObject::setVectorForce(D3DXVECTOR2 vectorForce)
{
	this->vectorForce = vectorForce;
}

void GameObject::setVectorAcceleration(D3DXVECTOR2 vectorAcceleration)
{
	this->vectorAcceleration = vectorAcceleration;
}

void GameObject::setVectorVelocity(D3DXVECTOR2 vectorVelocity)
{
	this->vectorVelocity = vectorVelocity;
}

void GameObject::setMass(float mass)
{
	this->mass = mass;
}

void GameObject::setRotationSpeed(float rotationSpeed)
{
	this->rotationSpeed = rotationSpeed;
}

// Method:
void GameObject::addVectorForce(D3DXVECTOR2 externalForce)
{
	this->vectorForce += externalForce;
}

void GameObject::addVectorAcceleration(D3DXVECTOR2 externalAcceleration)
{
	this->vectorAcceleration += externalAcceleration;
}

void GameObject::addVectorVelocity(D3DXVECTOR2 externalVelocity)
{
	this->vectorVelocity += externalVelocity;
}

void GameObject::addVectorPosition(D3DXVECTOR2 externalDisplacement)
{
	this->vectorPosition += externalDisplacement;
}
