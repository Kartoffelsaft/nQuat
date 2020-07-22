#include <stdio.h>
#include "quaternion/quaternion.h"
#include "vectors/vector3.h"

int main()
{
    auto const r = Quaternion(Vector3(1, 1, 1), 2.09);
    auto const rn = r.inverseSansNormalized();
    auto const vx = Vector3(1, 0, 0);
    auto const vy = Vector3(0, 1, 0);
    auto const vz = Vector3(0, 0, 1);

    Vector3 const nvx = r * vx * rn;
    Vector3 const nvy = r * vy * rn;
    Vector3 const nvz = r * vz * rn;

    nvx.print(); printf("\n");
    nvy.print(); printf("\n");
    nvz.print(); printf("\n");
}
