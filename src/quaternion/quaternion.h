#pragma once

#include "../vectors/vector3.h"

struct Quaternion
{
public:
    float r;
    float i;
    float j;
    float k;

    Quaternion(float, float, float, float);
    Quaternion(float, float, float);
    Quaternion(Vector3);
    Quaternion(Vector3, float);

    Quaternion operator*(Quaternion const other) const;
    Quaternion operator+(Quaternion const other) const;
    Quaternion inverse() const;
    Quaternion inverseSansNormalized() const;
    Quaternion normalized() const;

    void print() const;

private:
};
