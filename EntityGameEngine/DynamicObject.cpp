#include "DynamicObject.h"


DynamicObject::DynamicObject(void) {
}

DynamicObject::DynamicObject(float x, float y)
{
}

DynamicObject::DynamicObject(char* fileName, float x, float y) : GameObject(fileName, x, y){
}

void DynamicObject::onAnimate(){
}

void DynamicObject::onCollision(GameObject* ent){
}

void DynamicObject::onMove(float movX, float movY){
}

void DynamicObject::stopMove(){
}

bool DynamicObject::jump(){
	return true;
}


bool DynamicObject::collides(int oX, int oY, int oW, int oH){
	return true;
}

bool DynamicObject::posValid(float newX, float newY){
	return true;
}
	//bool posValidTile(EntityTile* tile);
bool DynamicObject::posValidEnt(GameObject* ent, float newX, float newY){
	return true;
}


// Destructor
DynamicObject::~DynamicObject(void)
{
}

