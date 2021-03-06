#include "game.h"
#include "graphics.h"
#include "input.h"
#include <SDL.h>
#include <algorithm>


/*Game Class
* This class holds all information for our main game loop
*/

namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME =  1000 / FPS;

}

game::game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}


game::~game()
{
}

void game::gameLoop()
{
	graphics graphics;
	input input;
	SDL_Event event;
	
	
	this->_level = level("map 1TEMP", Vector2(100, 100), graphics);
	this->_player = player(graphics, this->_level.getPlayerSpawnPoint());

	int LAST_UPDATE_TIME = SDL_GetTicks();

	while (true) {
		input.beginNewFrame();
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				if (event.key.repeat == 0) {
					input.keyDownEvent(event);
				}
			}
			else if (event.type == SDL_KEYUP) {
				input.keyUpEvent(event);
			}
			else if (event.type == SDL_QUIT) {
				return;
			}
		}
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
			return;
		}
		else if (input.isKeyHeld(SDL_SCANCODE_LEFT) == true) {
			this->_player.moveLeft();
		}
		else if (input.isKeyHeld(SDL_SCANCODE_RIGHT) == true) {
			this->_player.moveRight();
		}

		if (!input.isKeyHeld(SDL_SCANCODE_LEFT) && !input.isKeyHeld(SDL_SCANCODE_RIGHT)) {
			this->_player.stopMoving();
		}

		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		this->update(min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;

		this->draw(graphics);
	}
}

void game::draw(graphics &graphics)
{
	graphics.clear();
	this->_level.draw(graphics);
	this->_player.draw(graphics);

	graphics.flip();
}

void game::update(float elapsedTime)
{
	this->_player.update(elapsedTime);
	this->_level.update(elapsedTime);

	//Check collisions

	vector<rectangle> others;
	if ((others = this->_level.checkTileCollision(this->_player.getBoundingBox())).size() > 0) {
		//Player collided with at least one tile. Handle it
		this->_player.handeTileCollisions(others);
	}
}
