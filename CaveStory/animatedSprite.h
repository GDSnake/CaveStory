#pragma once

#include <string>
#include <map>
#include <vector>

#include "sprite.h"
#include "globals.h"

using namespace std;

class graphics;

/*animatedSprite class
* Holds logic for animating sprites
*/
class animatedSprite : public sprite
{
public:
	animatedSprite();
	animatedSprite(graphics &graphics, const string &filePath, int sourceX,int sourceY, int width, int height, 
		float posX, float posY, float timeToUpdate);
	
	/*void playAnimation
	* Plays the animation provided if it' not already playing
	*/
	void playAnimation(string animation, bool once = false);

	/*void update
	* Updates the animated sprite (timer)
	*/
	void update(int elapsedTime);

	/*void draw
	* Draws the sprite to the screen
	*/
	void draw(graphics &graphics, int x, int y);

	

protected:
	double _timeToUpdate;
	bool _currentAnimationOnce;
	string _currentAnimation;

	/*void addAnimation
	*Adds an animation to the map of animations for the sprite
	*/
	void addAnimation(int frames, int x, int y, string name, int width, int height, Vector2 offset);

	/*void resetAnimation
	* Resets all animations associated with this sprite
	*/
	void resetAnimation();

	/*void stopAnimation
	* Stops the current animation
	*/
	void stopAnimation();

	/*void setVisible
	* Changes the visibility of the animated sprite
	*/
	void setVisible(bool visible);

	/*void animationDone
	* Logic that happens when animation ends
	*/
	virtual void animationDone(string currentAnimation) = 0;

	/*void setupAnimations
	* A required function the sets up all animations for a sprite
	*/
	virtual void setupAnimations() = 0;

private:
	map<string, vector<SDL_Rect>> _animations;
	map<string, Vector2> _offsets;

	int _frameIndex;
	double _timeElapsed;
	bool _visible;



};

