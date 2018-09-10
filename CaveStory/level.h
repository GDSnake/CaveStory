#pragma once
#include <string>
#include <vector>

#include "globals.h"
#include"tile.h"


class graphics; 
struct SDL_Texture;
struct SDL_Rect;
struct Tileset;

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
	Vector2 _tileSize;

	SDL_Texture* _backgroundTexture;

	vector<tile> _tileList;
	vector<Tileset> _tilesets;


	/* void loadMap
	 Loads a map
	*/
	void loadMap(string mapName, graphics &graphics);
};

//Tileset structure

struct Tileset {
	SDL_Texture* Texture;
	int FirstGid;

	Tileset() {
		this->FirstGid = -1;
	}
	Tileset(SDL_Texture* texture, int firstGid) {
		this->Texture = texture;
		this->FirstGid = firstGid;
	}
};

