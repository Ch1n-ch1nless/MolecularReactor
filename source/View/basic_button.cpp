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

    return  (x0 <= mouse_x && mouse_x <= (x0 + width_ )) &&
            (y0 <= mouse_y && mouse_y <= (y0 + height_));
}

void View::BasicButton::UpdateButton(const Graphics::Event& event)
{
    switch (event.type)
    {
    case Graphics::EventType::MouseButtonPressed :
        state_ = ButtonStates::Pressed;
        break;

    case Graphics::EventType::MouseButtonReleased :
        state_ = ButtonStates::Released;
        break;

    case Graphics::EventType::MouseMoved:
    case Graphics::EventType::None:
        state_ = ButtonStates::Hovered;
        break;
    
    case Graphics::EventType::WindowClosed:
    default:
        break;
    }
}