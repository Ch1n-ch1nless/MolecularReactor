#ifndef MOLECULAR_REACTOR_MATH_TOOLS_CUSTOM_MOLECULES_HPP
#define MOLECULAR_REACTOR_MATH_TOOLS_CUSTOM_MOLECULES_HPP

#include "molecule.hpp"

namespace Math
{
    class BlueCircleMolecule : public Molecule
    {
    public:
         BlueCircleMolecule(const Vector& position);
         BlueCircleMolecule(const Vector& position, const Vector& velocity);
        ~BlueCircleMolecule();
    };

    class RedSquareMolecule : public Molecule
    {
    public:
         RedSquareMolecule(const Vector& position);
         RedSquareMolecule(const Vector& position, const Vector& velocity);
        ~RedSquareMolecule();
    };
} // namespace Math


#endif //MOLECULAR_REACTOR_MATH_TOOLS_CUSTOM_MOLECULES_HPP