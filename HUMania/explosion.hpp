#pragma once
#include "DrawObjects.hpp"
#include<SDL.h>
#include<iostream>
#include "explosion.hpp"

using namespace std;
class Explosion{
    protected:
    SDL_Rect srcRect, moverRect;


public:
    Explosion(){};   
    SDL_Rect* getMover();
    void draw();
    bool complete=false;
    bool exploding=false;
    int state=0;
    Explosion(int x, int y);
    bool has_exploded();

    ~Explosion()
    { }

};
