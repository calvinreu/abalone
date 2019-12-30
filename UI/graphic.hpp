#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include "../game_dynamic/board.hpp"
#include "../game_dynamic/move_dynamic.hpp"
#include "../bugtracker.hpp"
#include "rect.hpp"

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

    SDL_Surface* ballS = NULL;
    SDL_Surface* boardS = NULL;

    split_texture ball;
public:

    void new_frame(const position &selected, const byte &ammount, const direction &row_direction, const map &board);

    graphic();
    ~graphic();
};
