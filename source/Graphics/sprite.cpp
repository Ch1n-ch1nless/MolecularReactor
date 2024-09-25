#include "sprite.hpp"

using namespace Graphics;
using namespace Math;

Sprite::Sprite() :
    texture_(),
    sprite_ ()
{
}

Sprite::~Sprite()
{
}

Sprite::Sprite(const Sprite& other) :
    texture_(other.texture_),
    sprite_ (other.sprite_)
{
}

Sprite& Sprite::operator =(const Sprite& sprite)
{
    texture_ = sprite.texture_;
    sprite_  = sprite.sprite_;
    return *this;
}

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