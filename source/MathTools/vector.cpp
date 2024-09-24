#include "vector.hpp"

using namespace Math;

Vector& Vector::operator =(const Vector& vec)
{
    this->x_ = vec.x_;
    this->y_ = vec.y_;
    this->z_ = vec.z_;
    return *this;
}

Vector& Vector::operator +=(const Vector& other)
{
    x_ += other.x_;
    y_ += other.y_;
    z_ += other.z_;
    return *this;
}

Vector& Vector::operator -=(const Vector& other)
{
    x_ -= other.x_;
    y_ -= other.y_;
    z_ -= other.z_;
    return *this;
}

Vector& Vector::operator *=(const double scalar)
{
    x_ *= scalar;
    y_ *= scalar;
    z_ *= scalar;
    return *this;
}

Vector Math::operator +(const Vector& left, const Vector& right)
{
    return Vector(left.GetX() + right.GetX(), left.GetY() + right.GetY(), left.GetZ() + right.GetZ());
}

Vector Math::operator -(const Vector& left, const Vector& right)
{
    return Vector(left.GetX() - right.GetX(), left.GetY() - right.GetY(), left.GetZ() - right.GetZ());
}

double Math::operator *(const Vector& left, const Vector& right)
{
    return left.GetX() * right.GetX() + left.GetY() * right.GetY() + left.GetZ() * right.GetZ();
}

Vector Math::operator *(const Vector& src, const double  scalar)
{
    return Vector(scalar * src.GetX(), scalar * src.GetY(), scalar * src.GetZ());
}

Vector Math::operator *(const double  scalar, const Vector& src)
{
    return Vector(scalar * src.GetX(), scalar * src.GetY(), scalar * src.GetZ());
}