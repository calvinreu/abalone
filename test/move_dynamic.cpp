#include "../game_dynamic/move_dynamic.hpp"
#include <iostream>

int main()
{
    position testPos{.x = 1, .y = 1};

    std::cout << "right:     " << " x: " << (int)get_field_index(testPos, right     , 1).x << " y: " << (int)get_field_index(testPos, right     , 1).y << "\n";
    std::cout << "left :     " << " x: " << (int)get_field_index(testPos, left      , 1).x << " y: " << (int)get_field_index(testPos, left      , 1).y << "\n";
    std::cout << "top right: " << " x: " << (int)get_field_index(testPos, up_right  , 1).x << " y: " << (int)get_field_index(testPos, up_right  , 1).y << "\n";
    std::cout << "top left : " << " x: " << (int)get_field_index(testPos, up_left   , 1).x << " y: " << (int)get_field_index(testPos, up_left   , 1).y << "\n";
    std::cout << "bot right: " << " x: " << (int)get_field_index(testPos, down_right, 1).x << " y: " << (int)get_field_index(testPos, down_right, 1).y << "\n";
    std::cout << "bot left : " << " x: " << (int)get_field_index(testPos, down_left , 1).x << " y: " << (int)get_field_index(testPos, down_left , 1).y << "\n";

}