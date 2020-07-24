#pragma once
#include <datatypes.h>

extern uint8 convertPositiv(const int8 &x);

template<typename T>
extern T differenceToZero(const T &value){ return value < 0 ? -value : value; }