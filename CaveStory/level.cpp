#include "level.h"
#include "graphics.h"

#include <SDL.h>

level::level()
{
}

level::level(string mapName, Vector2 spawnPoint, graphics & graphics) :
	_mapName(mapName),
	_spawnPoint(spawnPoint),
	_size(Vector2(0,0))
{
	this->loadMap(mapName, graphics);
}


level::~level()
{
}

void level::update(int elapsedTime)
{
}

void level::draw(graphics &graphics)
{
	//Draw the background
	SDL_Rect sourceRect = {0,0,64,64};
	SDL_Rect destRect;
	for (int x = 0; x < this->_size.x / 64; x++) {
		for (int y = 0; y < this->_size.y / 64; y++) {
			destRect.x = x * 64;
			destRect.y = y * 64;
			destRect.w = 64;
			destRect.h = 64;
			graphics.blitSurface(this->_backgroundTexture, &sourceRect, &destRect);
		}
	}
}

void level::loadMap(string mapName, graphics &graphics)
{
	//Temporary code to load the background
	this->_backgroundTexture = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage("content/backgrounds/bkBlue.png"));
	this->_size = Vector2(1280, 960);
}
