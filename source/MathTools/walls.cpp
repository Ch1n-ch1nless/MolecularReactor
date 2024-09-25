#include "walls.hpp"

using namespace Math;

/*=============================< Wall functions >=============================*/

Wall::Wall(const Vector& top_left_corner, const Vector& low_right_corner, const Vector& normal) :
    top_left_corn_  (top_left_corner),
    low_right_corn_ (low_right_corner),
    normal_         (normal)
{
    normal_.Normalize();
}

Wall::Wall(const double x_begin, const double y_begin, const double x_end, const double y_end, const Vector& normal) :
    top_left_corn_  (x_begin, y_begin),
    low_right_corn_ (x_end, y_end),
    normal_         (normal)
{
    normal_.Normalize();
}

bool Wall::operator==(const Molecule& molecule) const
{
    Vector new_pos = molecule.pos_ - molecule.radius_ * normal_;

    if (top_left_corn_.GetX()  <= new_pos.GetX() && new_pos.GetX() <= low_right_corn_.GetX() &&
        low_right_corn_.GetY() <= new_pos.GetY() && new_pos.GetY() <= top_left_corn_.GetY()      )
    {
        return true;
    }

    return false;
}

void Wall::Collide(Molecule& molecule) const
{
    Vector projection_vec = (molecule.velocity_ * normal_) * normal_;
    molecule.velocity_ -= 2 * projection_vec;
}

/*============================================================================*/

/*=============================< Walls functions >============================*/

Walls::Walls(const Vector& top_left_corner, const Vector& low_right_corner) :
    array_{Wall(top_left_corner.GetX(),  top_left_corner.GetY(),  low_right_corner.GetX(), top_left_corner.GetY(),  { 0.0, -1.0}), 
           Wall(low_right_corner.GetX(), top_left_corner.GetY(),  low_right_corner.GetX(), low_right_corner.GetY(), {-1.0,  0.0}), 
           Wall(top_left_corner.GetX(),  low_right_corner.GetY(), low_right_corner.GetX(), low_right_corner.GetY(), { 0.0,  1.0}), 
           Wall(top_left_corner.GetX(),  top_left_corner.GetY(),  top_left_corner.GetX(),  low_right_corner.GetY(), { 1.0,  0.0})   
          },
    top_left_corn_(top_left_corner),
    width_        (low_right_corner.GetX() - top_left_corner.GetX() ),
    height_       (top_left_corner.GetY()  - low_right_corner.GetY())
{
}

Walls::Walls(const Vector& top_left_corner, const double width, const double height) :
    array_{Wall(top_left_corner.GetX(),         top_left_corner.GetY(),          top_left_corner.GetX() + width, top_left_corner.GetY(),          { 0.0, -1.0}), 
           Wall(top_left_corner.GetX() + width, top_left_corner.GetY(),          top_left_corner.GetX() + width, top_left_corner.GetY() + height, {-1.0,  0.0}), 
           Wall(top_left_corner.GetX(),         top_left_corner.GetY() + height, top_left_corner.GetX() + width, top_left_corner.GetY() + height, { 0.0,  1.0}), 
           Wall(top_left_corner.GetX(),         top_left_corner.GetY(),          top_left_corner.GetX(),         top_left_corner.GetY() + height, { 1.0,  0.0})   
          },
    top_left_corn_(top_left_corner),
    width_        (width ),
    height_       (height)
{
}

void Walls::CheckCollision(Molecule& molecule)
{
    for (int i = 0; i < 4; ++i)
    {
        if (array_[i] == molecule)
        {
            array_[i].Collide(molecule);
        }
    }
}

/*============================================================================*/