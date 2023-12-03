#include "Bullet.hpp"
using namespace std;
#include <iostream>

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

Bullet::Bullet(int x, int y)
{    
    srcRect={838,141,119,118};
    moverRect={x+50,y-20,15,15};
}

void Bullet::shot() {
    moverRect.y -= 30;
}