#pragma once
#include "../game_dynamic/board.hpp"
#include "graphic.hpp"
#include "input.hpp"
#include "output_constants.hpp"
#include <thread>

struct UI_threads
{
    std::thread* t_renderer;
    std::thread* t_input;
};


struct row
{
    byte ammount;
    position first;
    direction row_direction;
};//selected bullets from the first in row direction with ammount

extern UI_threads start_UI(const map &board, bool &running);
extern void run_output(const map &board, const bool &running, const row &selected);
extern void run_input(const map &board, bool &running, row &selected);