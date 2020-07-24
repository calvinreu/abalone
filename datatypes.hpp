#pragma once

typedef unsigned char byte;
typedef signed char s_byte;
typedef unsigned long int size_t;

template<typename T>
struct pair
{
    T x;
    T y;

    bool operator==(const pair &other){ return x == other.x && y == other.y; }
};

typedef pair<s_byte> position;