/*
	EntityGameEngine - a super simple game engine to learn C++
	
	sampyxis 2014

*/
#include "PlayerObject.h"
#include <iostream>

// Constructor
PlayerObject::PlayerObject(void)
{
}

//PlayerObject::PlayerObject(char* fileName, float x, float y) : DynamicObject(fileName, x, y){
PlayerObject::PlayerObject(char* fileName, float x, float y) {
	//GameObject(fileName, x, y);
	sprite = GameSprite(fileName);
	SetLocation(x, y);
}

// Set location
void PlayerObject::SetLocation(float x, float y) {
	myLocation.x = x;
	myLocation.y = y;
	// Set scRect in case
	sprite.rcSprite.x = x;
	sprite.rcSprite.y = y;
}

// Move Object - need the velocity sent in
void PlayerObject::moveObject(float velocX, float velocY) {
	// Check it's not out of bounds
	// Needs to be cleaned up and not hardcoded
	if ((sprite.rcSprite.x >= 960 - 32) || (sprite.rcSprite.x < 0)) {
		sprite.rcSprite.x -= 1;
	}
	else {
		sprite.rcSprite.x += velocX;
	}
	if ((sprite.rcSprite.y >= 640 - 32) || (sprite.rcSprite.y < 0)) {
		sprite.rcSprite.y -= 1;
	}
	else {
		sprite.rcSprite.y += velocY;
	}
	printf("x = %d \n", sprite.rcSprite.x);
	printf("y = %d \n", sprite.rcSprite.y);
}


PlayerObject::location PlayerObject::GetLocation() {
	return myLocation;
}

bool PlayerObject::loadObject(char* file, int width, int height, int maxFrames) {
	return true;
}

void PlayerObject::onLoop() {
}

void PlayerObject::onRender(SDL_Surface* surface) {
	SDL_BlitSurface(sprite.image, NULL, surface, &sprite.rcSprite);
}

bool PlayerObject::isVisible() {
	return visible;
}

void PlayerObject::setVisbible(bool vis) {
	visible = vis;
}

void PlayerObject::onCleanup() {
}

void PlayerObject::onStartup() {
}

void PlayerObject::onUpdate(float timeDelta) {
}

void PlayerObject::onShutdown() {
}


PlayerObject::~PlayerObject(void)
{
}
