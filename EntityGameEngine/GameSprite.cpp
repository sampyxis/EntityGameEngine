/*
	EntityGameEngine - a super simple game engine to learn C++
	
	sampyxis 2014
*/

#include "GameSprite.h"
#include <stdio.h>


GameSprite::GameSprite(){
}

GameSprite::GameSprite(char* fileName){
	loadImage(fileName);
}

void GameSprite::loadImage(char* fileName){
	image = IMG_Load(fileName);
	if( !image) {
		printf("%s failed to load.", fileName);
	}
	rcSprite.x = 0;
	rcSprite.y = 0;
}

void GameSprite::releaseImage(){
	SDL_FreeSurface(image);
}

float GameSprite::x(float x){
	rcSprite.x = x;
	return x;
}

float GameSprite::y(float y){
	rcSprite.y = y;
	return y;
}

float GameSprite::x(void){
	return rcSprite.x;
}

float GameSprite::y(void){
	return rcSprite.y;
}

// Destructor
GameSprite::~GameSprite(void)
{
}
