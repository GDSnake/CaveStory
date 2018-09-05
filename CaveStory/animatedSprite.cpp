#include "animatedSprite.h"
#include "graphics.h"
#include "sprite.h"


/*animatedSprite class
* Animates our sprites
*/


animatedSprite::animatedSprite()
{
}

animatedSprite::animatedSprite(graphics & graphics, const string &filePath, int sourceX, int sourceY, int width, int height,
	float posX, float posY, float timeToUpdate) :
	sprite(graphics, filePath, sourceX, sourceY, width, height, posX, posY),
	_frameIndex(0),
	_timeElapsed(0),
	_timeToUpdate(timeToUpdate),
	_visible(true),
	_currentAnimationOnce(false),
	_currentAnimation("")
{
}

void animatedSprite::playAnimation(string animation, bool once)
{
	this->_currentAnimationOnce = once;
	if (this->_currentAnimation != animation) {
		this->_currentAnimation = animation;
		this->_frameIndex = 0;
	}
}

void animatedSprite::update(int elapsedTime)
{
	sprite::update();
	
	this->_timeElapsed += elapsedTime;
	if (this->_timeElapsed > this->_timeToUpdate) {
		this->_timeElapsed -= _timeToUpdate;
		if (this->_frameIndex < this->_animations[this->_currentAnimation].size() - 1) {
			this->_frameIndex++;
		}
		else {
			if (this->_currentAnimationOnce == true) {
				this->setVisible(false);
			}
			this->_frameIndex = 0;
			this->animationDone(this->_currentAnimation);
		}
	}
}

void animatedSprite::draw(graphics & graphics, int x, int y)
{
	if (this->_visible) {
		SDL_Rect destinationRectangle;
		destinationRectangle.x = x + this->_offsets[this->_currentAnimation].x;
		destinationRectangle.y = y + this->_offsets[this->_currentAnimation].y;
		destinationRectangle.w = this->_sourceRect.w * globals::SPRITE_SCALE;
		destinationRectangle.h = this->_sourceRect.h * globals::SPRITE_SCALE;

		SDL_Rect sourceRect = this->_animations[this->_currentAnimation][this->_frameIndex];
		graphics.blitSurface(this->_spriteSheet, &sourceRect, &destinationRectangle);
	}
}

void animatedSprite::setupAnimation()
{
	this->addAnimation(3, 0, 0, "RunLeft", 16, 16, Vector2(0, 0));
	this->addAnimation(3, 0, 16,"RunRight",16,16,Vector2(0,0));
}

void animatedSprite::addAnimation(int frames, int x, int y, string name, int width, int height, Vector2 offset)
{
	vector<SDL_Rect> rectangles;
	for (int i = 0; i < frames; i++) {
		SDL_Rect newRect = { (i + x) * width, y, width, height };
		rectangles.push_back(newRect);
	}
	this->_animations.insert(pair<string, vector<SDL_Rect>>(name, rectangles));
	this-> _offsets.insert(pair<string, Vector2>(name, offset));
}

void animatedSprite::resetAnimation()
{
	this->_animations.clear();
	this->_offsets.clear();
}

void animatedSprite::stopAnimation()
{
	this->_frameIndex = 0;
	this->animationDone(this->_currentAnimation);
}

void animatedSprite::setVisible(bool visible)
{
	this->_visible = visible;
}

void animatedSprite::animationDone(string currentAnimation)
{
}



