/*
	EntityGameEngine - a super simple game engine to learn C++
	
	Samuel Harper 2014
*/

#pragma once
#include "gameobject.h"
class StaticObject : public GameObject
{
public:
	StaticObject(void);
	StaticObject(float x, float y);
	virtual ~StaticObject(void);
};

