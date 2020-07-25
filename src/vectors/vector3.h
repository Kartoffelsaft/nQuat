#pragma once

struct Quaternion;  // stop recursion error
struct Vector3
{
public:
    float x;
    float y;
    float z;

    Vector3(float const, float const, float const);
    Vector3(Quaternion const);

    Vector3 operator-(Vector3 const &) const;
    Vector3 normalized() const;

    void print() const;

private:
};
