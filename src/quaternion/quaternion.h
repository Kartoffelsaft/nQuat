#pragma once

struct Quaternion
{
public:
    float r;
    float i;
    float j;
    float k;

    Quaternion(float, float, float, float);
    Quaternion(float, float, float);

    Quaternion operator*(Quaternion const other) const;
    Quaternion operator+(Quaternion const other) const;
    Quaternion inverse() const;
    Quaternion normalized() const;

    void print() const;

private:
};
