#ifndef MOLECULAR_REACTOR_MATH_VECTOR_HPP
#define MOLECULAR_REACTOR_MATH_VECTOR_HPP

#include <cmath>

namespace Math
{
    class Vector
    {
    private:
        double x_, y_, z_;

    public:
        Vector(double x, double y, double z) :
            x_(x), y_(y), z_(z)
        {
        }

        Vector(const Vector& begin, const Vector& end) :
            x_(end.x_ - begin.x_), y_(end.y_ - begin.y_), z_(end.z_ - begin.z_)
        {
        }

        Vector(const Vector& vector) :
            x_(vector.x_), y_(vector.y_), z_(vector.z_)
        {
        }

        Vector() : x_(0.0), y_(0.0), z_(0.0) {}

        ~Vector() = default;

        double GetX() const { return x_; }
        double GetY() const { return y_; }
        double GetZ() const { return z_; }

        void SetX(double x) { x_ = x; }
        void SetY(double y) { y_ = y; }
        void SetZ(double z) { z_ = z; }

        double Length2() { return x_ * x_ + y_ * y_ + z_ * z_; }
        double Length()  { return sqrt(Length2()); }

        void Normalize()
        {
            double len = Length();

            x_ /= len;
            y_ /= len;
            z_ /= len;
        }

        Vector& operator =(const Vector& vec);

        Vector& operator +=(const Vector& other);
        Vector& operator -=(const Vector& other);
        Vector& operator *=(const double scalar);
    };

    Vector  operator +(const Vector& left,   const Vector& right);
    Vector  operator -(const Vector& left,   const Vector& right);
    double  operator *(const Vector& left,   const Vector& right);
    Vector  operator *(const Vector& src,    const double  scalar);
    Vector  operator *(const double  scalar, const Vector& src);
} // namespace Math


#endif