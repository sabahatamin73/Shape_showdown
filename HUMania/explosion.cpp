#include "Explosion.hpp"
#include <iostream>
using namespace std;

//coordinates taken through spritecow.com, explosion changes its form while falling downwards, 
//this is managed through the state variable
void Explosion::draw(){

    if (exploding==true)
    {

        if (state==0) 
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

//coordinates taken through spritecow.com
Explosion::Explosion(int x, int y)
{
    srcRect = {34,20,147,141};
    moverRect = {x, y, 80, 80};
}

//this function checks if explosion is completely animated
bool Explosion::has_exploded()
{
    if (complete==true)
    {   
        return true;
    }   
    return false;
}