#ifndef MOLECULAR_REACTOR_MATH_TOOLS_CHEMISTRY_ENGINE
#define MOLECULAR_REACTOR_MATH_TOOLS_CHEMISTRY_ENGINE

#include "molecule.hpp"
#include "chemistry_reactions.hpp"

namespace Math
{
    class ChemistryEngine
    {
    private:
        void 
        (*table_[(unsigned int)Math::MoleculeType::MaxNumberOfTypes][(unsigned int)Math::MoleculeType::MaxNumberOfTypes])(  std::vector<Molecule*>*, 
                                                                                                                            std::size_t, 
                                                                                                                            std::size_t                 );
    public:
         ChemistryEngine();
        ~ChemistryEngine();

        void React(std::vector<Molecule*>* molecule_vector, std::size_t i, std::size_t j);
    };
}

#endif //MOLECULAR_REACTOR_MATH_TOOLS_CHEMISTRY_ENGINE