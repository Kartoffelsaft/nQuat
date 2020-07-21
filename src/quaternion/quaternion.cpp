#include "quaternion.h"

#include <cmath>
#include <cstdio>
#include <math.h>

Quaternion::Quaternion(float nr, float ni, float nj, float nk)
    : r{nr}, i{ni}, j{nj}, k{nk}
{}

Quaternion::Quaternion(float x, float y, float z)
    : i{x}, j{y}, k{z}
{}

Quaternion Quaternion::operator*(Quaternion const other) const
{
    return Quaternion(
        this->r * other.r - this->i * other.i - this->j * other.j - this->k * other.k,
        this->r * other.i + this->i * other.r + this->j * other.k - this->k * other.j,
        this->r * other.j + this->j * other.r - this->i * other.k + this->k * other.i,
        this->r * other.k + this->k * other.r + this->i * other.j - this->j * other.i
    );
}

Quaternion Quaternion::operator+(Quaternion const other) const
{
    return Quaternion(
        this->r + other.r, 
        this->i + other.i, 
        this->j + other.j, 
        this->k + other.k
    );
}

Quaternion Quaternion::inverse() const
{
    auto div = r*r + i*i + j*j + k*k;
    return Quaternion(r/div, -i/div, -j/div, -k/div);
}

Quaternion Quaternion::normalized() const
{
    auto length = sqrt(r*r + i*i + j*j + k*k);
    return Quaternion(r/length, i/length, k/length, j/length);
}

void Quaternion::print() const
{printf("%f + %fi + %fj + %fk", r, i, j, k);}
