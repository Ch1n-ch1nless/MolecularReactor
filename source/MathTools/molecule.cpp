#include "molecule.hpp"

#include <cassert>

using namespace Math;

Molecule::Molecule(const Vector& position, const MoleculeType type, const double radius, const double massa) :
    pos_      (position),
    velocity_ (),
    radius_   (radius),
    massa_    (massa),
    type_     (type),
    sprite_   ()
{
    switch (type_)
    {
    case MoleculeType::BlueCircle:
        sprite_.LoadFromFile(BLUE_CIRCLE_IMAGE);
        break;

    case MoleculeType::RedSquare:
        sprite_.LoadFromFile(RED_SQUARE_IMAGE);
        break;
    
    default:
        assert(false);
        break;
    }
}

Molecule::Molecule(const Vector& position, const Vector& velocity, const MoleculeType type, const double radius, const double massa) :
    pos_      (position),
    velocity_ (velocity),
    radius_   (radius),
    massa_    (massa),
    type_     (type),
    sprite_   ()
{
    switch (type_)
    {
    case MoleculeType::BlueCircle:
        sprite_.LoadFromFile(BLUE_CIRCLE_IMAGE);
        break;

    case MoleculeType::RedSquare:
        sprite_.LoadFromFile(RED_SQUARE_IMAGE);
        break;
    
    default:
        assert(false);
        break;
    }
}

void Molecule::Move(double dt)
{
    pos_ += (velocity_ * dt);
}

bool Molecule::operator ==(const Molecule& other)
{
    double distance = (pos_ - other.pos_).Length();

    return distance < (radius_ + other.radius_);
}

void Molecule::Draw(Graphics::Window& window)
{
    sprite_.SetPosition(pos_);
    window.Draw(sprite_);
}

static Vector GetProjection(const Vector& axis, const Vector& vector)
{
    double projection_coefficient = (axis * vector) / axis.Length2();
    return projection_coefficient * axis;
}

static void CalculateFinalPulse(const double massa1, Vector& velocity1,
                                const double massa2, Vector& velocity2  )
{
    Vector old_velocity1 = velocity1;
    Vector old_velocity2 = velocity2;

    velocity1 = (2.0 * massa2 * old_velocity2 - (massa1 - massa2) * old_velocity1) / (massa1 + massa2);
    velocity2 = (2.0 * massa1 * old_velocity1 - (massa2 - massa1) * old_velocity2) / (massa1 + massa2) ;
}

void Math::Collide(Molecule &molecule1, Molecule &molecule2)
{
    Vector x_axis = molecule2.pos_ - molecule1.pos_;

    Vector velocity1_x = GetProjection(x_axis, molecule1.velocity_);
    Vector velocity1_y = molecule1.velocity_ - velocity1_x;

    Vector velocity2_x = GetProjection(x_axis, molecule2.velocity_);
    Vector velocity2_y = molecule2.velocity_ - velocity2_x;

    CalculateFinalPulse(molecule1.massa_, velocity1_x, molecule2.massa_, velocity2_x);

    molecule1.velocity_ = velocity1_x + velocity1_y;
    molecule2.velocity_ = velocity2_x + velocity2_y;
}
