#pragma once
#include "DrawObjects.hpp"
#include<SDL.h>
#include <iostream>

using namespace std;
class Bomb{
    protected:
    SDL_Rect srcRect, moverRect;


public:
    Bomb(){};  
    void draw(); 
    SDL_Rect* getMover();
    int get_y();
    Bomb(int x, int y);
    int get_x();
    void dropped();
    ~ Bomb()
    {}
};
