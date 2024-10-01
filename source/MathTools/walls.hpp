#ifndef MOLECULAR_REACTOR_MATH_WALLS_HPP
#define MOLECULAR_REACTOR_MATH_WALLS_HPP

#include "vector.hpp"
#include "molecule.hpp"

namespace Math
{
    class Walls
    {
    private:
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