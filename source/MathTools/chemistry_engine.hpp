#ifndef MOLECULAR_REACTOR_MATH_TOOLS_CHEMISTRY_ENGINE
#define MOLECULAR_REACTOR_MATH_TOOLS_CHEMISTRY_ENGINE

#include "molecule.hpp"
#include "chemistry_reactions.hpp"

namespace Math
{
    class ChemistryEngine
    {
    private:
        void (table_[(unsigned int)MoleculeType::MaxNumberOfTypes][(unsigned int)MoleculeType::MaxNumberOfTypes])(std::vector<Molecule*>* vector, std::size_t i, std::size_t j);

    public:
         ChemistryEngine();
        ~ChemistryEngine();

        void React(std::vector<Molecule*>* molecule_vector, std::size_t i, std::size_t j);
    };
}

#endif //MOLECULAR_REACTOR_MATH_TOOLS_CHEMISTRY_ENGINE