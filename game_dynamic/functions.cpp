#include "functions.hpp"

byte modulus(const s_byte &x)
{
    if (x < 0)
        return 0-x;
    else
        return x;
}