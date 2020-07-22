#pragma once

struct Quaternion;  // stop recursion error
struct Vector3
{
public:
    float x;
    float y;
    float z;

    Vector3(float, float, float);
    Vector3(Quaternion);

    Vector3 normalized() const;

    void print() const;

private:
};
