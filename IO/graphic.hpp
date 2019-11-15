#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "../game dynamic/board.hpp"
#include "rect.hpp"

extern tile* map[9];

class split_texture
{
private:
    SDL_Texture* texture;
public:
    void RenderCopy(SDL_Rect* src, SDL_Rect* dest, SDL_Renderer* renderer) const { SDL_RenderCopy(renderer, texture, src, dest); }
    void LoadFromSurface(SDL_Surface* src, SDL_Renderer* renderer){ texture = SDL_CreateTextureFromSurface(renderer, src); }
    void free() { SDL_DestroyTexture(texture); }
};

class graphic
{
private:
    SDL_Renderer* renderer = NULL;
    SDL_Window* window     = NULL;

    SDL_Surface* ballS = NULL;
    SDL_Surface* board = NULL;

    split_texture ball;
public:

    void new_frame(std::vector<position> selectedBalls);

    graphic();
    ~graphic();
};
