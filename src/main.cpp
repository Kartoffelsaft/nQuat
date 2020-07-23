#include <ratio>
#include <stdio.h>
#include <vector>
#include <chrono>
#include <thread>

#include <ncurses.h>

#include "quaternion/quaternion.h"
#include "vectors/vector3.h"
#include "window/window.h"
#include "rasterizer/rasterizer.h"

int main()
{
    auto points = std::vector<Vector3>{
        Vector3(-3, 12, 4),
        Vector3(10, 2, 8),
        Vector3(4, 8, -6)
    };
    auto q = Quaternion(Vector3(-0.4, 0.6, 0.2), 0.02);
    auto qn = q.inverseSansNormalized();

    Window w;

    while(!w.getInput().has_value())
    {
        w.clean();
        auto [offsetX, offsetY] = w.middle();

        fillTriangle(
            Vector3(points[0].x + offsetX, points[0].y + offsetY, 0), 
            Vector3(points[1].x + offsetX, points[1].y + offsetY, 0), 
            Vector3(points[2].x + offsetX, points[2].y + offsetY, 0), 
            w
        );
        
        for(auto point: points)
        {
            w.drawChar(point.x + offsetX, point.y + offsetY, 'O');
        }

        w.refreshScreen();

        for(auto& point: points)
        {
            point = q * point * qn;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
}
