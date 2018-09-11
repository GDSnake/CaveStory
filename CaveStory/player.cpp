#include "player.h"
#include "graphics.h"


namespace player_constants {
	const float WALK_SPEED = 0.2f;

	const float GRAVITY = 0.002f;
	const float GRAVITY_CAP = 0.8f;
}

player::player()
{
}

player::player(graphics &graphics, Vector2 spawnPoint) :
	animatedSprite(graphics, "content/sprites/MyChar.png", 0, 0, 16, 16, spawnPoint.x, spawnPoint.y, 100),
	_dx(0),
	_dy(0),
	_facing(RIGHT),
	_grounded(false)
{
	graphics.loadImage("content/sprites/MyChar.png");
	this->_facing = RIGHT;
	this->setupAnimations();
	this->playAnimation("RunRight");

}

void player::draw(graphics & graphics)
{
	animatedSprite::draw(graphics, this->_x, this->_y);
}

void player::update(float elapsedTime)
{
	//Apply gravity
	if (this->_dy <= player_constants::GRAVITY_CAP) {
		this->_dy += player_constants::GRAVITY * elapsedTime;
	}

	// Move by dx
	this->_x += this->_dx * elapsedTime;

	//Move by dy
	this->_y += _dy*elapsedTime;
	animatedSprite::update(elapsedTime);
}

void player::moveLeft()
{
	this->_dx = -player_constants::WALK_SPEED;
	this->playAnimation("RunLeft");
	this->_facing = LEFT;
}

void player::moveRight()
{
	this->_dx = player_constants::WALK_SPEED;
	this->playAnimation("RunRight");
	this->_facing = RIGHT;
}

void player::stopMoving()
{
	this->_dx = 0.0f;
	this->playAnimation(this->_facing == RIGHT ? "IdleRight" : "IdleLeft");

	
}

void player::animationDone(string currentAnimation)
{

}

void player::setupAnimations()
{
	this->addAnimation(1, 0, 0, "IdleLeft", 16, 16, Vector2(0, 0));
	this->addAnimation(1, 0, 16, "IdleRight", 16, 16, Vector2(0, 0));
	this->addAnimation(3, 0, 0, "RunLeft", 16, 16, Vector2(0, 0));
	this->addAnimation(3, 0, 16, "RunRight", 16, 16, Vector2(0, 0));
}

/*void handleTileCollisions
Handles collisions with ALL tiles the player is colliding with
*/
void player::handeTileCollisions(vector<rectangle> &others) {
	//Figure out what side the collision happend on and move the player accordingly
	for (int i = 0; i < others.size(); i++) {
		sides::Side collisionSide = sprite::getCollisionSide(others.at(i));
		if (collisionSide != sides::NONE) {
			switch (collisionSide)
			{
			case sides::TOP:
				this->_y = others.at(i).getBottom() + 1;
				this->_dy = 0;
				break;
			case sides::BOTTOM:
				this->_y = others.at(i).getTop() - this->_boundingBox.getHeight() - 1;
				this->_dy = 0;
				this->_grounded = true;
				break;
			case sides::LEFT:
				this->_y = others.at(i).getRight() + 1;
				break;
			case sides::RIGHT:
				this->_y = others.at(i).getLeft() - this->_boundingBox.getWidth() -1;
				break;
			case sides::NONE:
				break;
			default:
				break;
			}
		}
	}
}

const float player::getX() const
{
	return this->_x;
}

const float player::getY() const
{
	return this->_y;
}



