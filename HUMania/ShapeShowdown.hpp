#pragma once
#include<SDL.h>
#include<vector>
#include<list>
#include <SDL_mixer.h>
#include "Shapes.hpp"
#include "ShootingCharacter.hpp"
#include "bullet.hpp"
#include "explosion.hpp"

using namespace std;

class ShapesShowdown{

    SDL_Renderer * gRenderer;
    SDL_Texture * assets;
    
    public:
    Shooter* sh;
    Explosion* explosive; 
    list<Shapes*>Shape; //list of all animals
    void drawObjects();  //draws and create objects and includes functionality for score, health implementation too
    void createObject();
    //initially the score is set to 50
    bool flag; //responsible to implement the game end logic
    void shoot();
    Bullet* bullet;
    bool game_end();
    void deleteObject();
    bool state=false;
    list <Bullet*> list_bullets;
    ShapesShowdown();

    
};