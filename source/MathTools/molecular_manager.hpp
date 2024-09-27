#ifndef MOLECULAR_REACTOR_MATH_MOLECULAR_MANAGER
#define MOLECULAR_REACTOR_MATH_MOLECULAR_MANAGER

#include "molecule.hpp"
#include "chemistry_engine.hpp"
#include "physical_engine.hpp"
#include <vector>

namespace Math
{
    class MolecularManager
    {
    private:
        ChemistryEngine         chemical_engine_;
        PhysicalEngine          physical_engine_;

        std::vector<Molecule*>  molecule_list_;
        Vector                  spawn_point_; 
        long long               cur_time_;

    public:
        MolecularManager(const Vector& spawn_point);
        MolecularManager(const MolecularManager& molecular_manager);
        ~MolecularManager();

        void CreateMolecule(const MoleculeType type, const Vector& velocity, const double massa);
        
        void AddMolecule(Molecule* molecule);
        
        void LaunchPhysicalEngine(Walls& walls);

        std::vector<Molecule*>* GetUpdatedMoleculeData();
    };
} // namespace Math 

#endif //MOLECULAR_REACTOR_MATH_MOLECULAR_MANAGER