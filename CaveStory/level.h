#pragma once
#include <string>

#include "globals.h"

class graphics; 
struct SDL_Texture;

using namespace std;
class level
{
public:
	level();
	level(string mapName,Vector2 spawnPoint, graphics &graphics);
	~level();
	void update(int elapsedTime);
	void draw(graphics &graphics);
private:
	string _mapName;
	Vector2 _spawnPoint;

	Vector2 _size;

	SDL_Texture* _backgroundTexture;

	/* void loadMap
	 Loads a map
	*/
	void loadMap(string mapName, graphics &graphics);
};

