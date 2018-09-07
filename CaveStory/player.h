#pragma once
#include "animatedSprite.h"

class graphics;

using namespace std;

class player : public animatedSprite
{
public:
	player();
	player(graphics &graphics, float x, float y);
	void draw(graphics &graphics);
	void update(float elapsedTime);

	/*void moveLeft
	Moves the player left by -dx
	*/
	void moveLeft();

	/*void moveRight
	Moves the player right by dx
	*/
	void moveRight();

	/*void stopMoving
	Stops moving the player
	*/
	void stopMoving();

	virtual void animationDone(string currentAnimation);
	virtual void setupAnimations();

private:
	float _dx, _dy;

	Direction _facing;
};

