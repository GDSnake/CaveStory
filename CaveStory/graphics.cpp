#include <SDL.h>
#include "graphics.h"
/*Graphics Class
*Holds all information dealing with graphics for the game
*/

const char* graphics::TITLE = "CaveStory by Goncalo Delgado.";
const int graphics::WIDTH = 1024;
const int graphics::HEIGHT = 900;


graphics::graphics()
{
	SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, TITLE);
}


graphics::~graphics()
{
	SDL_DestroyWindow(this->_window);
}
