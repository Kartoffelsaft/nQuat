#include <stdio.h>
#include <vector>

#include <ncurses.h>

#include "quaternion/quaternion.h"
#include "vectors/vector3.h"
#include "window/window.h"

int main()
{
    auto const startV = Vector3(1, 0, 0);

    for(int i = 0; i < 50; i++)
    {
        auto const q = Quaternion(Vector3(1, 1, 1), 0.1 * i);
        auto const qn = q.inverseSansNormalized();
        Vector3(q * startV * qn).print(); printf("\n");
    }

    Window w;
    w.drawChar(3, 6, 'c');
    w.waitForInput();
}
