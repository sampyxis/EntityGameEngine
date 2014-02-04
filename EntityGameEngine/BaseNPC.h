/*
	EntityGameEngine - a super simple game engine to learn C++
	
	sampyxis 2014
*/

#pragma once
#include "dynamicobject.h"
class BaseNPC :	public DynamicObject
{
public:
	BaseNPC(void);
	BaseNPC(float x, float y);
	virtual ~BaseNPC(void);
};

