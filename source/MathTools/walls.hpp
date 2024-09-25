#ifndef MOLECULAR_REACTOR_MATH_WALLS_HPP
#define MOLECULAR_REACTOR_MATH_WALLS_HPP

#include "vector.hpp"
#include "molecule.hpp"

namespace Math
{
    class Wall
    {
    private:
        Vector top_left_corn_;
        Vector low_right_corn_;
        Vector normal_;

    public:
        Wall(const Vector& top_left_corner, const Vector& low_right_corner, const Vector& normal);
        Wall(const double x_begin, const double y_begin, const double x_end, const double y_end, const Vector& normal);

        ~Wall() = default;

        bool operator==(const Molecule& molecule) const;

        void Collide(Molecule& molecule) const;
    };

    class Walls
    {
    private:
        Wall   array_[4];
        Vector top_left_corn_;
        double width_;
        double height_;
    
    public:
        Walls(const Vector& top_left_corner, const Vector& low_right_corner);
        Walls(const Vector& top_left_corner, const double width, const double height);

        ~Walls() = default;

        void CheckCollision(Molecule& molecule);
    };

} // namespace Math

#endif //MOLECULAR_REACTOR_MATH_WALLS_HPP