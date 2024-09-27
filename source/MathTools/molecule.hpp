#ifndef MOLECULAR_REACTOR_MATH_MOLECULE_HPP
#define MOLECULAR_REACTOR_MATH_MOLECULE_HPP

#include "vector.hpp"
#include "molecule_types.hpp"

namespace Math
{
    class Molecule
    {
    protected:
        Vector              pos_;
        Vector              velocity_;
        double              radius_;
        double              massa_;
        MoleculeType        type_;

    public:
        Molecule(const Vector& position, const MoleculeType type, const double massa);
        Molecule(const Vector& position, const Vector& velocity, const MoleculeType type, const double massa);

        virtual ~Molecule() = default;

        void Move(double dt);

        MoleculeType GetType() const;

        double GetMassa() const;
        void   SetMassa(double massa);

        double GetRadius() const;

        double GetEnergy() const;

        const Vector& GetVelocity() const;
        void          SetVelocity(const Vector& new_velocity);

        const Vector& GetPosition() const;

        bool operator ==(const Molecule& other);

        friend void Collide(Molecule* molecule1, Molecule* molecule2);
        
        friend class Wall;
    };

    void Collide(Molecule* molecule1, Molecule* molecule2);

} // namespace Math

#endif //MOLECULAR_REACTOR_MATH_MOLECULE_HPP