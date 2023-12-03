#include "Bullet.hpp"
using namespace std;
#include <iostream>

//Drawing a bullet, coordinates taken through spritecow.com
void Bullet::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
    shot();    
}

int Bullet::get_x()
{
    return moverRect.x;
}

int Bullet::get_y()
{
    return moverRect.y;
}

SDL_Rect* Bullet::get_mover()
{
    return &moverRect;
}

//coordinates taken through spritecow.com
Bullet::Bullet(int x, int y)
{    
    srcRect={838,141,119,118};
    moverRect={x+50,y-20,15,15};
}

//Vertically upward motion, opposite to the bomb
void Bullet::shot() {
    moverRect.y -= 30;
}