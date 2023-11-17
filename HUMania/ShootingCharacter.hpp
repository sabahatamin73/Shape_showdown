#include<SDL.h>
#include "DrawObjects.hpp"
#include <iostream>

using namespace std;
// class for shooter implementation
class Shooter{
    SDL_Rect srcRect, moverRect;
    public:
    void draw();
    void movement(int move);
    // Shooter();
    Shooter(int, int);
    int get_x();
    int get_y();
    SDL_Rect* get_mover();
   ~Shooter(){}
};

