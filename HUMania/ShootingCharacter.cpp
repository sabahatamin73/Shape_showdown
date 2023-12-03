#include "ShootingCharacter.hpp"
using namespace std;
#include <iostream>

void Shooter::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);    
}
void Shooter::movement(int move){
    //if the shooter reaches the end of the screen horizontally, he appears from the beginning
    if (move==1)
    {
        if (moverRect.x < 0)
        {
            moverRect.x = 1300;
        }
        moverRect.x=moverRect.x-30;
    }
    if (move==2)
    {
        if (moverRect.x > 1300)
            moverRect.x= 0;
            moverRect.x = moverRect.x+30;
    }    
}

int Shooter::get_x()
{
    return moverRect.x;
}

int Shooter::get_y()
{
    return moverRect.y;
}

SDL_Rect* Shooter::get_mover()
{
    return &moverRect;
}

Shooter::Shooter(int x, int y)
{    
    srcRect={992,399,234, 458};
    moverRect={x,y,80,100};
}


bool Shooter::operator<(int i)
{
    return (life < i)
}

bool Shooter:: operator>(int i)
{
    return (life > i)
}


bool Shooter:: operator==(int i)
{
    return (life == i)
}

bool Shooter::CharacterDestroyed()
{
    return (life == 0)
}

int Shooter::get_life()
{
    return life;
}

void Shooter::set_life(int l)
{
    life = l;
}

void Shooter::set_coordinates()
{
    moverRect.x = 730;
    moverRect.y = 545;
}