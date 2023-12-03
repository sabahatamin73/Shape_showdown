#include "bomb.hpp"
#include <iostream>

using namespace std;

//Bomb dropped vertically downwards
void Bomb::dropped()
{
    cout<<"dropping"<<endl;
    moverRect.y+=30;
}

//Drawing the bomb, coordinates taken through spritecow.com
void Bomb::draw(){
    srcRect={838,141,119,118};
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
    dropped();
}


int Bomb::get_x()
{
    return moverRect.x;
}

int Bomb::get_y()
{
    return moverRect.y;
}

//Accessing the moverrect to get hold of the current position
SDL_Rect* Bomb::getMover()
{
    return &moverRect;
}

//Coordinates taken through spritecow.com
Bomb::Bomb(int x, int y)
{
    srcRect = {838,141,119,118};
    moverRect = {x, y, 40, 40};
}

