#include "physical_engine.hpp"

Math::PhysicalEngine::PhysicalEngine(ChemistryEngine* chemistry_engine) :
    molecule_array_  (nullptr),
    chemistry_engine_(chemistry_engine)
{
}

Math::PhysicalEngine::PhysicalEngine(std::vector<Molecule*>* molecule_array, ChemistryEngine* chemistry_engine) :
    molecule_array_  (molecule_array),
    chemistry_engine_(chemistry_engine)
{
}

Math::PhysicalEngine::~PhysicalEngine()
{
}

void Math::PhysicalEngine::UpdateMoleculeData(std::vector<Math::Molecule*>* new_data)
{
    molecule_array_ = new_data;
}

double Math::PhysicalEngine::CalcTemperature() const
{
    double sum_energy = 0.0;

    for (Math::Molecule* molecule : *molecule_array_)
    {
        sum_energy += molecule->GetEnergy();
    }

    return 2.0 * sum_energy / (3.0 * kBoltzmann);
}

double Math::PhysicalEngine::CalcPressure(double volume) const
{
    double sum_energy = 0.0;

    for (Math::Molecule* molecule : *molecule_array_)
    {
        sum_energy += molecule->GetEnergy();
    }

    return 2.0 * sum_energy / (3.0 * volume);
}

void Math::PhysicalEngine::CollideMolecules()
{
    for (std::size_t i = 1; i < (*molecule_array_).size(); ++i)
    {
        for (std::size_t j = 0; j < i; ++j)
        {
            if (*((*molecule_array_)[i]) == *((*molecule_array_)[j]))
            {
                double sum_energy = (*molecule_array_)[i]->GetEnergy() + (*molecule_array_)[j]->GetEnergy();

                Collide((*molecule_array_)[i], (*molecule_array_)[j]);

                if (sum_energy > maxEnergy)
                {
                    chemistry_engine_->React(molecule_array_, i, j);
                }
            }
        }
    }
}

void Math::PhysicalEngine::MoveMolecules(double dt)
{
    for (Molecule* molecule_ptr : *molecule_array_)
    {
        molecule_ptr->Move(dt);
    }
}

void Math::PhysicalEngine::CollideMolecules(Walls& walls)
{
    for (std::size_t i = 0; i < molecule_array_->size(); ++i)
    {
        walls.CheckCollision(*((*molecule_array_)[i]));
    }
}
