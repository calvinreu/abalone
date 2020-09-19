#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include "../game_dynamic/game.hpp"
#include "../game_dynamic/move_dynamic.hpp"
#include "config.h"
#include "row.h"

#define DeforbIMG "./UI/img/orb.png"
#define DefBoardIMG "./UI/img/board.png"

class split_texture
{
private:
    SDL_Texture* texture;
public:
    void RenderCopy(const SDL_Rect* src, const SDL_Rect* dest, SDL_Renderer* renderer) const { SDL_RenderCopy(renderer, texture, src, dest); }
    void LoadFromSurface(SDL_Surface* src, SDL_Renderer* renderer){ texture = SDL_CreateTextureFromSurface(renderer, src); }
    void free() { SDL_DestroyTexture(texture); }
};

class graphic
{
private:
    SDL_Renderer* renderer = NULL;
    SDL_Window* window     = NULL;

    SDL_Surface* orbS = NULL;
    SDL_Surface* boardS = NULL;

    split_texture orb;
public:

    void new_frame(const row &selected, const game &game_info);

    graphic();
    ~graphic();
};
