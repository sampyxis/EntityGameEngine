/*
	EntityGameEngine - a super simple game engine to learn C++
	
	sampyxis 2014
*/ 

/*
	This is the game file that runs - will soon change to a game object - then a seperate game files to actually run the game
*/

#include "SDL.h"   /* All SDL App's need this */
#include "SDL_image.h"
#include <stdio.h>
#include "GameSprite.h"
#include "PlayerObject.h"

	SDL_Surface* backdrop = NULL;
	SDL_Surface* screen = NULL;	 
	SDL_Surface* temp = NULL;
	SDL_Rect rcSprite;
	SDL_Event event;
	int gameRunning = 1;
	SDL_Rect source;
	Uint8 *keystate;
	float velocY = 0.f;
	float velocX = 0.f;
	const int SCREEN_WIDTH = 960;
	const int SCREEN_HEIGHT = 640;
	const int SCREEN_BPP = 32;

	GameSprite sprite;
	PlayerObject player;

void LoadImages() {    
	// Test sample.png to see if it is a PNG
	SDL_RWops *rwop1;
	rwop1=SDL_RWFromFile("bk_warhouse.png", "rb");
	if(IMG_isPNG(rwop1))
		printf("bk_warhouse.png is a PNG file.\n");
	else
		printf("sample.png is not a PNG file, or PNG support is not available.\n");

	SDL_RWops *rwop;
	rwop=SDL_RWFromFile("bk_warhouse.png", "rb");
	backdrop=IMG_LoadPNG_RW(rwop);

	printf("%s", IMG_GetError());

	backdrop = IMG_Load( "bk_warhouse.gif" );
	printf("%s", IMG_GetError());

	if (!backdrop)
		printf("Failed to load background");

	// Load sprite
	//sprite = GameSprite("spr_cop_0.gif");
	//sprite = IMG_Load("spr_cop_0.gif");
	//printf("sprite problem: %s", IMG_GetError());
//	sprite = SLD_DisplayFormat(temp);
//	SDL_FreeSurface(temp);
	//sprite.x(0.f);
	//sprite.y(0.f);

	player = PlayerObject("spr_cop_0.gif", 0.f, 0.f);
	//player.SetLocation(0.f, 0.f);
}

void InitGame() {
	SDL_Init( SDL_INIT_EVERYTHING );    
	screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE | SDL_DOUBLEBUF  );
	SDL_WM_SetCaption( "SDL Test", 0 );
	LoadImages();
}

void RenderScreen() {
	 SDL_BlitSurface( backdrop, NULL, screen, NULL );
	 //SDL_BlitSurface(sprite.image, NULL, screen, &sprite.rcSprite);
	 player.onRender(screen);
	 SDL_Flip( screen );
}

void FinishOff() {
	SDL_FreeSurface( backdrop );
	SDL_FreeSurface( screen );
	//SDL_FreeSurface( sprite.image );
	sprite.releaseImage();
	//Quit SDL
	SDL_Quit();
	exit(0);
}


int main_old(int argc, char* argv[])
{
	  InitGame();
	  RenderScreen();		  
	  //
	  while( gameRunning = 1){
		while( (SDL_PollEvent( &event ))    ){
				switch( event.type ){
					case SDL_QUIT:
						gameRunning = 0;
						printf("Quiting.../n");
						break;
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
						break;
			
					default:
						break;
				}
			}
		// Still running
		player.moveObject(velocX, velocY);
		player.onUpdate(0.0f);  // Needs to be delta - also needs to be an object that holds all entities that has update
		RenderScreen();
	  }
	FinishOff();
	return 0;
}