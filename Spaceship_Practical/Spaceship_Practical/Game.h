
#ifndef _GAME_
#define _GAME_

#include <vector>

#include "GameObject.h"
#include "WindowManager.h"
#include "D3DXManager.h"
#include "InputManager.h"
#include "FrameTimer.h"
#include "AudioManager.h"

class Game
{
protected:
	// Game Object:
	vector<GameObject> gameObjectList;

	// Framework Relation:
	WindowManager windowManager;
	D3DXManager d3dxManager;
	InputManager inputManager;
	FrameTimer* spriteFrameTimer;
	FrameTimer* textFrameTimer;
	AudioManager audioManager;

public:
	// Constructors & Destructor:
	Game();
	Game(HINSTANCE hInstance, int screenHeight, int screenWidth);
	~Game();

	// Getters:
	vector<GameObject> getGameObjectList();
	WindowManager getWindowManager();
	D3DXManager getD3DXManager();
	InputManager getInputManager();
	FrameTimer* getSpriteFrameTimer();
	FrameTimer* getTextFrameTimer();
	AudioManager getAudioManager();

	// Methods:
	virtual void initialize() = 0;
	// getInput from InputManager
	virtual void update() = 0;
	void render();
	void playSound();
	void clear();

	/*
	hr = D3DXCreateTextureFromFile(d3dDevice, "Pictures\\Spaceship.png", &texture);

	if (FAILED(hr))
	{
		MessageBox(NULL,
			"Error creating Spaceship.",
			"Sprite Creating Error",
			MB_OK);
		return 0;
	}
	*/

	/*
	for (int frameCount = 0; frameCount < frameTimer->framesToUpdate(); frameCount++)
	{
		// Implementation that affected by frames Add here...
	}
	*/

};

#endif _GAME_

