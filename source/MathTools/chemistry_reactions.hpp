#ifndef MOLECULAR_REACTOR_MATH_TOOLS_CHEMISTRY_REACTIONS_HPP
#define MOLECULAR_REACTOR_MATH_TOOLS_CHEMISTRY_REACTIONS_HPP

#include "molecule.hpp"
#include "custom_molecules.hpp"
#include <vector>

namespace Math
{
    void ChemistryReactCircleCircle(std::vector<Molecule*>* molecule_vector, std::size_t i, std::size_t j);
    void ChemistryReactCircleSquare(std::vector<Molecule*>* molecule_vector, std::size_t i, std::size_t j);
    void ChemistryReactSquareCircle(std::vector<Molecule*>* molecule_vector, std::size_t i, std::size_t j);
    void ChemistryReactSquareSquare(std::vector<Molecule*>* molecule_vector, std::size_t i, std::size_t j);
}

#endif //MOLECULAR_REACTIONS_MATH_TOOLS_CHEMISTRY_REACTIONS_HPP