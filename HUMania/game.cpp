#include "game.hpp"
#include "ShapeShowdown.hpp"
#include "DrawObjects.hpp"
#include <iostream>
#include <SDL_mixer.h>

using namespace std;
SDL_Renderer* Drawing::gRenderer = NULL;
SDL_Texture* Drawing::assets = NULL;
SDL_Texture* Drawing::asset_bullet= NULL;
SDL_Texture* Drawing::asset_explosion = NULL;
bool Game::init()
{
	//Initialization flag
	bool success = true;


	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "Shape Showdown", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
			{
				printf( "Warning: Linear texture filtering not enabled!" );
			}

			if( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0 )
			{
				printf( "Unable to open audio: %s\n", Mix_GetError());
				success=false;
			}

			//Create renderer for window
			Drawing::gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( Drawing::gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( Drawing::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;
	music=Mix_LoadMUS("gamemain.mp3");
	Drawing::assets = loadTexture("assets.png");
	Drawing::asset_bullet = loadTexture("bullet.png");
	Drawing::asset_explosion = loadTexture("explosion.png");

    gTexture = loadTexture("GameMain.png");

	if(Drawing::assets==NULL || gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success = false;
    }
	return success;
	if( music == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
}

void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(Drawing::assets);
	Drawing::assets=NULL;
	SDL_DestroyTexture(gTexture);
	Mix_FreeMusic(music);
    music = NULL;
	//Destroy window
	SDL_DestroyRenderer( Drawing::gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	Drawing::gRenderer = NULL;
	
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( Drawing::gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}
void Game::run( )
{
	//Main object created
	ShapesShowdown ss;
	bool quit = false;
	SDL_Event e;


	while( !quit )
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
			if(e.type == SDL_MOUSEBUTTONDOWN)
			{
				
				cout << "inhere";
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);
				//when player clicks on play game
				if (xMouse>168 && yMouse>343 && xMouse<802  && yMouse<460 && state == 0)
				{
					music=Mix_LoadMUS("click.wav"); //click sound plays
					Mix_PlayMusic(music,0);
					gTexture = loadTexture("GameBackground.jpeg"); 
					state = 2;
					if (play_again == true){  
						ss.createObject(); 
						ss.play_again();
						play_again = false;
					}
				}

				//If instructions button is pressed
				else if (xMouse>168 && yMouse>480 && xMouse<804 && yMouse < 600 && state == 0)
				{
					music=Mix_LoadMUS("click.wav"); //click sound plays
					Mix_PlayMusic(music,0);
					gTexture = loadTexture("instructions.png");	
					state=1; //each time a button is pressed and screen changes, state is changed
					
				}

				//If the back button on the instruction screen is pressed
				else if (xMouse>43 && yMouse>38 && xMouse<177 && yMouse<176 && state==1)
				{
					music=Mix_LoadMUS("click.wav"); //click sound plays
					Mix_PlayMusic(music,0);
					gTexture = loadTexture("GameMain.png");					
					state=0; //state is set back to the main screen
					
				}

				//If the quit botton on the paused screen is pressed
				else if (xMouse>170 && yMouse>370 && xMouse<788 && yMouse<559 && state==3)
				{
					music=Mix_LoadMUS("click.wav"); //click sound plays
					Mix_PlayMusic(music,0);
					gTexture = loadTexture("GameMain.png");
					ss.deleteObject();
					play_again = true;
					state=0;  //state is set back to the main screen
				}	

				//when game over screen and player presses play again
				else if (xMouse>214 && yMouse>239 && xMouse<769 && yMouse<403  && state==4)
				{
					music=Mix_LoadMUS("click.wav"); //click sound plays
					Mix_PlayMusic(music,0);
					gTexture = loadTexture("GameMain.png");
					ss.deleteObject();
					play_again = true;
					state=0;  //state is set back to the main screen
				}
			}
			
			//shooter movement when the right, left keys are pressed
			else if(e.type == SDL_KEYDOWN && state == 2)
			{	
				if (e.key.keysym.sym == SDLK_LEFT)
				{
					shooter_obj_moving = 1;
					ss.sh->movement(shooter_obj_moving); //movement is stored and passed to the shooter function
				}
				if 	(e.key.keysym.sym == SDLK_RIGHT)
				{	
					shooter_obj_moving=2;
					ss.sh->movement(shooter_obj_moving);
				}
			}

			//Shoot function called when space bar is pressed
			else if (e.key.keysym.sym == SDLK_SPACE) {
				if(e.type == SDL_KEYUP)
				{
					ss.shoot();
				}
			}

			//when Esc key is pressed game is paused, and resumed when it is pressed again
			if	(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE && pause== false){
				gTexture = loadTexture("Pause.png");
				state = 3;
				pause = true;
			}
			else if	(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE && pause==true)
			{
				gTexture = loadTexture("GameBackground.jpeg");
				state = 2;
				pause = false;
			}
		}
		SDL_RenderClear(Drawing::gRenderer); //removes everything from renderer
		SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL);

		//states are handled here

		//2: Playing mode
		if (state == 2 && restart == false) {
			counter = rand()%100;
			ss.drawObjects();
			if (counter>95)
			{
			 	ss.createObject();
			}
		}

		//1: Instruction screen, 0: Home Screen
		if(state == 0 ||  state == 1 ){
			if (Mix_PlayingMusic()==0)
			{
				music=Mix_LoadMUS("main.mp3");
				Mix_PlayMusic(music,0);
			}
		}
		
		//2: Playing Mode, with the game restarted, 
		//so the previous tate is destroyed, and new objects are drawn, new life and score is set
		if (state==2 && restart==true)
		{
			ss.deleteObject();
			ss.set_life();
			ss.set_score();
			
			counter = rand()%100;
			ss.drawObjects();
			if (counter>95)
			{
				ss.createObject();
			}
		}

		//If the player looses,game state is set to 4
		if (state==2 && ss.game_end()==true)
		{
			state=4;		
		}

		if(state==4) //4: gameover
		{
			gTexture = loadTexture("game_over.png");
			if (Mix_PlayingMusic()==0)
			{
				music=Mix_LoadMUS("main.mp3");
				Mix_PlayMusic(music,0);
			}
			state_4 = true;
			ss.drawScore();
			ss.game_end()==false;
			ss.deleteObject(); //this function deleted everything
			
		}
		
		//****************************************************************
    	SDL_RenderPresent(Drawing::gRenderer); //displays the updated renderer

	    SDL_Delay(100);	//causes sdl engine to delay for specified miliseconds
	}
			
}