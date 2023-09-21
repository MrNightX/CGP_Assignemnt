#include "InputManager.h"

InputManager::InputManager()
{
	
}

InputManager::InputManager(HWND wndHandle)
{
	// 1. get attributes from WindowManager
	this->wndHandle = wndHandle;

	// 2. clean up previous work
	clearDInput();

	// 3. create DirectInput
	if (!createDInput())
	{
		return;
	}
}

InputManager::~InputManager()
{

}

LPDIRECTINPUTDEVICE8 InputManager::getDInputKeyboardDevice()
{
	return dInputKeyboardDevice;
}

LPDIRECTINPUTDEVICE8 InputManager::getDInputMouseDevice()
{
	return dInputMouseDevice;
}

bool InputManager::createDInput()
{
	// 1. Create the Direct Input object
	diHR = DirectInput8Create(GetModuleHandle(NULL), 0x0800, IID_IDirectInput8, (void**)&dInput, NULL);

	// 2. Check whether DirectInput Object is successfully created
	if (FAILED(diHR))
	{
		MessageBox(NULL,
			"Error creating directInput object.",
			"DI Object Creating Error",
			MB_OK);
		return 0;
	}

	// 3. Create the keyboard device
	diHR = dInput->CreateDevice(GUID_SysKeyboard, &dInputKeyboardDevice, NULL);

	// 4. Check whether Keyboard Device is successfully created
	if (FAILED(diHR))
	{
		MessageBox(NULL,
			"Error creating directInput keyboard device.",
			"DI Device Creating Error",
			MB_OK);
		return 0;
	}

	// 5. Create the mouse device
	diHR = dInput->CreateDevice(GUID_SysMouse, &dInputMouseDevice, NULL);

	// 6. Check whether Mouse Device is successfully created
	if (FAILED(diHR))
	{
		MessageBox(NULL,
			"Error creating directInput mouse device.",
			"DI Device Creating Error",
			MB_OK);
		return 0;
	}

	// 7. Set the input data format for keyboard & mouse
	dInputKeyboardDevice->SetDataFormat(&c_dfDIKeyboard);
	dInputMouseDevice->SetDataFormat(&c_dfDIMouse);

	// 8. Set the cooperative level for keyboard & mouse
	dInputKeyboardDevice->SetCooperativeLevel(wndHandle, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	dInputMouseDevice->SetCooperativeLevel(wndHandle, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

	// 9. The DirectInput Object & Devices are successfully created
	return 1;
}

void InputManager::getInput()
{
	// ********** Step 1: Acquire Keyboard **********
	dInputKeyboardDevice->Acquire();

	// ********** Step 2: Get Keyboard Key State **********
	dInputKeyboardDevice->GetDeviceState(256, diKeys);

	// ********** Step 3: Check Key State & Assign Status **********
	for (int keyCode = 0; keyCode < 256; keyCode++)
	{
		// Necessary DInput Keys List:
		// For Movement: DIK_LEFT, DIK_RIGHT, DIK_UP, DIK_DOWN
		//               DIK_A, DIK_D, DIK_W, DIK_S

		// Check State & Assign Status
		if (KEYDOWN(diKeys, keyCode))
		{
			keyDownStatus[keyCode] = true;
		}
		else
		{
			keyDownStatus[keyCode] = false;
		}
	}



	// ********** Step 4: Acquire Mouse **********
	dInputMouseDevice->Acquire();

	// ********** Step 5: Get Mouse Button State **********
	dInputMouseDevice->GetDeviceState(sizeof(mouseState), (LPVOID)&mouseState);

	// ********** Step 6: Check Button State & Assign Status **********
	for (int mouseCode = 0; mouseCode < 5; mouseCode++)
	{
		// DInput Mouse Button List:
		// [0] - Left Mouse Button
		// [1] - Right Mouse Button
		// [2] - Middle Mouse Button
		// [3] - First Extra Mouse Button
		// [4] - Second Extra Mouse Button

		// Check State & Assign Status
		if (BUTTONDOWN(mouseState, mouseCode))
		{
			btnDownStatus[mouseCode] = true;
		}
		else
		{
			btnDownStatus[mouseCode] = false;
		}
	}

}

bool InputManager::getKeyDownState(BYTE key)
{
	return keyDownStatus[key];
}

bool InputManager::getBtnDownState(MOUSEBUTTON mouseBtn)
{
	return btnDownStatus[mouseBtn];
}

void InputManager::clearDInput()
{
	// ********** Step 1: Clear directInput Devices **********

	// 1. Unacquire dInput mouse device
	dInputMouseDevice->Unacquire();

	// 2. Release dInput mouse device
	dInputMouseDevice->Release();

	// 3. Reset dInput mouse device to NULL
	dInputMouseDevice = NULL;

	// 4. Unacquire dInput keyboard device
	dInputKeyboardDevice->Unacquire();

	// 5. Release dInput keyboard device
	dInputKeyboardDevice->Release();

	// 6. Reset dInput keyboard device to NULL
	dInputKeyboardDevice = NULL;



	// ********** Step 2: Clear directInput Object **********

	// 1. Release the directInput object when exiting.
	dInput->Release();
	// 2. Reset directInput object to NULL
	dInput = NULL;
}
