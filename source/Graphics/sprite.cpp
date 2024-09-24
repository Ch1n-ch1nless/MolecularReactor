#include "sprite.hpp"

using namespace Graphics;
using namespace Math;

bool Sprite::LoadFromFile(const char* const filename)
{
    if (texture_.loadFromFile(filename))
    {
        sprite_.setTexture(texture_);
        return true;
    }

    return false;
}

void Sprite::SetPosition(const Math::Vector& top_left_corner)
{
    sprite_.setPosition((float)top_left_corner.GetX(), (float)top_left_corner.GetY());
}