#include <SDL.h>
#include "DrawObjects.hpp"
#include <SDL_ttf.h>

class Text {
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* Message;
    TTF_Font* font;
    SDL_Color White;
    SDL_Rect srcRect, moverRect;
    SDL_Surface* surfaceMessage;

public:
    Text();
    ~Text();
    void draw(int score);
};
