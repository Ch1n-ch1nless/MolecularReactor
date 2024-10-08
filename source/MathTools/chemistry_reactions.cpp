#include "chemistry_reactions.hpp"
#include <cstdio>

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

    (*molecule_vector)[i] = nullptr;
}

void Math::ChemistryReactSquareCircle(std::vector<Math::Molecule*>* molecule_vector, std::size_t i, std::size_t j)
{
    double massa1    = (*molecule_vector)[i]->GetMassa();
    Vector velocity1 = (*molecule_vector)[i]->GetVelocity();

    double massa2    = (*molecule_vector)[j]->GetMassa();
    Vector velocity2 = (*molecule_vector)[j]->GetVelocity();

    (*molecule_vector)[i]->SetMassa(massa1 + massa2);
    (*molecule_vector)[i]->SetVelocity((massa1 * velocity1 + massa2 * velocity2) / (massa1 + massa2));

    (*molecule_vector)[j] = nullptr;
}

void Math::ChemistryReactSquareSquare(std::vector<Math::Molecule*>* molecule_vector, std::size_t i, std::size_t j)
{
    Vector position = ((*molecule_vector)[i]->GetPosition() + (*molecule_vector)[j]->GetPosition()) / 2.0;

    double massa1   = (*molecule_vector)[i]->GetMassa();
    double massa2   = (*molecule_vector)[j]->GetMassa();

    double radius   = (*molecule_vector)[i]->GetRadius();

    (*molecule_vector)[i] = nullptr;
    (*molecule_vector)[j] = nullptr;

    for (double index = 0; index < massa1 + massa2; index += 64.0)
    {
        Vector new_position(0.0, 2.0 * radius);
        new_position.Rotate(2 * M_PI * index / (massa1 + massa2));
        Vector new_speed = new_position / 2.0;
        new_position += position;
        BlueCircleMolecule* new_ptr = new BlueCircleMolecule(new_position, new_speed);
        molecule_vector->push_back(new_ptr);
    }
}