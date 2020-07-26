#pragma once

#include "../vectors/vector2.h"
#include "../vectors/vector3.h"
#include "../quaternion/quaternion.h"
#include "../window/window.h"
#include <tuple>

void refreshRasterizerDists(std::tuple<int, int> const);

void fillTriangle(
    Vector2 const, 
    Vector2 const, 
    Vector2 const, 
    float const,
    Window&, 
    char const
);

char getAppearance(Vector3 const, Vector3 const, Vector3 const);
