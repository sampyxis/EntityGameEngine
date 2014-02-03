/*
	EntityGameEngine - a super simple game engine to learn C++
	
	Samuel Harper 2014
*/

#pragma once
#include "gameobject.h"
#include <vector>

class DynamicObject : public GameObject
{
public:
	DynamicObject(void);
	DynamicObject(float x, float y);
	DynamicObject(char* fileName, float x, float y);
	virtual ~DynamicObject(void);

	// properties
	bool moveLeft;
	bool moveRight;
	bool dead;
	float maxVelX;
	float maxVelY;

protected:
	int currFameCol;
	int currFrameRow;
	float velX;
	float velY;
	bool canJump;
	float accelX;
	float accelY;
	int colX;
	int colY;
	int colWide;
	int colTall;

	// Functions
public:
	virtual void onAnimate();
	virtual void onCollision(GameObject* ent);
	void onMove(float movX, float moveY);
	void stopMove();
	bool jump();

	bool collides(int oX, int oY, int oW, int oH);

private:
	bool posValid(float newX, float newY);
	//bool posValidTile(EntityTile* tile);
	bool posValidEnt(GameObject* ent, float newX, float newY);

};

class entityCol{
public:
	static std::vector<entityCol> entColList;

public:
	GameObject* entA;
	GameObject* entB;

public:
	entityCol();
};