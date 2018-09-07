#include "input.h"

/* Input class
* Keeps track of keyboard state
*/


//This fucntion gets called at the beginning of each new frame
// to reset the keys that are no longer relevant
void input::beginNewFrame()
{
	this->_pressedKeys.clear();
	this->_releasedKeys.clear();
}

// this gets called when a keys is released
void input::keyUpEvent(const SDL_Event& event)
{
	this->_releasedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = false;
}

// This gets called when as key has been pressed
void input::keyDownEvent(const SDL_Event& event)
{
	this->_pressedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = true;
}

// Checks if a certain key was pressed during current frame
bool input::wasKeyPressed(SDL_Scancode key)
{
	return this->_pressedKeys[key];
}

//Check if a certain key was released during current frame
bool input::wasKeyReleased(SDL_Scancode key)
{
	return this->_releasedKeys[key];
}

//Check if a certain key is currently being held
bool input::isKeyHeld(SDL_Scancode key)
{
	return this->_heldKeys[key];
}
