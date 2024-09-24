#include "molecular_manager.hpp"

#include <chrono>

using namespace Math;
using namespace Graphics;

MolecularManager::MolecularManager() :
    molecule_list_(),
    cur_time_     (0ll)
{
}

MolecularManager::~MolecularManager()
{
    for (Molecule* molecule : molecule_list_)
    {
        delete molecule;
    }
}

void MolecularManager::CreateMolecule(const MoleculeType type, const Vector& position, const Vector& velocity, const double radius, const double massa)
{
    Molecule* new_molecule = new Molecule(position, velocity, type, radius, massa);
    molecule_list_.push_back(new_molecule);
}

static long long GetTime()
{
    auto now = std::chrono::system_clock::now();

    return std::chrono::duration_cast<std::chrono::milliseconds>( now.time_since_epoch()).count();
}

void MolecularManager::MoveMolecules()
{
    long long new_time = GetTime();
    double    dt       = (double)(new_time - cur_time_) / 1000.0;

    for (Molecule* molecule_ptr : molecule_list_)
    {
        molecule_ptr->Move(dt);
    }

    cur_time_ = new_time;
}

void MolecularManager::DrawMolecules(Window& window)
{
    for (Molecule* molecule_ptr : molecule_list_)
    {
        molecule_ptr->Draw(window);
    }
}