#include<SDL.h>
#include "DrawObjects.hpp"
class Life{
    SDL_Rect srcRect, moverRect;
    public:
    void draw(int value);
    Life();
    Life(int x, int y);
    
  
};
