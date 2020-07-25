#pragma once

#include "../vectors/vector2.h"
#include "../vectors/vector3.h"
#include "../quaternion/quaternion.h"
#include "../window/window.h"

void fillTriangle(Vector2 const, Vector2 const, Vector2 const, Window&, char const);

char getAppearance(Vector3 const, Vector3 const, Vector3 const);
