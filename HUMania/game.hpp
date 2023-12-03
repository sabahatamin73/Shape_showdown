#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <SDL_mixer.h>


class Game{
    //Screen dimension constants
    const int SCREEN_WIDTH = 1350;
    const int SCREEN_HEIGHT = 650;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    //global reference to png image sheets
    SDL_Texture* assets=NULL;
    Mix_Music* music=NULL;
    int state = 0;
    bool restart=false;

public:

    bool init();
    bool loadMedia();
    void close();
    SDL_Texture* loadTexture( std::string path );
    void run();
    int counter = 0;
    int shooter_obj_moving = 0;
    bool pause = false;
    bool play_again = false;
    bool state_4=false;
};

