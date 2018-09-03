#pragma once

struct SDL_Window;
struct SDL_Renderer;

class graphics
{
public:
	static const int WIDTH;
	static const int HEIGHT;
	static const char* TITLE;
	graphics();
	~graphics();
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
};

