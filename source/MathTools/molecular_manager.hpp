#ifndef MOLECULAR_REACTOR_MATH_MOLECULAR_MANAGER
#define MOLECULAR_REACTOR_MATH_MOLECULAR_MANAGER

#include "molecule.hpp"
#include <list>

namespace Math
{
    class MolecularManager
    {
    private:
        std::vector<Molecule*>  molecule_list_;
        Vector                  spawn_point_; 
        long long               cur_time_;

    public:
        MolecularManager(const Vector& spawn_point);
        ~MolecularManager();

        void CreateMolecule(const MoleculeType type, const Vector& velocity, const double radius, const double massa);
        
        void CreateBlueCircleMolecule();
        void CreateRedSquareMolecule ();
        
        void MoveMolecules();
        void DrawMolecules(Graphics::Window& window);
        void CollideMolecules();
    };
} // namespace Math 

#endif //MOLECULAR_REACTOR_MATH_MOLECULAR_MANAGER