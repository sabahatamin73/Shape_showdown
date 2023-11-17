#include "Explosion.hpp"
#include <iostream>

using namespace std;
void Explosion::draw(){

    if (exploding==true)
    {

        if (state==0) //with increment in stage, animation changes
        {   
            srcRect={254, 194, 149, 137};
            state+=1;
            
        }
        else if (state==1)
        {
            srcRect={238, 375, 85, 63};
            state+=1;
            
        }
        else if (state==2)
        {
            srcRect={274,16,89,70};
            state+=1;
            
        }
        else if (state==3)
        {
            srcRect={539, 374, 54, 63};
            state+=1;
            complete = true;
        }
        SDL_RenderCopy(Drawing::gRenderer, Drawing::asset_explosion, &srcRect, &moverRect);
        
    }
}


Explosion::Explosion(int x, int y)
{
    srcRect = {100,123,21,20};
    moverRect = {x, y, 80, 80};
}

void Explosion:: drop()
{
    moverRect.y+=0;
}

//this function checks if explosion is completely animated
bool Explosion::has_exploded()
{
    if (complete==true)
    {   
        //complete=false;
        return true;
    }   
    return false;
}