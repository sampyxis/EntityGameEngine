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
SDL_Event event;

Engine thisEngine;// = Engine();


// Game specific variables
bool gameRunning = true;
bool gamePaused = false;

float velocY = 0.f;
float velocX = 0.f;

PlayerObject myPlayer;
//GameObject& mBarrel = NULL;


// Load Background
void loadBackground(){
	localBackdrop = IMG_Load( "bk_warhouse.gif" );
	printf("%s", IMG_GetError());

	if (!localBackdrop)
		printf("Failed to load background");
	else
		thisEngine.backdrop = localBackdrop;
}

// Setup level objects
// Move this to a level manager later
void setUpLevel() {
	GameObject& mBarrel = GameObject("spr_cop_0.gif", 10.f, 10.f, true);
	mBarrel.title = "Barrel 1";
	thisEngine.AddGameObject(&mBarrel);
	
	GameObject& mBarrel1 = GameObject("spr_cop_0.gif", 20.f, 20.f, true);
	mBarrel1.title = "Barrel 2";
	thisEngine.AddGameObject(&mBarrel1);
	// Below for testing
	thisEngine.UpdateObjects();
}

// Set up the player
void setUpPlayer(){
	int i;
	i = 1;
	myPlayer =  PlayerObject("spr_cop_0.gif", 0.f, 0.f);
	thisEngine.player = PlayerObject("spr_cop_0.gif", 0.f, 0.f);
	//Engine::AddGameObject(myPlayer);
	thisEngine.UpdateObjects();
}

// Game entry
int main(int argc, char* argv[]){

// Init the Engine
	//Engine* myEngine = new Engine();
	thisEngine = Engine();
	thisEngine.InitSDL();
	loadBackground();
//	setUpLevel();
	GameObject& mBarrel = GameObject("spr_cop_0.gif", 10.f, 10.f, true);
	mBarrel.title = "Barrel 1";
	thisEngine.AddGameObject(&mBarrel);

	GameObject& mBarrel1 = GameObject("spr_cop_0.gif", 20.f, 20.f, true);
	mBarrel1.title = "Barrel 2";
	thisEngine.AddGameObject(&mBarrel1);
	// Below for testing
	thisEngine.UpdateObjects();
	setUpPlayer();


	// Loop while running
	while(gameRunning) {
		while( (SDL_PollEvent( &event ))    ){
				switch( event.type ){
					case SDL_QUIT:
						gameRunning = 0;
						printf("Quiting.../n");
						break;
//
					/* Look for a keypress */
					case SDL_KEYDOWN:
						/* Check the SDLKey values and move change the coords */
						switch( event.key.keysym.sym ){
							case SDLK_LEFT:
								velocX = -1;
								break;
							case SDLK_RIGHT:
								velocX =  1;
								break;
							case SDLK_UP:
								velocY = -1;
								break;
							case SDLK_DOWN:
								velocY =  1;
								break;
							default:
								break;
						}
						break;
					/* We must also use the SDL_KEYUP events to zero the x */
					/* and y velocity variables. But we must also be       */
					/* careful not to zero the velocities when we shouldn't*/
					case SDL_KEYUP:
						switch( event.key.keysym.sym ){
							case SDLK_LEFT:
								/* We check to make sure the alien is moving */
								/* to the left. If it is then we zero the    */
								/* velocity. If the alien is moving to the   */
								/* right then the right key is still press   */
								/* so we don't tocuh the velocity            */
								if( velocX < 0 )
									velocX = 0;
								break;
							case SDLK_RIGHT:
								if( velocX > 0 )
									velocX = 0;
								break;
							case SDLK_UP:
								if( velocY < 0 )
									velocY = 0;
								break;
							case SDLK_DOWN:
								if( velocY > 0 )
									velocY = 0;
								break;
							default:
								break;
						}

//
				}
		}
		thisEngine.player.moveObject(velocX, velocY);
		thisEngine.player.onUpdate(0.0f);  // Needs to be delta - also needs to be an object that holds all entities that has update
		thisEngine.UpdateObjects();
		thisEngine.RenderScreen();
	}

	return 0;
}









