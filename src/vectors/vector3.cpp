#include "vector3.h"
#include "../quaternion/quaternion.h"
#include <cstdio>
#include <math.h>

Vector3::Vector3(float const nx, float const ny, float const nz)
    : x{nx}, y{ny}, z{nz}
{}

Vector3::Vector3(Quaternion const q)
    : x{q.i}, y{q.j}, z{q.k}
{}

Vector3 Vector3::operator-(Vector3 const & other) const
{
    return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
}

Vector3 Vector3::normalized() const
{
    auto length = sqrt(x*x + y*y + z*z);
    return Vector3(x/length, y/length, z/length);
}

void Vector3::print() const
{printf("{%f, %f, %f}", x, y, z);}
