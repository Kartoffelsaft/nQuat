#include "quaternion.h"

#include <cmath>
#include <cstdio>
#include <math.h>

Quaternion::Quaternion(float const nr, float const ni, float const nj, float const nk)
    : r{nr}, i{ni}, j{nj}, k{nk}
{}

Quaternion::Quaternion(float const x, float const y, float const z)
    : r{0}, i{x}, j{y}, k{z}
{}

Quaternion::Quaternion(Vector3 const v)
    : r{0}, i{v.x}, j{v.y}, k{v.z}
{}

Quaternion::Quaternion(Vector3 const v, float const angle)
    : r{cos(angle)}, 
      i{v.normalized().x * sin(angle)},
      j{v.normalized().y * sin(angle)},
      k{v.normalized().z * sin(angle)}
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

Quaternion Quaternion::operator*(Vector3 const other) const
{
    return *this * Quaternion(other);
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

Quaternion Quaternion::inverseSansNormalized() const
{return Quaternion(r, -i, -j, -k);}

Quaternion Quaternion::normalized() const
{
    auto length = sqrt(r*r + i*i + j*j + k*k);
    return Quaternion(r/length, i/length, k/length, j/length);
}

void Quaternion::print() const
{printf("%f + %fi + %fj + %fk", r, i, j, k);}
