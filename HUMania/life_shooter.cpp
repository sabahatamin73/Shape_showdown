#include "life_shooter.hpp"
using namespace std;
#include <iostream>
void Life::draw(int value){
    
    for (int i=0;i<value;i++)
    {
        SDL_Rect moverrect =moverRect;
        moverrect.x=moverRect.x+((i*45));
        SDL_RenderCopy(Drawing::gRenderer,Drawing::assets,&srcRect,&moverrect);
    }
    
}


Life::Life()
{
    srcRect = {1484, 727, 130, 121};
    moverRect = {40,560,40,40};
    
}

Life::Life(int x, int y) 
{
    srcRect = {1484, 727, 130, 121};
    moverRect = {x, y, 40, 40};
}
