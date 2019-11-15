#pragma once
#include "../datatypes.hpp"
#include "board.hpp"

enum direction
{
    up_left = 2,
    up_right = 3,
    right = 0,
    down_right = 4,
    down_left = 5,
    left = 1
};

void get_field_index(position &field, const direction &change, const byte &ammount)
{
    if (change < 2)
        if (change == left)
            field.x -= ammount;
        else
            field.x += ammount;
    else if(change < 4)
    {
        field.y += ammount;

        if(field.y > middleLayer)
        {
            if (change == up_right)
                field.x += ammount;
        }
        else
        {
            if (change == up_left)
                field.x -= ammount;
        }            
    }
    else
    {
        field.y -= ammount;

        if(field.y < middleLayer)
        {
            if (change == down_right)
                field.x += ammount;
        }
        else
        {
            if (change == down_left)
                field.x -= ammount;
        }            
    }    
}