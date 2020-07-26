#include <cstddef>
#include <ratio>
#include <stdio.h>
#include <vector>
#include <chrono>
#include <thread>

#include <ncurses.h>

#include "quaternion/quaternion.h"
#include "vectors/vector2.h"
#include "vectors/vector3.h"
#include "window/window.h"
#include "rasterizer/rasterizer.h"

int main()
{
    auto points = std::vector<float>{
        #include "../models/sphere.vtx"
    };
    auto const tris = std::vector<size_t>{
        #include "../models/sphere.tri"
    };
    auto const q = Quaternion(Vector3(1, 1, 0), 0.01);
    auto const qn = q.inverseSansNormalized();

    Window w;

    while(!w.getInput().has_value())
    {
        w.clean();
        auto [offsetX, offsetY] = w.middle();

        for(auto i = 0; i < tris.size(); i += 3)
        {
            auto const * const pa = &points[3 * (tris[i + 0] - 1)];
            auto const * const pb = &points[3 * (tris[i + 1] - 1)];
            auto const * const pc = &points[3 * (tris[i + 2] - 1)];
            auto const va = Vector3(pa[0], pa[1], pa[2]);
            auto const vb = Vector3(pb[0], pb[1], pb[2]);
            auto const vc = Vector3(pc[0], pc[1], pc[2]);

            auto const appearance = getAppearance(va, vb, vc);

            auto const scale = 5;

            fillTriangle(
                Vector2(va.x * scale + offsetX, va.y * scale + offsetY), 
                Vector2(vb.x * scale + offsetX, vb.y * scale + offsetY), 
                Vector2(vc.x * scale + offsetX, vc.y * scale + offsetY), 
                w, appearance
            );
        }
        
        w.refreshScreen();

        for(auto i = 0; i < points.size(); i += 3)
        {
            auto point = Vector3(
                points[i + 0],
                points[i + 1],
                points[i + 2]
            );

            point = q * point * qn;
            
            points[i + 0] = point.x;
            points[i + 1] = point.y;
            points[i + 2] = point.z;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
}
