/*
	EntityGameEngine - a super simple game engine to learn C++
	
	sampyxis 2014
*/

#include "StaticObject.h"


StaticObject::StaticObject(void){
}

StaticObject::StaticObject(float x, float y)
{
	SetLocation(x,y);
}


StaticObject::~StaticObject(void)
{
}
