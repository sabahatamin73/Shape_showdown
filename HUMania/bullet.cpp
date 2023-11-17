#include "Bullet.hpp"
using namespace std;
#include <iostream>

void Bullet::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::asset_bullet, &srcRect, &moverRect);
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
    srcRect={650, 141, 111, 539};
    moverRect={x+50,y-20,20,20};
}

void Bullet::shot() {
    moverRect.y -= 30;
}