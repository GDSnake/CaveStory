#include <SDL.h>
#include <SDL_image.h>

#include "graphics.h"
#include "globals.h"
/*Graphics Class
*Holds all information dealing with graphics for the game
*/

const char* graphics::TITLE = "CaveStory by Goncalo Delgado.";



graphics::graphics()
{
	SDL_CreateWindowAndRenderer(gloabals::SCREEN_WIDTH, gloabals::SCREEN_HEIGHT, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, TITLE);
}


graphics::~graphics()
{
	SDL_DestroyWindow(this->_window);
}

SDL_Surface * graphics::loadImage(const string &filePath)
{
	if (this->_spriteSheets.count(filePath) == 0) {
		this-> _spriteSheets[filePath] = IMG_Load(filePath.c_str());
	}
	return this->_spriteSheets[filePath];
}

void graphics::blitSurface(SDL_Texture * texture, SDL_Rect * sourceRectangle, SDL_Rect * destinationRectangle)
{
	SDL_RenderCopy(this->_renderer, texture, sourceRectangle, destinationRectangle);
}

void graphics::flip()
{
	SDL_RenderPresent(this->_renderer);
}

void graphics::clear()
{
	SDL_RenderClear(this->_renderer);
}

SDL_Renderer * graphics::getRenderer() const
{
	return this->_renderer;
}
