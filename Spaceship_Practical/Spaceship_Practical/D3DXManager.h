
#ifndef _D3DXMANAGER_
#define _D3DXMANAGER_

#include <d3d9.h> 
#include <d3dx9.h>

// Pragma to include directories as backup
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib") 

class D3DXManager
{
private:
	// Attributes from WindowManager
	HWND wndHandle;
	int wndHeight;
	int wndWidth;

	// Direct3D Object & Device
	IDirect3D9* direct3D9;
	IDirect3DDevice9* d3dDevice;

	// Sprite brushes
	LPD3DXSPRITE spriteInterface;
	LPD3DXFONT fontInterface;
	LPD3DXLINE lineInterface;

	// Handle to the result for D3DXManager
	HRESULT d3dxHR;

public:
	// Constructor & Destructor:
	D3DXManager();
	D3DXManager(HWND wndHandle, int wndHeight, int wndWidth);
	~D3DXManager();

	// Getters:
	IDirect3D9* getDirect3D9();
	IDirect3DDevice9* getD3DDevice();
	LPD3DXSPRITE getSpriteInterface();
	LPD3DXFONT getFontInterface();
	LPD3DXLINE getLineInterface();

	// Methods:
	bool createD3DDevice();
	bool createSpriteBrushes();
	void createTexture(LPCTSTR location, LPDIRECT3DTEXTURE9 targetTexture);
	// include row, col, maxFrame, height, width?
	void clearD3DX();
};

#endif _D3DXMANAGER_

