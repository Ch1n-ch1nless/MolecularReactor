#include "molecule_buttons.hpp"

using namespace Graphics;
using namespace GUI;
using namespace Math;

AddBlueCircleMoleculesButton::AddBlueCircleMoleculesButton(const Math::Vector& position, Math::MolecularManager* manager_ptr) :
    Button       (position, ADD_BLUE_CIRCLE_ICON_WIDTH, ADD_BLUE_CIRCLE_ICON_HEIGHT, ADD_BLUE_CIRCLE_ICONS),
    manager_ptr_ (manager_ptr)
{
}

void AddBlueCircleMoleculesButton::Act()
{
    manager_ptr_->CreateBlueCircleMolecule();
}

AddRedSquareMoleculesButton::AddRedSquareMoleculesButton(const Math::Vector& position, Math::MolecularManager* manager_ptr) :
    Button       (position, ADD_RED_SQUARE_ICON_WIDTH, ADD_RED_SQUARE_ICON_HEIGHT, ADD_RED_SQUARE_ICONS),
    manager_ptr_ (manager_ptr)
{
}

void AddRedSquareMoleculesButton::Act()
{
    manager_ptr_->CreateRedSquareMolecule();
}
