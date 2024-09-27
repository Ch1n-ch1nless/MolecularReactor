#include "custom_molecules.hpp"

using namespace Math;

BlueCircleMolecule::BlueCircleMolecule(const Vector& position) :
    Molecule(position, MoleculeType::BlueCircle, 64.0)
{
    double dx = (double)(rand() % 1001 - 500) / 10.0;
    double dy = (double)(rand() % 1001 - 500) / 10.0;
    
    SetVelocity({dx, dy});
}

BlueCircleMolecule::BlueCircleMolecule(const Vector& position, const Vector& velocity) :
    Molecule(position, velocity, MoleculeType::BlueCircle, 64.0)
{
}

BlueCircleMolecule::~BlueCircleMolecule()
{
}

RedSquareMolecule::RedSquareMolecule(const Vector& position) :
    Molecule(position, MoleculeType::RedSquare, 64.0)
{
    double dx = (double)(rand() % 1001 - 500) / 20.0;
    double dy = (double)(rand() % 1001 - 500) / 20.0;
    
    SetVelocity({dx, dy});
}

RedSquareMolecule::RedSquareMolecule(const Vector& position, const Vector& velocity) :
    Molecule(position, velocity, MoleculeType::RedSquare, 64.0)
{
}

RedSquareMolecule::~RedSquareMolecule()
{
}