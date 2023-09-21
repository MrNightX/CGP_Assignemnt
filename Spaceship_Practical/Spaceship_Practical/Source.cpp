// ********** Directories & Libraries Section **********

// 1. Non-Window related libraries
#include <iostream> // For Testing by using console



// 2. Window related libraries & definitions
#include <vector>

// Add Preprocessors here...



// 3. User-Defined Libraries & Definitions (Guards Included)
#include "Game.h"
#include "MainMenu.h"



// 5. Standard Namespacing for easy coding
using namespace std;

// GameStateManager



// WinMain / console main function
//	use int main if you want to have a console to print out message
int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)

//	use WinMain if you don't want the console
// int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	Game* gameDriver = new MainMenu(hInstance, 800, 600);

	// ********** Step 1: Initialize Framework **********
	// if at(0), initialize framework, else not manipulate framework**
	// gameDriver = new MainMenu(hInstance, 800, 600);

	// ********** Step 2: Initialize Game **********
	// Game -> initialize();
	gameDriver->getWindowManager().createWindow();

	// ********** Step 3: Infinite Looping **********
	while (gameDriver->getWindowManager().isWindowRunning())
	{
		// 3a. GetInput
		gameDriver->getInputManager().getInput();

		// 3b. Update
		// gameDriver->update();

		// 3c. Render
		// gameDriver->render();

	}

	// ********** Step 4: Clear Game & Framework **********
	gameDriver->clear();

	// ********** Final Step: Return Statement for console testing **********
	return 0;

}
//--------------------------------------------------------------------