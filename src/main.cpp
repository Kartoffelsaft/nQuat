#include <stdio.h>
#include "quaternion/quaternion.h"
#include "vectors/vector3.h"

int main()
{
    auto r = Quaternion(Vector3(1, 1, 1), 2.09);
    auto rn = r.inverseSansNormalized();
    auto vx = Quaternion(1, 0, 0);
    auto vy = Quaternion(0, 1, 0);
    auto vz = Quaternion(0, 0, 1);

    auto nvx = r * vx * rn;
    auto nvy = r * vy * rn;
    auto nvz = r * vz * rn;

    nvx.print(); printf("\n");
    nvy.print(); printf("\n");
    nvz.print(); printf("\n");
}
