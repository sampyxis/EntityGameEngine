/*
	EntityGameEngine - a super simple game engine to learn C++
	
	sampyxis 2014

	This is the main engine header
*/

// All the engine files
#pragma once
#include "SDL.h"   /* All SDL App's need this */
#include "SDL_image.h"
#include <stdio.h>
#include "GameSprite.h"
#include "PlayerObject.h" // Should be in engine or game???

class Engine
{
public:
	Engine(void); // Constructor
	virtual ~Engine(void); // Destructor

	void InitGame(void);
	void RenderScreen(void);

	SDL_Surface* backdrop;
	SDL_Surface* screen;
	SDL_Surface* temp;
	SDL_Rect rcSprite;
	SDL_Event event;
	int gameRunning;
	SDL_Rect source;
	Uint8 *keystate;
	float velocY;
	float velocX;
	const int SCREEN_WIDTH;
	const int SCREEN_HEIGHT;
	const int SCREEN_BPP;
}


