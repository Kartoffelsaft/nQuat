#include <ratio>
#include <stdio.h>
#include <vector>
#include <chrono>
#include <thread>

#include <ncurses.h>

#include "quaternion/quaternion.h"
#include "vectors/vector3.h"
#include "window/window.h"

int main()
{
    auto points = std::vector<Vector3>{
        Vector3(-3, 12, 4),
        Vector3(0, 2, 8),
        Vector3(4, 2, 6)
    };
    auto q = Quaternion(Vector3(1, 0.2, 0.5), 0.02);
    auto qn = q.inverseSansNormalized();

    Window w;

    while(!w.getInput().has_value())
    {
        w.clean();
        auto [offsetX, offsetY] = w.middle();
        for(auto point: points)
        {
            w.drawChar(point.x + offsetX, point.y + offsetY, '.');
        }
        w.refreshScreen();

        for(auto& point: points)
        {
            point = q * point * qn;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
}
