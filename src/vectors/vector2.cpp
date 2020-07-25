#include "vector2.h"
#include <cstdio>
#include <math.h>

Vector2::Vector2(float const nx, float const ny) 
    : x{nx}, y{ny}
{}

Vector2 Vector2::normalized() const
{
    auto length = sqrt(x*x + y*y);
    return Vector2(x/length, y/length);
}

void Vector2::print() const
{printf("{%f, %f}", x, y);}
