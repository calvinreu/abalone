#pragma once
#include "SDL2/SDL.h"

const Uint32 Delay_timeDelay = 3;//delay when launching SDL_Delay
const Uint32 FPS = 30;
const Uint32 frameTime = (1000 / FPS) - Delay_timeDelay;
