#include "D3DXManager.h"

D3DXManager::D3DXManager()
{

}

D3DXManager::D3DXManager(HWND wndHandle, int wndHeight, int wndWidth)
{
	// 1. get attributes from WindowManager
	this->wndHandle = wndHandle;
	this->wndHeight = wndHeight;
	this->wndWidth = wndWidth;

	// 2. clean up previous work
	this->direct3D9 = Direct3DCreate9(D3D_SDK_VERSION);
	clearD3DX();

	// 3. create d3dDevice
	if (!createD3DDevice())
	{
		return;
	}

	// 4. create sprite brushes
	if (!createSpriteBrushes())
	{
		return;
	}
}

D3DXManager::~D3DXManager()
{

}

IDirect3D9* D3DXManager::getDirect3D9()
{
    return direct3D9;
}

IDirect3DDevice9* D3DXManager::getD3DDevice()
{
    return d3dDevice;
}

LPD3DXSPRITE D3DXManager::getSpriteInterface()
{
    return spriteInterface;
}

LPD3DXFONT D3DXManager::getFontInterface()
{
    return fontInterface;
}

LPD3DXLINE D3DXManager::getLineInterface()
{
    return lineInterface;
}

bool D3DXManager::createD3DDevice()
{
	// 1. Define how the screen presents.
	D3DPRESENT_PARAMETERS d3dPP;
	ZeroMemory(&d3dPP, sizeof(d3dPP));

	// 2. Set Direct3D Pointers' Parameters
	d3dPP.Windowed = true; // For Full screen
	d3dPP.SwapEffect = D3DSWAPEFFECT_DISCARD; // swap memory to display graphics
	d3dPP.BackBufferFormat = D3DFMT_X8R8G8B8; // transparency RGB value in 8-bit
	d3dPP.BackBufferCount = 1;
	d3dPP.BackBufferWidth = wndWidth;
	d3dPP.BackBufferHeight = wndHeight;
	d3dPP.hDeviceWindow = wndHandle;

	// 3. Create a Direct3D 9 device.
	d3dxHR = direct3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, wndHandle, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dPP, &d3dDevice);
	// adapter: D3DADAPTER_DEFAULT ~ int, represent which graphics card to invoke
	// deviceType (important): 3 types of virtual graphic card (HAL, REF (emulator), SW)

	// 4. Check whether Direct3D9 Device is successfully created
	if (FAILED(d3dxHR))
	{
		MessageBox(NULL,
			"Error creating D3D Device.",
			"Direct3D Device Error",
			MB_OK);
		return 0;
	}

	// 5. The Direct3D9 Device is successfully created
	return 1;
}

bool D3DXManager::createSpriteBrushes()
{
	// 1. Create sprite brush
	this->d3dxHR = D3DXCreateSprite(d3dDevice, &spriteInterface);

	// 2. Check whether sprite brush is successfully created
	if (FAILED(d3dxHR))
	{
		MessageBox(NULL,
			"Error creating sprite brush.",
			"Sprite Brush Creating Error",
			MB_OK);
		return 0;
	}

	// 3. Create font brush
	this->d3dxHR = D3DXCreateFont(d3dDevice, 25, 0, 0, 1, false,
		DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "Arial", &fontInterface);

	// 4. Check whether font brush is successfully created
	if (FAILED(d3dxHR))
	{
		MessageBox(NULL,
			"Error creating font brush.",
			"Font Brush Creating Error",
			MB_OK);
		return 0;
	}

	// 5. Create line brush
	this->d3dxHR = D3DXCreateLine(d3dDevice, &lineInterface);

	// 6. Check whether font brush is successfully created
	if (FAILED(d3dxHR))
	{
		MessageBox(NULL,
			"Error creating line brush.",
			"Line Brush Creating Error",
			MB_OK);
		return 0;
	}

	// 7. The sprite brushes are successfully created
	return 1;
}

void D3DXManager::createTexture(LPCTSTR location, LPDIRECT3DTEXTURE9 targetTexture)
{
	D3DXCreateTextureFromFileEx(d3dDevice, location, NULL, NULL,
		D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(0, 0, 0),
		NULL, NULL, &targetTexture);
}

void D3DXManager::clearD3DX()
{
	// 1. Clear sprite brushes (Reversal Order)
	lineInterface->Release();
	lineInterface = NULL;

	fontInterface->Release();
	fontInterface = NULL;

	spriteInterface->Release();
	spriteInterface = NULL;

	// 2. Release the device when exiting.
	d3dDevice->Release();
	d3dDevice = NULL;
}
