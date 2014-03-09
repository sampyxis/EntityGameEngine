/*
	EntityGameEngine - a super simple game engine to learn C++
	
	sampyxis 2014

	This is the main engine header
*/

// All the engine files
#pragma once
#include <iostream>
#include <list>
#include <vector>

#include "SDL.h"   /* All SDL App's need this */
#include "SDL_image.h"
#include <stdio.h>
#include "GameObject.h"
#include "GameSprite.h"
#include "PlayerObject.h" // Should be in engine or game???

static class Engine
{
public:
	Engine(void); // Constructor
	Engine(int width, int height, char* title);
	virtual ~Engine(void); // Destructor

	static void InitSDL(void);
	void InitGame(void);
	static void RenderScreen(void);
	void UpdateObjects(void);
	void AddGameObject(GameObject *gameObject);


	// GameObjects
	std::list<GameObject*> gameObjectList;

	// Screen
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

	char* windowTitle;
	
	// Player object to be assigned in the game
	PlayerObject player;
};

