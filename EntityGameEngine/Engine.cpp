/*
	EntityGameEngine - a super simple game engine to learn C++
	
	sampyxis 2014

	This is the main engine
*/

#include "Engine.h"

	const int SCREEN_WIDTH = 960;
	const int SCREEN_HEIGHT = 640;
	const int SCREEN_BPP = 32;

// Contructor
Engine::Engine(void){
	windowTitle = "Game";
}

Engine::Engine(int width, int height, char* title) {
	const int SCREEN_WIDTH = width;
	const int SCREEN_HEIGHT = height;
	const int SCREEN_BPP = 32;
	windowTitle = title;

}

void Engine::InitSDL(void) {
	SDL_Surface* backdrop = NULL;
	SDL_Surface* screen = NULL;	 
	SDL_Surface* temp = NULL;
	SDL_Rect rcSprite;
	SDL_Event event;
	SDL_Rect source;

	// Setup the screen now
	SDL_Init( SDL_INIT_EVERYTHING );    
	screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE | SDL_DOUBLEBUF  );
	SDL_WM_SetCaption( "Title - temp", 0 );
	//SDL_WM_SetCaption( windowTitle, 0 );

}

void Engine::InitGame(void) {
	gameRunning = 1;
	velocY = 0.f;
	velocX = 0.f;
}

void Engine::RenderScreen(void){
	SDL_BlitSurface( backdrop, NULL, screen, NULL );
	//SDL_BlitSurface(sprite.image, NULL, screen, &sprite.rcSprite);
	// Here will be the loop where we render all entities - or - call each entity and have them render themselves
	player.onRender(screen);
	SDL_Flip( screen );
}

// Add a game object to the list
void Engine::AddGameObject(GameObject *gameObject){
	static int id = 0;
	gameObject->setID(id);
	gameObjectList.push_back(gameObject);
	id++;
};

// Update all objects
void Engine::UpdateObjects(void){
	std::list<GameObject*>::iterator iter;
	GameObject *gameObject;

	iter = gameObjectList.begin();
	while(iter != gameObjectList.end())
	{
		// Get an object
		gameObject = *iter;
		// Is it alive
		if(gameObject->getIsAlive()) {
			//gameObject.onUpdate();
			gameObject->onLoop();
		}
		if(gameObject->isVisible()){
			gameObject->onRender(screen);
		}
		iter++;
	}
}

// Destructor
Engine::~Engine(void) {

}
