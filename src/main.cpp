#include <stdio.h>
#include "quaternion/quaternion.h"

int main()
{
    Quaternion q{3, 5, 7, 11};
    auto qn = q.normalized();
    q = q * q.inverse();

    q.print(); printf("\n");
    qn.print(); printf("\n");
}
