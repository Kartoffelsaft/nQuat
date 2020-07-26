#include "rasterizer.h"
#include <algorithm>
#include <cmath>
#include <vector>

std::vector<float> dists;

void refreshRasterizerDists(std::tuple<int, int> const size)
{
    dists.clear();
    dists.resize(std::get<0>(size) * std::get<1>(size), INFINITY);
}

void drawLine(
    Vector2 const where, 
    int const length, 
    float const distance, 
    Window& w,
    char const appearance
){
    auto const [sX, sY] = w.size();
    for(int i = std::max((int) where.x, 0); i < length + where.x; i++)
    {
        if(i > sX) break;
        int const index = ((int) where.y) * sX + i;
        if(index > dists.size() || index < 0) break;
        if(distance < dists[index]) 
        {
            w.drawChar(i, where.y, appearance);
            dists[index] = distance;
        }
    }
}

void fillTriangle(
    Vector2 const a, 
    Vector2 const b, 
    Vector2 const c, 
    float const distance,
    Window& w, 
    char const appearance
){
    Vector2 const & top = a.y < b.y? b.y < c.y? c : b : a.y < c.y? c : a;
    Vector2 const & bottom = a.y > b.y? b.y > c.y? c : b : a.y > c.y? c : a;
    Vector2 const & middle = (a.y != top.y && a.y != bottom.y)? a
                            :(b.y != top.y && b.y != bottom.y)? b
                            : c;

    float dx1=-(top.x-middle.x)/(top.y-middle.y);
	float dx2=-(top.x-bottom.x)/(top.y-bottom.y);
	float dx3=-(middle.x-bottom.x)/(middle.y-bottom.y);

    auto beginLine = top;
    float length = 0;

    if(dx1 < dx2)
    {
        while(beginLine.y > middle.y)
        {
            drawLine(beginLine, length, distance, w, appearance);
            beginLine.y -= 1;
            beginLine.x += dx1;
            length += dx2 - dx1;
        }

        beginLine = middle;
        length = (top.y - middle.y) * (dx2 - dx1);

        while(beginLine.y > bottom.y)
        {
            drawLine(beginLine, length, distance, w, appearance);
            beginLine.y -= 1;
            beginLine.x += dx3;
            length += dx2 - dx3;
        }
    }
    else 
    {
        while(beginLine.y > middle.y)
        {
            drawLine(beginLine, length, distance, w, appearance);
            beginLine.y -= 1;
            beginLine.x += dx2;
            length += dx1 - dx2;
        }

        length = (top.y - middle.y) * (dx1 - dx2);

        while(beginLine.y > bottom.y)
        {
            drawLine(beginLine, length, distance, w, appearance);
            beginLine.y -= 1;
            beginLine.x += dx2;
            length += dx3 - dx2;
        }
    }
}

char getAppearance(Vector3 const a,Vector3 const b,Vector3 const c)
{
    static char const * const appearances = "#*!:^,.`";
    Vector3 const v1 = b - a;
    Vector3 const v2 = c - a;
    Vector3 const normal = Vector3(Quaternion(v1) * Quaternion(v2)).normalized();
    int const brightness_level = [&](){
        if(normal.y >= 1) return 7;
        else if(normal.y <= -1) return 0;
        else return (int)((normal.y + 1) * 4);
    }();
    return appearances[brightness_level];
}
