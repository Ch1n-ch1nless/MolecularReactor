#ifndef MOLECULAR_REACTOR_BUTTONS_BUTTON_HPP
#define MOLECULAR_REACTOR_BUTTONS_BUTTON_HPP

#include "../Graphics/mouse.hpp"
#include "../Graphics/window.hpp"
#include "../MathTools/vector.hpp"

#include <cstdio>

namespace GUI
{
    enum class State : unsigned int
    {
        Normal,
        Hovered,
        Pressed,
        Released,

        MaxNumberOfStates       //constant to control number of states
    };

    class Button
    {
    protected:
        Math::Vector     top_left_corner_;
        double           width_;
        double           height_;
        State            state_;
        Graphics::Sprite sprites_[(unsigned int)State::MaxNumberOfStates];

    public:
        Button(const Math::Vector& position, double width, double height, char const * const * const file_names);
        
        virtual ~Button() = default;

        bool IsMouseOnButton(const Graphics::Mouse& mouse);

        virtual void Act() = 0;

        void Draw(Graphics::Window& window)
        {
            window.Draw(sprites_[(unsigned int)state_]);
        }

        void Pressed()   { state_ = State::Pressed;  }
        void Released()  { state_ = State::Released; }
        void Hovered()   { state_ = State::Hovered;  }
        void UnHovered() { state_ = State::Normal;   }
    };

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

} // namespace GUI

#endif //MOLECULAR_REACTOR_BUTTONS_BUTTON_HPP