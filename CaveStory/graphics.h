#pragma once
#include <SDL_image.h>
#include <string>
#include <map>


/*Graphics Class
*Holds all information dealing with graphics for the game
*/
struct SDL_Window;
struct SDL_Renderer;

using namespace std;

class graphics
{
public:
	static const int WIDTH;
	static const int HEIGHT;
	static const char* TITLE;
	graphics();
	~graphics();
	/*SDL_Surface* loadImage
	* Loads and image into the _spriteSheets map if doesn't already exist.
	* As a result, each image will only ever be loaded once.
	* Returns the image from the map regardless of whether or not it was just loaded.
	*/
	SDL_Surface* loadImage(const string &filePath);

	/*void blitSurface
	* Draws a texture to a certain part of the screen
	*/
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

	/*void flip
	* Renders everything to the screen
	*/
	void flip();

	/* void clear
	* Clears the screen
	*/
	void clear();

	/* SDL_Renderer* getRenderer
	* Returns the renderer
	*/
	SDL_Renderer* getRenderer() const;

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	map<string, SDL_Surface*> _spriteSheets;
};

