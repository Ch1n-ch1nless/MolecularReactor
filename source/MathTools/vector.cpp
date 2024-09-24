#include "vector.hpp"

using namespace Math;

Vector& Vector::operator =(const Vector& vec)
{
    this->x_ = vec.x_;
    this->y_ = vec.y_;
    return *this;
}

Vector& Vector::operator +=(const Vector& other)
{
    x_ += other.x_;
    y_ += other.y_;
    return *this;
}

Vector& Vector::operator -=(const Vector& other)
{
    x_ -= other.x_;
    y_ -= other.y_;
    return *this;
}

Vector& Vector::operator *=(const double scalar)
{
    x_ *= scalar;
    y_ *= scalar;
    return *this;
}

Vector Math::operator +(const Vector& left, const Vector& right)
{
    return Vector(left.GetX() + right.GetX(), left.GetY() + right.GetY());
}

Vector Math::operator -(const Vector& left, const Vector& right)
{
    return Vector(left.GetX() - right.GetX(), left.GetY() - right.GetY());
}

double Math::operator *(const Vector& left, const Vector& right)
{
    return left.GetX() * right.GetX() + left.GetY() * right.GetY();
}

Vector Math::operator *(const Vector& src, const double  scalar)
{
    return Vector(scalar * src.GetX(), scalar * src.GetY());
}

Vector Math::operator *(const double  scalar, const Vector& src)
{
    return Vector(scalar * src.GetX(), scalar * src.GetY());
}

Vector Math::operator /(const Vector& src, const double  scalar)
{
    return Vector(src.GetX() / scalar, src.GetY() / scalar);
}