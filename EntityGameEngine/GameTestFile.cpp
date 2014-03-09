/*
	EntityGameEngine - a super simple game engine to learn C++
	
	sampyxis 2014

	File to test the game engine
*/

// Intitate the game engine

#include "Engine.h" 
//Background
// really should be referencing this in the engine
// Engine::backgrop = NULL;
SDL_Surface* localBackdrop = NULL;

// Game specific variables
bool gameRunning = true;
bool gamePaused = false;

// Load Background
void loadBackground(){
	localBackdrop = IMG_Load( "bk_warhouse.gif" );
	printf("%s", IMG_GetError());

	if (!localBackdrop)
		printf("Failed to load background");
}


// Game entry
int main(int argc, char* argv[]){

// Init the Engine
	//Engine myEngine = new Engine();
	Engine::InitSDL();
	loadBackground();
	// Loop while running
	while(gameRunning) {
		Engine::RenderScreen();
	}

	return 0;
}



// Set up the player
PlayerObject myPlayer;


