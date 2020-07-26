#pragma once
#include <SDL2/SDL.h>
#include "../game_dynamic/game.hpp"

const int orbWidth = 50;
const int orbHeight = 50;
const int emptySpace = 50;
const Uint32 Delay_timeDelay = 3;//delay when launching SDL_Delay
const Uint32 FPS = 10;
const Uint32 frameTime = (1000 / FPS) - Delay_timeDelay;


const int topSpace = (2*emptySpace)+orbHeight;
const int botSpace = topSpace;
const int windowHeight = (orbHeight*(layerCount+2))+(4*emptySpace);
const int windowWidth  = orbWidth * layerCount;
const SDL_Rect white_orb = {.x = orbWidth, .y =0, .w = orbWidth, .h = orbHeight};
const SDL_Rect black_orb = {.x = 0, .y = 0, .w = orbWidth, .h = orbHeight};
const SDL_Rect selected_orb = {.x = 2*orbWidth, .y =0, .w = orbWidth, .h = orbHeight};