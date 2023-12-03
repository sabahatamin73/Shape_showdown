#pragma once
#include "DrawObjects.hpp"
#include<SDL.h>
#include<iostream>
#include "explosion.hpp"

using namespace std;
class Explosion_1{
    protected:
    SDL_Rect srcRect, moverRect;

public:
    Explosion_1(){};   
    void draw();
    Explosion_1(int x, int y);
    ~Explosion_1()
    {}

};