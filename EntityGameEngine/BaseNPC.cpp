/*
	EntityGameEngine - a super simple game engine to learn C++
	
	Samuel Harper 2014
*/

#include "BaseNPC.h"


BaseNPC::BaseNPC(void)
{
}

BaseNPC::BaseNPC(float x, float y){
	SetLocation(x, y);
}

// Destructor
BaseNPC::~BaseNPC(void)
{
}
