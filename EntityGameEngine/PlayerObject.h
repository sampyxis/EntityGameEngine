/*
	EntityGameEngine - a super simple game engine to learn C++
	
	Samuel Harper 2014
*/

#pragma once
#include "dynamicobject.h"
class PlayerObject : public DynamicObject
{
public:
	PlayerObject(void);
	PlayerObject(float x, float y);
	PlayerObject(char* fileName, float x, float y);
	virtual ~PlayerObject(void);
};

