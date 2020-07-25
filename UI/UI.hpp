#pragma once
#include "../game_dynamic/game.hpp"
#include "graphic.hpp"
#include "input.hpp"
#include "row.h"
#include <thread>

extern void start_UI(game &game_info);
extern void run_input(game &game_info, row &selected);
extern void run_output(const game &game_info, const row &selected);