#ifndef MOLECULAR_REACTOR_MATH_ABSTRACT_MOLECULE_HPP
#define MOLECULAR_REACTOR_MATH_ABSTRACT_MOLECULE_HPP

#include "vector.hpp"

namespace Math
{
    class AMolecule
    {
    protected:
        Vector pos_;
        Vector velocity_;
        double radius_;
        double massa_;

    public:
        AMolecule(const Vector& position, const double radius);
        AMolecule(const Vector& position, const Vector& velocity, const double radius, const double massa);

        ~AMolecule() = default;

        void Move(double dt);

        bool operator ==(const AMolecule& other);

        friend void Collide(AMolecule& molecule1, AMolecule& molecule2);
        
        friend class Wall;
    };

} // namespace Math

#endif //MOLECULAR_REACTOR_MATH_ABSTRACT_MOLECULE_HPP