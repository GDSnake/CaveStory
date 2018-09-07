#include "player.h"
#include "graphics.h"


namespace player_constants {
	const float WALK_SPEED = 0.2f;
}

player::player()
{
}

player::player(graphics &graphics, float x, float y) :
	animatedSprite(graphics, "content/sprites/MyChar.png", 0, 0, 16, 16, x, y, 100) 
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
	// Move by dx
	this->_x += this->_dx * elapsedTime;

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



