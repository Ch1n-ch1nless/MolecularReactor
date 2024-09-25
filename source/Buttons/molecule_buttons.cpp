#include "molecule_buttons.hpp"

using namespace Graphics;
using namespace GUI;
using namespace Math;

AddBlueCircleMoleculesButton::AddBlueCircleMoleculesButton(const Math::Vector& position, Math::MolecularManager* manager_ptr) :
    Button       (position, ADD_BLUE_CIRCLE_ICON_WIDTH, ADD_BLUE_CIRCLE_ICON_HEIGHT, ADD_BLUE_CIRCLE_ICONS),
    manager_ptr_ (manager_ptr)
{
}

AddBlueCircleMoleculesButton::AddBlueCircleMoleculesButton(const AddBlueCircleMoleculesButton& other) :
    Button       (other.top_left_corner_, other.width_, other.height_, ADD_BLUE_CIRCLE_ICONS),
    manager_ptr_ (other.manager_ptr_)
{
}

AddBlueCircleMoleculesButton& AddBlueCircleMoleculesButton::operator =(const AddBlueCircleMoleculesButton& other)
{
    manager_ptr_     = other.manager_ptr_;
    width_           = other.width_;
    height_          = other.height_;
    top_left_corner_ = other.top_left_corner_;
    state_           = other.state_;

    for (unsigned int i = 0; i < (unsigned int)State::MaxNumberOfStates ; ++i)
    {
        sprites_[i] = other.sprites_[i];
    }

    return *this;
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

AddRedSquareMoleculesButton::AddRedSquareMoleculesButton(const AddRedSquareMoleculesButton& other) :
    Button       (other.top_left_corner_, other.width_, other.height_, ADD_RED_SQUARE_ICONS),
    manager_ptr_ (other.manager_ptr_)
{
}

AddRedSquareMoleculesButton& AddRedSquareMoleculesButton::operator =(const AddRedSquareMoleculesButton& other)
{
    manager_ptr_     = other.manager_ptr_;
    width_           = other.width_;
    height_          = other.height_;
    top_left_corner_ = other.top_left_corner_;
    state_           = other.state_;

    for (unsigned int i = 0; i < (unsigned int)State::MaxNumberOfStates ; ++i)
    {
        sprites_[i] = other.sprites_[i];
    }

    return *this;
}

void AddRedSquareMoleculesButton::Act()
{
    manager_ptr_->CreateRedSquareMolecule();
}
