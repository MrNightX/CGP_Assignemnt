
#ifndef _GAMEOBJECT_
#define _GAMEOBJECT_

#include "SpriteManager.h"

class GameObject
{
protected:

	// Vector Position 
	D3DXVECTOR2 vectorPosition;

	// Sprite
	SpriteManager spriteManager;

	// Physics
	RECT hitBox;
	D3DXVECTOR2 vectorForce;
	D3DXVECTOR2 vectorAcceleration;
	D3DXVECTOR2 vectorVelocity;
	float mass;
	float rotationSpeed;

public:
	// Constructor & Destructor
	GameObject();
	GameObject(int height, int width, int row, int col, int maxFrame, LPDIRECT3DTEXTURE9 texture, float mass, float rotationSpeed);
	~GameObject();

	// Getters:
	D3DXVECTOR2 getVectorPosition();
	SpriteManager getSpriteManager();
	RECT getHitBox();
	D3DXVECTOR2 getVectorForce();
	D3DXVECTOR2 getVectorAcceleration();
	D3DXVECTOR2 getVectorVelocity();
	float getMass();
	float getRotationSpeed();

	// Setters:
	void setVectorPosition(D3DXVECTOR2 vectorPosition);
	void setHitBox(RECT hitBox);
	void setVectorForce(D3DXVECTOR2 vectorForce);
	void setVectorAcceleration(D3DXVECTOR2 vectorAcceleration);
	void setVectorVelocity(D3DXVECTOR2 vectorVelocity);
	void setMass(float mass);
	void setRotationSpeed(float rotationSpeed);

	// Method:
	void addVectorForce(D3DXVECTOR2 externalForce);
	void addVectorAcceleration(D3DXVECTOR2 externalAcceleration);
	void addVectorVelocity(D3DXVECTOR2 externalVelocity);
	void addVectorPosition(D3DXVECTOR2 externalDisplacement);
};

#endif _GAMEOBJECT_



