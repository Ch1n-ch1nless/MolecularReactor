#ifndef MOLECULAR_REACTOR_MATH_TOOLS_PHYSICAL_ENGINE_HPP
#define MOLECULAR_REACTOR_MATH_TOOLS_PHYSICAL_ENGINE_HPP

#include "chemistry_engine.hpp"
#include "molecule.hpp"
#include "walls.hpp"
#include <vector>

namespace Math
{
    class PhysicalEngine
    {
    private:
        std::vector<Molecule*>* molecule_array_;  
        ChemistryEngine*        chemistry_engine_;

        const double kBoltzmann = 1.38;
        const double maxEnergy  = 100.0;

    public:
         PhysicalEngine(ChemistryEngine* chemistry_engine);
         PhysicalEngine(std::vector<Molecule*>* molecule_array, ChemistryEngine* chemistry_engine);
        ~PhysicalEngine();

        void UpdateMoleculeData(std::vector<Molecule*>* new_data);

        double CalcTemperature() const ;
        double CalcPressure(double volume) const ;

        void MoveMolecules(double dt);
        void CollideMolecules();
        void CollideMolecules(Walls& walls);
    };
}

#endif //MOLECULAR_REACTOR_MATH_TOOLS_PHYSICAL_ENGINE_HPP