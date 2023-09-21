
#ifndef _MAINMENU_
#define _MAINMENU_

#include "Game.h"

class MainMenu : public Game
{
public:
	// Constuctor & Destructor:
	MainMenu();
	MainMenu(HINSTANCE hInstance, int screenHeight, int screenWidth);
	~MainMenu();

	// Method:
	void initialize() override;
	void update() override;
};

#endif _MAINMENU_

