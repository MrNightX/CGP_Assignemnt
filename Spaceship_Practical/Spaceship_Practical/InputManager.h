
#ifndef _INPUTMANAGER_
#define _INPUTMANAGER_

#define DIRECTINPUT_VERSION 0x0800 
#define KEYDOWN(name, key) (name[key] & 0x80)
#define BUTTONDOWN(name, key) (name.rgbButtons[key] & 0x80)
#include <dinput.h>

// Pragma to include directories as backup
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

#include <vector>

using namespace std;

class InputManager
{
private:
	// Attributes from WindowManager
	HWND wndHandle;

	// DInput Object
	LPDIRECTINPUT8 dInput;

	// DInput Devices
	LPDIRECTINPUTDEVICE8 dInputKeyboardDevice;
	LPDIRECTINPUTDEVICE8 dInputMouseDevice;

	// DInput & Status
	BYTE diKeys[256];
	bool keyDownStatus[256];
	DIMOUSESTATE mouseState;
	bool btnDownStatus[5];

	// DInput Mouse Position
	LONG currentXPos;
	LONG currentYPos;
	/*currentXPos += mouseState.lX;
	currentYPos += mouseState.lY;*/

	// Handle to the result
	HRESULT diHR;

public:
	// Enumeration:
	enum MOUSEBUTTON {MOUSE_BTN_LEFT, MOUSE_BTN_RIGHT, MOUSE_BTN_MID, MOUSE_BTN_EXTRA1, MOUSE_BTN_EXTRA2};
	
	// Constructor & Destructor:
	InputManager();
	InputManager(HWND wndHandle);
	~InputManager();

	// Getters:
	LPDIRECTINPUTDEVICE8 getDInputKeyboardDevice();
	LPDIRECTINPUTDEVICE8 getDInputMouseDevice();
	
	// Methods:
	bool createDInput();
	void getInput(); // getInputState
	bool getKeyDownState(BYTE key);
	bool getBtnDownState(MOUSEBUTTON mouseBtn);
	void clearDInput();
};

#endif _INPUTMANAGER_
