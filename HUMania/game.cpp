#include "game.hpp"
#include "ShapeShowdown.hpp"
#include "DrawObjects.hpp"
#include <iostream>
using namespace std;
SDL_Renderer* Drawing::gRenderer = NULL;
SDL_Texture* Drawing::assets = NULL;
SDL_Texture* Drawing::asset_bullet= NULL;
SDL_Texture* Drawing::asset_explosion = NULL;
// SDL_Texture* Drawing::assets1 = NULL;


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
}

void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(Drawing::assets);
	Drawing::assets=NULL;
	// Drawing::assets1=NULL;
	// Drawing::assets2=NULL;
	// Drawing::assets3=NULL;
	SDL_DestroyTexture(gTexture);
	
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
	//main object created
	ShapesShowdown ss;
	bool quit = false;
	SDL_Event e;


	while( !quit )
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
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
				if (xMouse<346 && yMouse < 548  && xMouse > 182 && yMouse > 408)
				{
					gTexture = loadTexture("GameBackground.jpeg"); //new screen texture opened
					state = 2;
				}

				// //if instructions button is pressed
				// else if (xMouse<997 && yMouse < 548  && xMouse > 384 && yMouse > 408)
				// {
				// 	//madanimals.deleteObject();
				// 	gTexture = loadTexture("GameBackground.png");
				// 	state = 2;	
					
				// }
			}
			if	(e.type == SDL_KEYDOWN && state==2)
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
			if 	(e.key.keysym.sym == SDLK_SPACE)
				{	
					ss.shoot(); //collision function is implemented
					
				}

		}
		SDL_RenderClear(Drawing::gRenderer); //removes everything from renderer
		SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL);//Draws background
		if (state == 2) {
			counter = rand()%100;
			// ss.deleteObject();
			ss.drawObjects();
			if (counter>95)
			{
			 	ss.createObject();
			}
		}


		// SDL_RenderClear(Drawing::gRenderer); //removes everything from renderer
		// SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		
		//****************************************************************
    	SDL_RenderPresent(Drawing::gRenderer); //displays the updated renderer

	    SDL_Delay(100);	//causes sdl engine to delay for specified miliseconds
	}
			
}