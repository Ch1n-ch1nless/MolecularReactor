#include "mouse.hpp"

using namespace Graphics;
using namespace Math;

Mouse::Mouse() :
    mouse_(),
    pos_  ()
{
}

Mouse::Mouse(const Vector& position) :
    mouse_(),
    pos_  (position)
{
}

Vector Mouse::GetMouseCoords(Window& window)
{
    sf::Vector2i sf_mouse_pos = mouse_.getPosition(window.window_);
    return Vector((double)sf_mouse_pos.x, (double)sf_mouse_pos.y);
}

Vector Mouse::GetMouseCoords() const
{
    return pos_;
}