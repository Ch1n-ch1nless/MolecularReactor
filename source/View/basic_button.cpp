#include "basic_button.hpp"

View::BasicButton::BasicButton(std::size_t width, std::size_t height, const Math::Vector& position, const char* const * const textures_files) :
    AWindow   (),
    sprites_  {},
    position_ (position),
    width_    (width),
    height_   (height),
    state_    (ButtonStates::Normal)
{
    for (unsigned int i = 0; i < (unsigned int)ButtonStates::MaxNumberOfStates; ++i)
    {
        sprites_[i].LoadFromFile(textures_files[i]);
        sprites_[i].SetPosition(position_);
    }
}

View::BasicButton::BasicButton(std::size_t width, std::size_t height, const Math::Vector& position, const char* const texture_file) :
    AWindow   (),
    sprites_  {},
    position_ (position),
    width_    (width),
    height_   (height),
    state_    (ButtonStates::Normal)
{
    for (unsigned int i = 0; i < (unsigned int)ButtonStates::MaxNumberOfStates; ++i)
    {
        sprites_[i].LoadFromFile(texture_file);
        sprites_[i].SetPosition(position_);
    }
}

void View::BasicButton::Draw(Graphics::Window& window)
{
    window.Draw(sprites_[(unsigned int)state_]);
}

bool View::BasicButton::IsMouseOnButton(const Graphics::Mouse& mouse)
{
    double x0 = position_.GetX();
    double y0 = position_.GetY();

    double mouse_x = mouse.GetMouseCoords().GetX();
    double mouse_y = mouse.GetMouseCoords().GetY();

    return  (x0 <= mouse_x && mouse_x <= (x0 + (double)width_ )) &&
            (y0 <= mouse_y && mouse_y <= (y0 + (double)height_));
}

void View::BasicButton::Pressed()
{
    state_ = ButtonStates::Pressed;
}

void View::BasicButton::Released()
{
    state_ = ButtonStates::Released;
}

void View::BasicButton::Hovered()
{
    state_ = ButtonStates::Hovered;
}

void View::BasicButton::UnHovered()
{
    state_ = ButtonStates::Normal;
}