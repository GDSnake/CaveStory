#pragma once

#include"globals.h";
struct SDL_Texture;

class graphics;

class tile
{
public:
	tile();
	tile(SDL_Texture* tileset, Vector2 size, Vector2 tilesetPosition, Vector2 position);
	void update(int elapsedTime);
	void draw(graphics &graphics);
private:
	SDL_Texture * _tileset;
	Vector2 _size;
	Vector2 _tilesetPosition;
	Vector2 _position;
};

