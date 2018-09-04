#pragma once
#include "sprite.h"

class graphics;

class game
{
public:
	game();
	~game();
private:
	void gameLoop();
	void draw(graphics &graphics);
	void update(float elapsedTime);

	sprite _player;

};

