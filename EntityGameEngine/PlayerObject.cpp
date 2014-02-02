#include "PlayerObject.h"


// Constructor
PlayerObject::PlayerObject(void)
{
}

PlayerObject::PlayerObject(char* fileName, float x, float y) : DynamicObject(fileName, x, y){
	//GameObject(fileName, x, y);
}


PlayerObject::~PlayerObject(void)
{
}
