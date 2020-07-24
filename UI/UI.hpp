#pragma once
#include "../game_dynamic/board.hpp"
#include "graphic.hpp"
#include "input.hpp"
#include "row.h"
#include <thread>

extern void start_UI(map &board, bool &running);
extern void run_UI(map &board, bool &running);
extern void run_input(map &board, row &selected, bool &running);
extern void run_output(const map &board, const row &selected, const bool &running);