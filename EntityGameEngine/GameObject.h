/*
	EntityGameEngine - a super simple game engine to learn C++
	
	sampyxis 2014
*/
/* 
	GameObject - 
		Base Object for every object in the game
		Need x,y, rot, width, height

		Adding an update here - that way all children will run the update for every tick in the game
		Adding a startup and shutdown function as well

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
	GameObject(char* fileName, float x, float y, bool visible);
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
	bool visible;
	bool isAlive;

	int id;

	// Functions
	void SetLocation(float x, float y);
	void moveObject(float velocX, float velocY);
	location GetLocation();
	virtual bool loadObject(char* file, int width, int height, int maxFrames); // Virtual since we may be redfining these later
	virtual void onLoop();
	virtual void onRender(SDL_Surface* surface);
	virtual bool isVisible();
	virtual void setVisbible(bool vis);
	virtual void onCleanup();
	virtual void onStartup();
	virtual void onUpdate(float timeDelta);
	virtual void onShutdown();
	void setID(int value) { id = value; }
	int getID() { return id; }
};

