#include "Explosion_1.hpp"
#include <iostream>

using namespace std;

void Explosion_1::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

Explosion_1::Explosion_1(int x, int y)
{
    srcRect = {765, 676, 141, 116};
    moverRect = {x, y, 60, 60};
}
