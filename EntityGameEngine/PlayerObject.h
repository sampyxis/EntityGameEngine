/*
	EntityGameEngine - a super simple game engine to learn C++
	
	sampyxis 2014
*/

#pragma once
#include "DrawMacros.h"
#include "GameSprite.h"
//#include "dynamicobject.h"

//class PlayerObject : public DynamicObject
class PlayerObject
{
public:
	PlayerObject(void);
	PlayerObject(float x, float y);
	PlayerObject(char* fileName, float x, float y);
	virtual ~PlayerObject(void);

	// Properties
	struct location {
		float x;
		float y;
		float angle;
	} myLocation;

	GameSprite sprite;

	char* title;

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
	void setIsAlive(bool value) { isAlive = value; }
	bool getIsAlive() { return isAlive; }


};

