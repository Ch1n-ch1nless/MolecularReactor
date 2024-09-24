#ifndef MOLECULAR_REACTOR_MATH_MOLECULAR_MANAGER
#define MOLECULAR_REACTOR_MATH_MOLECULAR_MANAGER

#include "molecule.hpp"
#include <list>

namespace Math
{
    class MolecularManager
    {
    private:
        std::list<Molecule*> molecule_list_;
        long long            cur_time_;

    public:
        MolecularManager();
        ~MolecularManager();

        void CreateMolecule(const MoleculeType type, const Vector& position, const Vector& velocity, const double radius, const double massa);
        void MoveMolecules();
        void DrawMolecules(Graphics::Window& window);
    };
} // namespace Math 

#endif //MOLECULAR_REACTOR_MATH_MOLECULAR_MANAGER