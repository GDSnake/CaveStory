#include "sprite.h"
#include "globals.h"
#include <iostream>


sprite::sprite()
{
}

sprite::sprite(graphics &graphics, const string & filePath, int sourceX, int sourceY, int width, int height, float posX, float posY):
	_x(posX),
	_y(posY)
{
	this->_sourceRect.x = sourceX;
	this->_sourceRect.y = sourceY;
	this->_sourceRect.w = width;
	this->_sourceRect.h = height;

	this->_spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));
	if (this->_spriteSheet == NULL) {
		cout << endl << "Error: Unable to load image" << endl;
	}

	this->_boundingBox = rectangle(this->_x, this->_y, width * globals::SPRITE_SCALE, height * globals::SPRITE_SCALE);
}


sprite::~sprite()
{
}

void sprite::update()
{
	this->_boundingBox = rectangle(this->_x, this->_y, _sourceRect.w * globals::SPRITE_SCALE, _sourceRect.h * globals::SPRITE_SCALE);
}

void sprite::draw(graphics & graphics, int x, int y)
{
	SDL_Rect destinationRectange = { x, y, this->_sourceRect.w * globals::SPRITE_SCALE, this->_sourceRect.h * globals::SPRITE_SCALE};
	graphics.blitSurface(this->_spriteSheet, &this->_sourceRect, &destinationRectange);
}

const rectangle sprite::getBoundingBox() const
{
	return this->_boundingBox;
}

/*getCollisionSide
* Determine which side the collision happened on
*/
const sides::Side sprite::getCollisionSide(rectangle &other) const
{
	int amtRight, amtLeft, amtTop, amtBottom;
	amtRight = this->getBoundingBox().getRight() - other.getLeft();
	amtLeft = other.getRight() - this->getBoundingBox().getLeft();
	amtTop = other.getBottom() - this->getBoundingBox().getTop();
	amtBottom = this->getBoundingBox().getBottom() - other.getTop();

	int vals[4] = { abs(amtRight), abs(amtLeft), abs(amtTop), abs(amtBottom) };
	int lowest = vals[0];
	for (int i = 0; i < 4; i++) {
		if (vals[i] < lowest) {
			lowest = vals[i];
		}
	}
	return
		lowest == abs(amtRight) ? sides::RIGHT :
		lowest == abs(amtLeft) ? sides::LEFT :
		lowest == abs(amtTop) ? sides::TOP :
		lowest == abs(amtBottom) ? sides::BOTTOM :
		sides::NONE;
}
