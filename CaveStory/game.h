#pragma once
#include "player.h"
#include "level.h"

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

	player _player;

	level _level;

};

