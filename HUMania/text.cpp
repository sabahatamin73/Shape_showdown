#include <iostream>
#include "text.hpp"
using namespace std;

Text::Text() : Message(nullptr), font(nullptr), surfaceMessage(nullptr) {
    if (TTF_Init() == -1) {
        cerr << "TTF initialization failed: " << TTF_GetError() << endl;
    }

    font = TTF_OpenFont("font.ttf", 80);
    if (font == nullptr) {
        cerr << "Failed to load font: " << TTF_GetError() << endl;
    }
    White = { 255, 255, 255 };
}

Text::~Text() {
    if (Message) {
        SDL_DestroyTexture(Message);
    }
    if (font) {
        TTF_CloseFont(font);
    }
    if (surfaceMessage) {
        SDL_FreeSurface(surfaceMessage);
    }
    TTF_Quit(); 
}

void Text::draw(int score) {
    if (font == nullptr) {
        cerr << "Font not loaded!" << endl;
        return; 
    }
    std::string score_txt = "score: " + std::to_string(score);   
    surfaceMessage = TTF_RenderText_Solid(font, score_txt.c_str(), White);
    if (surfaceMessage == nullptr) {
        cerr << "Unable to render text surface: " << TTF_GetError() << endl;
    }

    Message = SDL_CreateTextureFromSurface(Drawing::gRenderer, surfaceMessage);
    if (Message == nullptr) {
        cerr << "Unable to create texture from surface: " << SDL_GetError() << endl;
    }

    moverRect.x = 1150;
    moverRect.y = 20;
    moverRect.w = 150;
    moverRect.h = 80;

    SDL_RenderCopy(Drawing::gRenderer, Message, NULL, &moverRect);

    SDL_FreeSurface(surfaceMessage);
}