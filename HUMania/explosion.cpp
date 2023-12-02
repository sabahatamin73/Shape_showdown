#include "Explosion.hpp"
#include <iostream>

using namespace std;
void Explosion::draw(){

    if (exploding==true)
    {

        if (state==0) //with increment in stage, animation changes
        {   
            srcRect={34,20,147,141};
            state+=1;
            
        }
        else if (state==1)
        {
            srcRect={248,37,112, 107};
            state+=0;
            
        }
        SDL_RenderCopy(Drawing::gRenderer, Drawing::asset_explosion, &srcRect, &moverRect);
        
    }
}


Explosion::Explosion(int x, int y)
{
    srcRect = {34,20,147,141};
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