#include "move_dynamic.hpp"

direction opposite_direction(const direction &first)
{
    if(first < 2)
        if(first == right)
            return left;
        else
            return right;
    else if (first < 4)
        if (first == up_right)
            return down_left;
        else
            return down_right;
    else
        if (first == down_right)
            return up_left;
        else
            return up_right;
        
        
    
}

void set_field_index(position &field, const direction &change, const size_t &ammount)
{
    if (change < 2)//left right
        if (change == left)
            field.x -= ammount;
        else
            field.x += ammount;
    else if(change < 4)//up
    {
        s_byte yPos = field.y - ammount;

        if (change == up_right)
        {
            for (field.y; field.y > yPos; field.y--)
                if(field.y > middleLayer)
                    field.x++;
            
        }
        else
        {
            for (field.y; field.y > yPos; field.y--)
                if (!(field.y > middleLayer))
                    field.x--;
        }   
    }
    else//down
    {
        s_byte yPos = field.y + ammount;

        if (change == down_right)
        {
            for (field.y; field.y < yPos; field.y++)
                if (field.y < middleLayer)
                    field.x++;
        }
        else
        {
            for (field.y; field.y < yPos; field.y++)
                if (!(field.y < middleLayer))
                    field.x--;
        }

    }    
}

position get_field_index(const position &field, const direction &change, const size_t &ammount)
{
    position retVal = field;
    set_field_index(retVal, change, ammount);
    return retVal;
}