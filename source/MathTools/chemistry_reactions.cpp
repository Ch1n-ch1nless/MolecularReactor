#include "chemistry_reactions.hpp"

void Math::ChemistryReactCircleCircle(std::vector<Math::Molecule*>* molecule_vector, std::size_t i, std::size_t j)
{
    return;
}

void Math::ChemistryReactCircleSquare(std::vector<Math::Molecule*>* molecule_vector, std::size_t i, std::size_t j)
{
    double massa1    = (*molecule_vector)[j]->GetMassa();
    Vector velocity1 = (*molecule_vector)[j]->GetVelocity();

    double massa2    = (*molecule_vector)[i]->GetMassa();
    Vector velocity2 = (*molecule_vector)[i]->GetVelocity();

    (*molecule_vector)[j]->SetMassa(massa1 + massa2);
    (*molecule_vector)[j]->SetVelocity((massa1 * velocity1 + massa2 * velocity2) / (massa1 + massa2));

    molecule_vector->erase(molecule_vector->begin() + i);
}

void Math::ChemistryReactSquareCircle(std::vector<Math::Molecule*>* molecule_vector, std::size_t i, std::size_t j)
{
    double massa1    = (*molecule_vector)[i]->GetMassa();
    Vector velocity1 = (*molecule_vector)[i]->GetVelocity();

    double massa2    = (*molecule_vector)[j]->GetMassa();
    Vector velocity2 = (*molecule_vector)[j]->GetVelocity();

    (*molecule_vector)[i]->SetMassa(massa1 + massa2);
    (*molecule_vector)[i]->SetVelocity((massa1 * velocity1 + massa2 * velocity2) / (massa1 + massa2));

    molecule_vector->erase(molecule_vector->begin() + j);
}

void Math::ChemistryReactSquareSquare(std::vector<Math::Molecule*>* molecule_vector, std::size_t i, std::size_t j)
{
    Vector position = (*molecule_vector)[i]->GetPosition();

    double massa1    = (*molecule_vector)[i]->GetMassa();

    double massa2    = (*molecule_vector)[j]->GetMassa();

    molecule_vector->erase(molecule_vector->begin() + j);
    molecule_vector->erase(molecule_vector->begin() + j);

    for (double index = 0; index < massa1 + massa2; i += 1.0)
    {
        Molecule* new_ptr = new Molecule(position, MoleculeType::BlueCircle, 1.0);
        molecule_vector->push_back(new_ptr);
    }
}