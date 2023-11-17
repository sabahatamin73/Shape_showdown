#include<SDL.h>
#include "DrawObjects.hpp"
#include <iostream>

using namespace std;
// class for shooter implementation
class Bullet{
    SDL_Rect srcRect, moverRect;
    public:
    void draw();
    void shot();
    // Shooter();
    Bullet(int, int);
    int get_x();
    int get_y();
    SDL_Rect* get_mover();
   ~Bullet(){}
};

