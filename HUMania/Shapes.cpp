#include "Shapes.hpp"
#include <iostream>

using namespace std;

// Unit class is well implemented, no need to change it

void Shapes::draw(){
    
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
    cout<<"Drawn"<<endl;
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


