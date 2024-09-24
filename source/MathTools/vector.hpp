#ifndef MOLECULAR_REACTOR_MATH_VECTOR_HPP
#define MOLECULAR_REACTOR_MATH_VECTOR_HPP

#include <cmath>

namespace Math
{
    class Vector
    {
    private:
        double x_, y_;

    public:
        Vector(double x, double y) :
            x_(x), y_(y)
        {
        }

        Vector(const Vector& begin, const Vector& end) :
            x_(end.x_ - begin.x_), y_(end.y_ - begin.y_)
        {
        }

        Vector(const Vector& vector) :
            x_(vector.x_), y_(vector.y_)
        {
        }

        Vector() : x_(0.0), y_(0.0) {}

        ~Vector() = default;

        double GetX() const { return x_; }
        double GetY() const { return y_; }

        void SetX(double x) { x_ = x; }
        void SetY(double y) { y_ = y; }

        double Length2() const { return x_ * x_ + y_ * y_; }
        double Length()  const { return sqrt(Length2()); }

        void Normalize()
        {
            double len = Length();

            x_ /= len;
            y_ /= len;
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
    Vector  operator /(const Vector& src,    const double scalar);

} // namespace Math


#endif //MOLECULAR_REACTOR_MATH_VECTOR_HPP