#include "Game.h"

Game::Game()
{

}

Game::Game(HINSTANCE hInstance, int screenHeight, int screenWidth)
{
	this->windowManager = WindowManager(hInstance, screenHeight, screenWidth);
	this->d3dxManager = D3DXManager(windowManager.getWndHandle(), screenHeight, screenWidth);
	this->inputManager = InputManager(windowManager.getWndHandle());

	// ...
}

Game::~Game()
{

}

vector<GameObject> Game::getGameObjectList()
{
	return gameObjectList;
}

WindowManager Game::getWindowManager()
{
	return windowManager;
}

D3DXManager Game::getD3DXManager()
{
	return d3dxManager;
}

InputManager Game::getInputManager()
{
	return inputManager;
}

FrameTimer* Game::getSpriteFrameTimer()
{
	return spriteFrameTimer;
}

FrameTimer* Game::getTextFrameTimer()
{
	return textFrameTimer;
}

AudioManager Game::getAudioManager()
{
	return audioManager;
}

void Game::render()
{
	// ********** Step 1: Begin scene **********
	// 1. Clear the back buffer
	d3dxManager.getD3DDevice()->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0);

	// 2. Begin the scene
	d3dxManager.getD3DDevice()->BeginScene();



	// ********** Step 2: Draw scene **********
	// 1. Begin to draw by using sprite brush
	//    alpha blend is specified to ensure that the sprite will render the background with alpha.
	d3dxManager.getSpriteInterface()->Begin(D3DXSPRITE_ALPHABLEND);
	d3dxManager.getLineInterface()->Begin();

	// ----------------------------------------------
	// 2. Draw the sprites: // !!
	for (int gameObjectCount = 0; gameObjectCount < gameObjectList.size(); gameObjectCount++)
	{
		// 2a. SetTransform for each sprites
		// d3dxManager.getSpriteInterface()->SetTransform(&gameObjectList.at(gameObjectCount).getSpriteManager().getMatrix());

		// 2b. Draw the sprites
		/*
		d3dxManager.getSpriteInterface()->Draw
		(
			gameObjectList.at(gameObjectCount).getSpriteManager().getTexture(),
			&gameObjectList.at(gameObjectCount).getSpriteManager().getClipRect(),
			NULL,
			NULL,
			D3DCOLOR_XRGB
			(
				gameObjectList.at(gameObjectCount).getSpriteManager().getRedValue(), 
				gameObjectList.at(gameObjectCount).getSpriteManager().getGreenValue(), 
				gameObjectList.at(gameObjectCount).getSpriteManager().getBlueValue()
			)
		);
		*/
	}

	// 3. Draw fonts:
	// d3dxManager.getFontInterface()->DrawText(sprite, c, -1, NULL, 0, D3DCOLOR_XRGB(255, 255, 255));


	// 4. Draw lines:

	// Add here...



	// ----------------------------------------------

	// 5. End sprite drawing
	d3dxManager.getSpriteInterface()->End();
	d3dxManager.getLineInterface()->End();



	// ********** Step 4: End scene **********
	// 1. End the scene
	d3dxManager.getD3DDevice()->EndScene();

	// 2. Present the back buffer to screen
	d3dxManager.getD3DDevice()->Present(NULL, NULL, NULL, NULL);
}

void Game::playSound()
{
	audioManager.initializeAudio();
	audioManager.loadSounds();
	// audioManager.loadSoundTrack();
	audioManager.playSoundtrack();
}

void Game::clear()
{
	// Clear directInput
	inputManager.clearDInput();
	
	// Clear font & line?

	// Clear sprite texture for each of gameObject
	for (int gameObjectCount = 0; gameObjectCount < gameObjectList.size(); gameObjectCount++)
	{
		gameObjectList.at(gameObjectCount).getSpriteManager().getTexture()->Release();
		gameObjectList.at(gameObjectCount).getSpriteManager().setTexture(NULL);
	}

	// Clear D3DX
	d3dxManager.clearD3DX();

	// Clear WIndow
	windowManager.clearWindow();
}
