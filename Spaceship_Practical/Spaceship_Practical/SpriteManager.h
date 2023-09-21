
#ifndef _SPRITEMANAGER_
#define _SPRITEMANAGER_

#include <d3dx9.h>

class SpriteManager
{
private:
	// Presets:
	int height;
	int width;
	int row;
	int col;
	int maxFrame;
	int spriteHeight;
	int spriteWidth;
	LPDIRECT3DTEXTURE9 texture;

	// Variables:
	int rowIndex;
	int colIndex;
	RECT clipRect;
	D3DXMATRIX matrix;
	D3DXVECTOR2 scalingCenterPoint;
	D3DXVECTOR2 scalingFactor;
	float scalingRotationFactor;
	float rotation;
	D3DXVECTOR2 rotationCenterPoint;
	int redValue;
	int greenValue;
	int blueValue;

public:
	// Constructor & Destructor:
	SpriteManager();
	SpriteManager(int height, int width, int row, int col, int maxFrame, LPDIRECT3DTEXTURE9 texture, D3DXVECTOR2 position);
	~SpriteManager();

	// Getters:
	int getHeight();
	int getWidth();
	int getRow();
	int getCol();
	int getMaxFrame();
	int getSpriteHeight();
	int getSpriteWidth();
	LPDIRECT3DTEXTURE9 getTexture();
	int getRowIndex();
	int getColIndex();
	RECT getClipRect();
	D3DXMATRIX getMatrix();
	D3DXVECTOR2 getScalingCenterPoint();
	D3DXVECTOR2 getScalingFactor();
	float getScalingRotationFactor();
	float getRotation();
	D3DXVECTOR2 getRotationCenterPoint();
	int getRedValue();
	int getGreenValue();
	int getBlueValue();

	// Setters:
	void setHeight(int height);
	void setWidth(int width);
	void setRow(int row);
	void setCol(int col);
	void setMaxFrame(int maxFrame);
	void setSpriteHeight(int spriteHeight);
	void setSpriteWidth(int spriteWidth);
	void setTexture(LPDIRECT3DTEXTURE9 texture);
	void setRowIndex(int rowIndex);
	void setColIndex(int colIndex);
	void setClipRect(RECT clipRect);
	void setMatrix(D3DXMATRIX matrix);
	void setScalingCenterPoint(D3DXVECTOR2 scalingCenterPoint);
	void setScalingFactor(D3DXVECTOR2 scalingFactor);
	void setScalingRotationFactor(float scalingRotationFactor);
	void setRotation(float rotation);
	void setRotationCenterPoint(D3DXVECTOR2 rotationCenterPoint);
	void setRedValue(int redValue);
	void setGreenValue(int greenValue);
	void setBlueValue(int blueValue);

	// Methods:
	int incRowIndex();
	int incColIndex();
};

#endif _SPRITEMANAGER_



