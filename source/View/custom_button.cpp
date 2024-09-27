#include "custom_button.hpp"

using namespace View;

AddBlueCircleButton::AddBlueCircleButton(Math::MolecularManager* manager_ptr, const Math::Vector& top_left_corner) :
    BasicButton (ADD_BLUE_CIRCLE_ICON_WIDTH, ADD_BLUE_CIRCLE_ICON_HEIGHT, top_left_corner, ADD_BLUE_CIRCLE_ICONS),
    manager_ptr_(manager_ptr)
{    
}

AddBlueCircleButton::~AddBlueCircleButton()
{
}

void AddBlueCircleButton::Act()
{
    Math::BlueCircleMolecule* new_molecule = new Math::BlueCircleMolecule({400.0, 300.0});
    manager_ptr_->AddMolecule(new_molecule);
}

AddRedSquareButton::AddRedSquareButton(Math::MolecularManager* manager_ptr, const Math::Vector& top_left_corner) :
    BasicButton (ADD_RED_SQUARE_ICON_WIDTH, ADD_RED_SQUARE_ICON_HEIGHT, top_left_corner, ADD_RED_SQUARE_ICONS),
    manager_ptr_(manager_ptr)
{    
}

AddRedSquareButton::~AddRedSquareButton()
{
}

void AddRedSquareButton::Act()
{
    Math::RedSquareMolecule* new_molecule = new Math::RedSquareMolecule({400.0, 500.0});
    manager_ptr_->AddMolecule(new_molecule);
}