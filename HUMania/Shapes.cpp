#include "Shapes.hpp"
#include <iostream>

using namespace std;

//Base class, to draw shapes
void Shapes::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
};

SDL_Rect* Shapes::getMover()
{
    return &moverRect;
};

int Shapes::get_y()
{
    return moverRect.y;
};

int Shapes::get_x()
{
    return moverRect.x;
};


