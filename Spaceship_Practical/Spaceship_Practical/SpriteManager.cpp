#include "SpriteManager.h"

// Null Constructor
SpriteManager::SpriteManager()
{

}

// Full Constructor
SpriteManager::SpriteManager(int height, int width, int row, int col, int maxFrame, LPDIRECT3DTEXTURE9 texture, D3DXVECTOR2 position)
{
	this->height = height;
	this->width = width;
	this->row = row;
	this->col = col;
	this->maxFrame = maxFrame;

	this->spriteHeight = height / row;
	this->spriteWidth = width / col;

	this->texture = texture;

	this->rowIndex = 0;
	this->colIndex = 0;

	this->clipRect.top = rowIndex * spriteHeight;
	this->clipRect.bottom = clipRect.top + spriteHeight;
	this->clipRect.left = colIndex * spriteWidth;
	this->clipRect.right = clipRect.left + spriteWidth;

	this->scalingCenterPoint = D3DXVECTOR2(spriteWidth / 2, spriteHeight / 2);
	this->scalingFactor = D3DXVECTOR2(1.0f, 1.0f);
	this->rotationCenterPoint = D3DXVECTOR2(spriteWidth / 2, spriteHeight / 2);
	this->scalingRotationFactor = 0.0f;
	this->rotation = 0.0f;

	D3DXMatrixTransformation2D(&matrix,
		&scalingCenterPoint,
		scalingRotationFactor,
		&scalingFactor,
		&rotationCenterPoint,
		rotation,
		&position);

	this->redValue = 255;
	this->greenValue = 255;
	this->blueValue = 255;

}

// Destructor
SpriteManager::~SpriteManager()
{

}

// Getters:
int SpriteManager::getHeight()
{
	return height;
}

int SpriteManager::getWidth()
{
	return width;
}

int SpriteManager::getRow()
{
	return row;
}

int SpriteManager::getCol()
{
	return col;
}

int SpriteManager::getMaxFrame()
{
	return maxFrame;
}

int SpriteManager::getSpriteHeight()
{
	return spriteHeight;
}

int SpriteManager::getSpriteWidth()
{
	return spriteWidth;
}

LPDIRECT3DTEXTURE9 SpriteManager::getTexture()
{
	return texture;
}

int SpriteManager::getRowIndex()
{
	return rowIndex;
}

int SpriteManager::getColIndex()
{
	return colIndex;
}

RECT SpriteManager::getClipRect()
{
	return clipRect;
}

D3DXMATRIX SpriteManager::getMatrix()
{
	return matrix;
}

D3DXVECTOR2 SpriteManager::getScalingCenterPoint()
{
	return scalingCenterPoint;
}

D3DXVECTOR2 SpriteManager::getScalingFactor()
{
	return scalingFactor;
}

float SpriteManager::getScalingRotationFactor()
{
	return scalingRotationFactor;
}

float SpriteManager::getRotation()
{
	return rotation;
}

D3DXVECTOR2 SpriteManager::getRotationCenterPoint()
{
	return rotationCenterPoint;
}

int SpriteManager::getRedValue()
{
	return redValue;
}

int SpriteManager::getGreenValue()
{
	return greenValue;
}

int SpriteManager::getBlueValue()
{
	return blueValue;
}

// Setters:
void SpriteManager::setHeight(int height)
{
	this->height = height;
}

void SpriteManager::setWidth(int width)
{
	this->width = width;
}

void SpriteManager::setRow(int row)
{
	this->row = row;
}

void SpriteManager::setCol(int col)
{
	this->col = col;
}

void SpriteManager::setMaxFrame(int maxFrame)
{
	this->maxFrame = maxFrame;
}

void SpriteManager::setSpriteHeight(int spriteHeight)
{
	this->spriteHeight = spriteHeight;
}

void SpriteManager::setSpriteWidth(int spriteWidth)
{
	this->spriteWidth = spriteWidth;
}

void SpriteManager::setTexture(LPDIRECT3DTEXTURE9 texture)
{
	this->texture = texture;
}

void SpriteManager::setRowIndex(int rowIndex)
{
	this->rowIndex = rowIndex;
}

void SpriteManager::setColIndex(int colIndex)
{
	this->colIndex = colIndex;
}

void SpriteManager::setClipRect(RECT clipRect)
{
	this->clipRect = clipRect;
}

void SpriteManager::setMatrix(D3DXMATRIX matrix)
{
	this->matrix = matrix;
}

void SpriteManager::setScalingCenterPoint(D3DXVECTOR2 scalingCenterPoint)
{
	this->scalingCenterPoint = scalingCenterPoint;
}

void SpriteManager::setScalingFactor(D3DXVECTOR2 scalingFactor)
{
	this->scalingFactor = scalingFactor;
}

void SpriteManager::setScalingRotationFactor(float scalingRotationFactor)
{
	this->scalingRotationFactor = scalingRotationFactor;
}

void SpriteManager::setRotation(float rotation)
{
	this->rotation = rotation;
}

void SpriteManager::setRotationCenterPoint(D3DXVECTOR2 rotationCenterPoint)
{
	this->rotationCenterPoint = rotationCenterPoint;
}

void SpriteManager::setRedValue(int redValue)
{
	this->redValue = redValue;
}

void SpriteManager::setGreenValue(int greenValue)
{
	this->greenValue = greenValue;
}

void SpriteManager::setBlueValue(int blueValue)
{
	this->blueValue = blueValue;
}

// Method:
int SpriteManager::incRowIndex()
{
	rowIndex++;
	return rowIndex;
}

int SpriteManager::incColIndex()
{
	colIndex++;
	return colIndex;
}

