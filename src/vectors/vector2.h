#pragma once

struct Vector2
{
public:
    float x;
    float y;

    Vector2(float const, float const);

    Vector2 normalized() const;

    void print() const;

private:
};
