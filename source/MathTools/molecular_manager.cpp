#include "molecular_manager.hpp"

#include <chrono>
#include <cstdio>

using namespace Math;

MolecularManager::MolecularManager(const Vector& spawn_point) :
    chemical_engine_ (),
    physical_engine_ (&chemical_engine_),
    molecule_list_   (),
    spawn_point_     (spawn_point),
    cur_time_        (0ll)
{
}

MolecularManager::MolecularManager(const MolecularManager& molecular_manager) :
    chemical_engine_ (molecular_manager.chemical_engine_),
    physical_engine_ (molecular_manager.physical_engine_),
    molecule_list_   (molecular_manager.molecule_list_),
    spawn_point_     (molecular_manager.spawn_point_),
    cur_time_        (0ll)
{
}

MolecularManager::~MolecularManager()
{
    for (Molecule* molecule : molecule_list_)
    {
        delete molecule;
    }
}

void MolecularManager::CreateMolecule(const MoleculeType type, const Vector& velocity, const double massa)
{
    Molecule* new_molecule = new Molecule(spawn_point_, velocity, type, massa);
    molecule_list_.push_back(new_molecule);
}

void MolecularManager::AddMolecule(Molecule* new_molecule)
{
    molecule_list_.push_back(new_molecule);
}

void MolecularManager::RemoveMolecule(const MoleculeType type)
{
    if (molecule_list_.empty()) return;

    for (int i = static_cast<int>(molecule_list_.size()) - 1; i >= 0; --i)
    {
        Math::MoleculeType cur_type = molecule_list_[i]->GetType();
        if (cur_type == type)
        {
            std::swap(molecule_list_[i], molecule_list_[molecule_list_.size()-1]);
            molecule_list_.pop_back();
            break;
        }
    }
}

static double GetTime(long long& old_time)
{
    auto now = std::chrono::system_clock::now();
    long long new_time = std::chrono::duration_cast<std::chrono::milliseconds>( now.time_since_epoch()).count();

    double dt = static_cast<double>(new_time - old_time) / 1000.0;
    old_time = new_time;

    return dt;
}

void MolecularManager::LaunchPhysicalEngine(Walls& walls)
{
    physical_engine_.UpdateMoleculeData(&molecule_list_);

    double dt = GetTime(cur_time_);

    physical_engine_.MoveMolecules(dt);

    physical_engine_.CollideMolecules();
    physical_engine_.CollideMolecules(walls);
}

std::vector<Molecule*>* MolecularManager::GetUpdatedMoleculeData()
{
    return &molecule_list_;
}