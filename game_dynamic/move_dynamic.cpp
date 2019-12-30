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

void set_field_index(position &field, const direction &change, const s_byte &ammount)
{
    if (change < 2)
        if (change == left)
            field.x -= ammount;
        else
            field.x += ammount;
    else if(change < 4)
    {

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

        field.y -= ammount;         
    }
    else
    {
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

        field.y += ammount;            
    }    
}

position get_field_index(const position &field, const direction &change, const s_byte &ammount)
{
    position retVal = field;

    if (change < 2)
        if (change == left)
            retVal.x -= ammount;
        else
            retVal.x += ammount;
    else if(change < 4)
    {
        if(retVal.y > middleLayer)
        {
            if (change == up_right)
                retVal.x += ammount;
        }
        else
        {
            if (change == up_left)
                retVal.x -= ammount;
        }

        retVal.y -= ammount;         
    }
    else
    {
        if(retVal.y < middleLayer)
        {
            if (change == down_right)
                retVal.x += ammount;
        }
        else
        {
            if (change == down_left)
                retVal.x -= ammount;
        }

        retVal.y += ammount;          
    }

    return retVal;
}