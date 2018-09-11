#pragma once
#include <SDL.h>
#include <string>

#include "graphics.h"
#include "rectangle.h"
#include "globals.h"
using namespace std;



/* sprite class
* Holds all information for individual sprites
*/
class sprite
{
public:
	sprite();
	sprite(graphics &graphics, const string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);
	virtual ~sprite();
	virtual void update();
	void draw(graphics &graphics, int x, int y);

	const rectangle getBoundingBox() const;
	const sides::Side getCollisionSide(rectangle &other) const;

protected:
	SDL_Rect _sourceRect;
	SDL_Texture* _spriteSheet;

	rectangle _boundingBox;

	float _x, _y;

private:
	
};

