#include "chemistry_engine.hpp"

using namespace Math;

ChemistryEngine::ChemistryEngine()
{
    table_[0][0] = ChemistryReactCircleCircle;
    table_[0][1] = ChemistryReactCircleSquare;
    table_[1][0] = ChemistryReactSquareCircle;
    table_[1][1] = ChemistryReactSquareSquare;
}


ChemistryEngine::~ChemistryEngine()
{
}

void ChemistryEngine::React(std::vector<Molecule*>* vector, std::size_t i, std::size_t j)
{
    unsigned int type1 = (unsigned int)((*vector)[i]->GetType());
    unsigned int type2 = (unsigned int)((*vector)[j]->GetType());

    table_[type1][type2](vector, i, j);
}