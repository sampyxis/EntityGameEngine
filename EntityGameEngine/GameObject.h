/* 
	GameObject - 
		Base Object for every object in the game
		Need x,y, rot, width, height

		Adding an update here - that way all children will run the update for every tick in the game

*/

#pragma once
#include "DrawMacros.h"
#include "GameSprite.h"

class GameObject
{
public:
	GameObject(void);
	GameObject(float x, float y); // Constructor
	GameObject(char* fileName, float x, float y);
	virtual ~GameObject(void); // Destructor

	// Properties
	struct location {
		float x;
		float y;
		float angle;
	} myLocation;

	GameSprite sprite;

	float rotation;
	int width;
	int height;

	bool allowOutOfBounds;

	// Functions
	void SetLocation(float x, float y);
	void moveObject(float velocX, float velocY);
	location GetLocation();
	virtual bool loadObject(char* file, int width, int height, int maxFrames); // Virtual since we may be redfining these later
	virtual void onLoop();
	virtual void onRender(SDL_Surface* surface);
	virtual void onCleanup();
	virtual void update(float timeDelta);

};

