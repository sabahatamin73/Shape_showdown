#pragma once
#include "DrawObjects.hpp"
#include<SDL.h>
#include <iostream>

using namespace std;
// Unit class is well implemented, no need to change it

class Shapes{
    protected:
    SDL_Rect srcRect, moverRect;

public:
    Shapes(){};   
    SDL_Rect* getMover();
    virtual void draw();
    virtual void change() = 0;
    int get_y();
    int get_x();
    virtual ~Shapes()
    {
        cout<<"Shapes deleted"<<endl;
    }

};
