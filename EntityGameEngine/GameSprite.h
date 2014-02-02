#pragma once
#include <SDL.h>
#include <SDL_image.h>

class GameSprite
{
public:
	SDL_Surface* image;
	SDL_Rect rcSprite;
	int sizeX;
	int sizeY;
	float myX;
	float myY;

	// Default constructor
	GameSprite();

	GameSprite(char* fileName);

	void loadImage(char* fileName);

	void releaseImage();

	float x(float x);
	float y(float y);

	float x(void);
	float y(void);

	virtual ~GameSprite(void);
};

