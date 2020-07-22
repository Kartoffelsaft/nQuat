#pragma once

struct Vector3
{
public:
    float x;
    float y;
    float z;

    Vector3(float, float, float);

    Vector3 normalized() const;

private:
};
