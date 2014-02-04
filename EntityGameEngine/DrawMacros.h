/*
	EntityGameEngine - a super simple game engine to learn C++
	
	sampyxis 2014
*/

#pragma once

#include <SDL.h>
#include <SDL_image.h>

class DrawMacros
{
public:
	DrawMacros(void);
	~DrawMacros(void);

public:
	static SDL_Surface* loadImage(char* file);
	static bool doDraw(SDL_Surface* sDest, SDL_Surface* sSrc, int x, int y);
	static bool doDraw(SDL_Surface* sDest, SDL_Surface* sSrc, int x, int y, int x2, int y2, int w, int h); // For multipart surface
	static bool transparent(SDL_Surface* sDest, int R, int G, int B);
};

