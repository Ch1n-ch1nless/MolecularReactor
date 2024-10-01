#include "molecule.hpp"

#include <cassert>

using namespace Math;

Molecule::Molecule(const Vector& position, const MoleculeType type, const double massa) :
    pos_      (position),
    velocity_ (),
    radius_   (sqrt(massa)),
    massa_    (massa),
    type_     (type)
{
}

Molecule::Molecule(const Vector& position, const Vector& velocity, const MoleculeType type, const double massa) :
    pos_      (position),
    velocity_ (velocity),
    radius_   (sqrt(massa)),
    massa_    (massa),
    type_     (type)
{
}

void Molecule::Move(double dt)
{
    pos_ += (velocity_ * dt);
}

MoleculeType Molecule::GetType() const
{
    return type_;
}

double Molecule::GetMassa() const
{
    return massa_;
}

double Molecule::GetRadius() const
{
    return radius_;
}

double Molecule::GetEnergy() const
{
    return massa_ * velocity_.Length2() / 2.0;
}

void Molecule::SetMassa(double massa)
{
    massa_  = massa;
    radius_ = sqrt(massa);
}

const Vector& Molecule::GetVelocity() const
{
    return velocity_;
}

void Molecule::SetVelocity(const Vector& new_velocity)
{
    velocity_ = new_velocity;
}

const Vector& Molecule::GetPosition() const
{
    return pos_;
}

void Molecule::SetPosition(const Vector& new_position)
{
    pos_ = new_position;
}

bool Molecule::operator ==(const Molecule& other)
{
    double distance = (pos_ - other.pos_).Length();

    return distance < (radius_ + other.radius_);
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

void Math::Collide(Molecule* molecule1, Molecule* molecule2)
{
    Vector x_axis = molecule2->pos_ - molecule1->pos_;

    Vector velocity1_x = GetProjection(x_axis, molecule1->velocity_);
    Vector velocity1_y = molecule1->velocity_ - velocity1_x;

    Vector velocity2_x = GetProjection(x_axis, molecule2->velocity_);
    Vector velocity2_y = molecule2->velocity_ - velocity2_x;

    CalculateFinalPulse(molecule1->massa_, velocity1_x, molecule2->massa_, velocity2_x);

    molecule1->velocity_ = velocity1_x + velocity1_y;
    molecule2->velocity_ = velocity2_x + velocity2_y;
}
