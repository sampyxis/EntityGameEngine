/*
	EntityGameEngine - a super simple game engine to learn C++
	
	sampyxis 2014
*/

#include "GameObject.h"

// Default constructor
GameObject::GameObject(void) {
}

GameObject::GameObject(float x, float y)
{
	// set the location to the x,y
	SetLocation(x, y);	
}

// Constructor with image
GameObject::GameObject(char* fileName, float x, float y){
	sprite = GameSprite(fileName);
	SetLocation(x, y);
}

// Construct with image and set visible 
GameObject::GameObject(char* fileName, float x, float y, bool visible){
	sprite = GameSprite(fileName);
	SetLocation(x, y);
	visible= true;
}


// Set location
void GameObject::SetLocation(float x, float y) {
	myLocation.x  = x;
	myLocation.y = y;
	// Set scRect in case
	sprite.rcSprite.x = x;
	sprite.rcSprite.y = y;
}

// Move Object - need the velocity sent in
void GameObject::moveObject(float velocX, float velocY){
	// Check it's not out of bounds
	// Needs to be cleaned up and not hardcoded
	if( (sprite.rcSprite.x >= 960 - 32)  || (sprite.rcSprite.x < 0)) {
		sprite.rcSprite.x -= 1;
	} else {
		sprite.rcSprite.x += velocX;
	}
	if(( sprite.rcSprite.y >= 640 - 32) || ( sprite.rcSprite.y < 0)) {
		sprite.rcSprite.y -= 1;
	} else {
		sprite.rcSprite.y += velocY;
	}
	printf("x = %d \n", sprite.rcSprite.x);
	printf("y = %d \n", sprite.rcSprite.y);
}


GameObject::location GameObject::GetLocation() {
	return myLocation;
}

bool GameObject::loadObject(char* file, int width, int height, int maxFrames){
	return true;
}

void GameObject::onLoop() {
} 

void GameObject::onRender(SDL_Surface* surface){
	SDL_BlitSurface(sprite.image, NULL, surface, &sprite.rcSprite);
}

bool GameObject::isVisible() {
	return visible;
}

void GameObject::setVisbible(bool vis) {
	visible = vis;
}

void GameObject::onCleanup() {
}

void GameObject::onStartup() {
}

void GameObject::onUpdate(float timeDelta) {
}

void GameObject::onShutdown() {
}

// Destructor
GameObject::~GameObject(void)
{
}

