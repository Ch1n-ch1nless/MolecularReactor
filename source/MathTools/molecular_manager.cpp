#include "molecular_manager.hpp"

#include <chrono>

using namespace Math;
using namespace Graphics;

MolecularManager::MolecularManager(const Vector& spawn_point) :
    molecule_list_(),
    spawn_point_  (spawn_point),
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

void MolecularManager::CreateMolecule(const MoleculeType type, const Vector& velocity, const double radius, const double massa)
{
    Molecule* new_molecule = new Molecule(spawn_point_, velocity, type, radius, massa);
    molecule_list_.push_back(new_molecule);
}

void MolecularManager::CreateBlueCircleMolecule()
{
    double dx = (double)(rand() % 1000) / 100.0;
    double dy = (double)(rand() % 1000) / 100.0;

    CreateMolecule(MoleculeType::BlueCircle, {dx, dy}, 1.0, 1.0);
}

void MolecularManager::CreateRedSquareMolecule ()
{
    double dx = (double)(rand() % 1000) / 100.0;
    double dy = (double)(rand() % 1000) / 100.0;

    CreateMolecule(MoleculeType::RedSquare, {dx, dy}, 1.5, 2.25);
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

void MolecularManager::CollideMolecules()
{
    for (std::size_t i = 1; i < molecule_list_.size(); ++i)
    {
        for (std::size_t j = 0; j < i; ++j)
        {
            if (*(molecule_list_[i]) == *(molecule_list_[j]))
            {
                Collide(molecule_list_[i], molecule_list_[j]);
            }
        }
    }
}