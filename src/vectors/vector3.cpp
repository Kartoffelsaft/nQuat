#include "vector3.h"
#include <math.h>

Vector3::Vector3(float nx, float ny, float nz)
    : x{nx}, y{ny}, z{nz}
{}

Vector3 Vector3::normalized() const
{
    auto length = sqrt(x*x + y*y + z*z);
    return Vector3(x/length, y/length, z/length);
}
