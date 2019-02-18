/*
	EntityGameEngine - a super simple game engine to learn C++
	
	sampyxis 2014

	This is the main engine
*/

#include "Engine.h"

	const int SCREEN_WIDTH = 960;
	const int SCREEN_HEIGHT = 640;
	const int SCREEN_BPP = 32;
	SDL_Surface* Engine::backdrop = NULL;
	SDL_Surface* Engine::screen = NULL;
	SDL_Surface* Engine::temp = NULL;
	PlayerObject Engine::player;
	//The window we'll be rendering to
	static SDL_Window* gWindow = NULL;
	std::list<GameObject*> Engine::gameObjectList;

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
//	SDL_Surface* Engine::backdrop = NULL;
	//screen = NULL;	 
	//temp = NULL;
	//SDL_Rect rcSprite;
	//SDL_Event event;
	//SDL_Rect source;

	// Setup the screen now
	SDL_Init( SDL_INIT_EVERYTHING );    
	//screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE | SDL_DOUBLEBUF  );
	//Create window
	gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	SDL_SetWindowTitle(gWindow, "Title - temp" );
	//Get window surface
	screen = SDL_GetWindowSurface(gWindow);
	//SDL_WM_SetCaption( windowTitle, 0 );

}

void Engine::InitGame(void) {
	gameRunning = 1;
	velocY = 0.f;
	velocX = 0.f;
}

void Engine::RenderScreen(void){
	SDL_BlitSurface( Engine::backdrop, NULL, Engine::screen, NULL );
	//SDL_BlitSurface(sprite.image, NULL, screen, &sprite.rcSprite);
	// Here will be the loop where we render all entities - or - call each entity and have them render themselves
	player.onRender(screen);
	//Render all the objects
	Engine::UpdateObjects();
	//
	//Update the surface
	SDL_UpdateWindowSurface(gWindow);
	//SDL_Flip( screen );
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
	// problem is we don't know which gameObjectList to use - when I get here the system tries to recreate one.
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
