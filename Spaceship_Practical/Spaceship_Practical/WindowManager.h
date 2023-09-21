
#ifndef _WINDOWMANAGER_
#define _WINDOWMANAGER_

#include <Windows.h>
#define WIN32_LEAN_AND_MEAN

class WindowManager
{
private:
	// Presets:
	HINSTANCE hInstance;
	int screenHeight;
	int screenWidth;
	
	// Window Relation:
	HWND wndHandle;
	WNDCLASS wndClass;

public:
	// Constructor & Destructor:
	WindowManager();
	WindowManager(HINSTANCE hInstance);
	WindowManager(HINSTANCE hInstance, int screenHeight, int screenWidth);
	~WindowManager();

	// Getters:
	HWND getWndHandle();
	WNDCLASS getWndClass();

	// Method:
	bool createWindow();
	bool isWindowRunning();
	void clearWindow();
};

#endif _WINDOWMANAGER_

