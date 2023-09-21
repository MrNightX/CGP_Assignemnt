#include "WindowManager.h"

WindowManager::WindowManager()
{
	
}

WindowManager::WindowManager(HINSTANCE hInstance)
{
	// Presets:
	this->hInstance = hInstance;
	this->screenHeight = 800;
	this->screenWidth = 600;

	// Window Relation:
	this->wndHandle = NULL;

	if (!createWindow())
	{
		MessageBox(NULL,
			"Error creating Window.",
			"Window Error",
			MB_OK);
	}
}

WindowManager::WindowManager(HINSTANCE hInstance, int screenHeight, int screenWidth)
{
	// Presets:
	this->hInstance = hInstance;
	this->screenHeight = 800;
	this->screenWidth = 600;

	// Window Relation:
	this->wndHandle = NULL;

	if (!createWindow())
	{
		MessageBox(NULL,
			"Error creating Window.",
			"Window Error",
			MB_OK);
	}
}

WindowManager::~WindowManager()
{

}

HWND WindowManager::getWndHandle()
{
	return wndHandle;
}

WNDCLASS WindowManager::getWndClass()
{
	return wndClass;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		// Destroying the window by quitting
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

		// Pressing the key
	case WM_KEYDOWN:
		// open up wParam to find what key
		switch (wParam)
		{
		case VK_ESCAPE:
		{
			PostQuitMessage(0);
			break;
		}

		}
		break;

	case WM_MOUSEMOVE:
	{
		break;
	}

	//	Default handling for other messages.
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

bool WindowManager::createWindow()
{
	// 1. Zeroes the memory of the wndClass, to prevent game crash due to data from previous wndClass with same name
	ZeroMemory(&wndClass, sizeof(wndClass));

	// 2. Set wndClass' parameters
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);	// black background
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					// cursor: standard arrow
	wndClass.hInstance = GetModuleHandle(NULL);						// return window handle that refers to a hInstance
	wndClass.lpfnWndProc = WindowProcedure;							// long pointer to function
	wndClass.lpszClassName = "My Window";							// long pointer to zero terminated string (sz ~ \0), there are different kind of string
	wndClass.style = CS_HREDRAW | CS_VREDRAW;						// horizontal redraw, vertical redraw

	// 3. Register wndClass
	RegisterClass(&wndClass);

	// 4. Create window based on preset wndClass' parameters
	wndHandle = CreateWindowEx(0, wndClass.lpszClassName, "DesolationX", WS_OVERLAPPEDWINDOW, 0, 0, screenHeight, screenWidth, NULL, NULL, wndClass.hInstance, NULL);

	// 5. Display Window
	ShowWindow(wndHandle, 1);

	// 6. Optional Default Cursor (Will be removed after replacing mouse pointer)
	ShowCursor(true);

	// 7. Window is successfully created
	return 1;
}

bool WindowManager::isWindowRunning()
{
	// 1. Check whether the window is running
	if (wndHandle == NULL)
	{
		// ...
		return false;
	}

	// 2. Define msg for msg receival for WinProc
	MSG msg;

	// 3. Zeroes the memory of the msg, to prevent game crash
	ZeroMemory(&msg, sizeof(msg));

	// 4. Infinite Loop to retrieve message constantly
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		// 4a. Terminate window if quit msg is received
		if (msg.message == WM_QUIT)
			return false;

		// 4b. Translate the message 
		TranslateMessage(&msg);

		// 4c. Send message to your window procedure
		DispatchMessage(&msg);
	}

	// 5. Return statement
	return true;
}

void WindowManager::clearWindow()
{
	// Free up the window's memory
	UnregisterClass(wndClass.lpszClassName, hInstance); // or GetModuleHandle(NULL);
}