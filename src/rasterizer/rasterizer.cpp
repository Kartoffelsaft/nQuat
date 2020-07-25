#include "rasterizer.h"

void fillTriangle(Vector2 const a, Vector2 const b, Vector2 const c, Window& w)
{
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
            w.drawLine(beginLine.x, beginLine.y, '@', length + 0.5);
            beginLine.y -= 1;
            beginLine.x += dx1;
            length += dx2 - dx1;
        }

        while(beginLine.y > bottom.y)
        {
            w.drawLine(beginLine.x, beginLine.y, '@', length + 0.5);
            beginLine.y -= 1;
            beginLine.x += dx3;
            length += dx2 - dx3;
        }
    }
    else 
    {
        while(beginLine.y > middle.y)
        {
            w.drawLine(beginLine.x, beginLine.y, '@', length + 0.5);
            beginLine.y -= 1;
            beginLine.x += dx2;
            length += dx1 - dx2;
        }

        while(beginLine.y > bottom.y)
        {
            w.drawLine(beginLine.x, beginLine.y, '@', length + 0.5);
            beginLine.y -= 1;
            beginLine.x += dx2;
            length += dx3 - dx2;
        }
    }
}
