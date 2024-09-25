#include "button.hpp"

using namespace Graphics;
using namespace GUI;
using namespace Math;

 Button::Button(const Math::Vector& position, double width, double height, char const * const * const file_names) :
    top_left_corner_(position),
    width_          (width),
    height_         (height),
    state_          (State::Normal),
    sprites_        ()
{
    for (unsigned int i = 0; i < (unsigned int)State::MaxNumberOfStates; ++i)
    {
        if (!(sprites_[i].LoadFromFile(file_names[i]))) fprintf(stderr, "ERROR!!! Button can not load the image!\n");
        sprites_[i].SetPosition(top_left_corner_);
    }
}

bool Button::IsMouseOnButton(const Graphics::Mouse& mouse)
{
    double x0 = top_left_corner_.GetX();
    double y0 = top_left_corner_.GetY();

    double mouse_x = mouse.GetMouseCoords().GetX();
    double mouse_y = mouse.GetMouseCoords().GetY();

    return  (x0 <= mouse_x && mouse_x <= (x0 + width_ )) &&
            (y0 <= mouse_y && mouse_y <= (y0 + height_));
}

void Button::Draw(Graphics::Window& window)
{
    window.Draw(sprites_[(unsigned int)state_]);
}

void Button::Pressed()   
{
    state_ = State::Pressed;  
}

void Button::Released()   
{
    state_ = State::Released;  
}

void Button::Hovered()   
{
    state_ = State::Hovered;  
}

void Button::UnHovered()   
{
    state_ = State::Normal;
}