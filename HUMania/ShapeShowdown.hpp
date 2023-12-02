#pragma once
#include<SDL.h>
#include<vector>
#include<list>
#include <SDL_mixer.h>
#include "Shapes.hpp"
#include "ShootingCharacter.hpp"
#include "bullet.hpp"
#include "explosion.hpp"
#include "bomb.hpp"
#include "life_shooter.hpp"
#include "text.hpp"
#include "Explosion_1.hpp"
// #include <SDL_ttf.h>

using namespace std;

class ShapesShowdown{
    int score = 0;
    SDL_Renderer * gRenderer;
    SDL_Texture * assets;
    TTF_Font* font;
    public:
    Text* t;
    Shooter* sh;
    Explosion* explosive; 
    Explosion_1* explosive_1;
    Life * l;
    void set_life();
    list<Shapes*>Shape; 
    list <Bomb*> bomb;
    void drawObjects();  
    void createObject();
    void bomb_dropping(int x, int y);
    bool flag = false; 
    void shoot();
    Bullet* bullet;
    bool game_end();
    void deleteObject();
    void set_score();
    void drawScore();
    bool state=false;
    list <Bullet*> list_bullets;
    void play_again();
    ShapesShowdown();
    // bool flag = false;
    // int score = 0;

    
};