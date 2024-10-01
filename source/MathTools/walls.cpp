#include "walls.hpp"

#include <iostream>

using namespace Math;

/*=============================< Walls functions >============================*/

Walls::Walls(const Vector& top_left_corner, const Vector& low_right_corner) :
    top_left_corn_(top_left_corner),
    width_        (low_right_corner.GetX() - top_left_corner.GetX() ),
    height_       (low_right_corner.GetY() - top_left_corner.GetX() )
{
}

Walls::Walls(const Vector& top_left_corner, const double width, const double height) :
    top_left_corn_(top_left_corner),
    width_        (width ),
    height_       (height)
{
}

void Walls::CheckCollision(Molecule& molecule)
{
    Vector cur_position = molecule.GetPosition();
    Vector cur_velocity = molecule.GetVelocity();

    double left_border   = top_left_corn_.GetX() + molecule.GetRadius();
    double right_border  = top_left_corn_.GetX() + width_ - molecule.GetRadius();
    double top_border    = top_left_corn_.GetY() + molecule.GetRadius();
    double bottom_border = top_left_corn_.GetY() + height_ - molecule.GetRadius();

    if (cur_position.GetX() <= left_border)
    {
        cur_position.SetX(left_border);

        if (cur_velocity.GetX() < 0)
        {
            cur_velocity.SetX(-1 * cur_velocity.GetX());
        }
    }

    if (cur_position.GetX() >= right_border)
    {
        cur_position.SetX(right_border);

        if (cur_velocity.GetX() > 0)
        {
            cur_velocity.SetX(-1 * cur_velocity.GetX());
        }
    }

    if (cur_position.GetY() <= top_border)
    {
        cur_position.SetY(top_border);

        if (cur_velocity.GetY() < 0)
        {
            cur_velocity.SetY(-1 * cur_velocity.GetY());
        }
    }

    if (cur_position.GetY() >= bottom_border)
    {
        cur_position.SetY(bottom_border);

        if (cur_velocity.GetY() > 0)
        {
            cur_velocity.SetY(-1 * cur_velocity.GetY());
        }
    }

    molecule.SetPosition(cur_position);
    molecule.SetVelocity(cur_velocity);  
}

/*============================================================================*/