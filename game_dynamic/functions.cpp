#include "functions.hpp"

uint8 convertPositiv(const int8 &x)
{
    if (x < 0)
        return 0-x;
    else
        return x;
}