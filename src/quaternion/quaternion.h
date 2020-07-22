#pragma once

#include "../vectors/vector3.h"

struct Quaternion
{
public:
    float r;
    float i;
    float j;
    float k;

    Quaternion(float const, float const, float const, float const);
    Quaternion(float const, float const, float const);
    Quaternion(Vector3 const);
    Quaternion(Vector3 const, float const);

    Quaternion operator*(Quaternion const other) const;
    Quaternion operator*(Vector3 const other) const;
    Quaternion operator+(Quaternion const other) const;
    Quaternion inverse() const;
    Quaternion inverseSansNormalized() const;
    Quaternion normalized() const;

    void print() const;

private:
};
