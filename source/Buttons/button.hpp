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
        Button(const Button& other);
        
        virtual ~Button() = default;

        bool IsMouseOnButton(const Graphics::Mouse& mouse);

        virtual void Act() = 0;

        void Draw(Graphics::Window& window);

        void Pressed();
        void Released();
        void Hovered();
        void UnHovered();
    };

} // namespace GUI

#endif //MOLECULAR_REACTOR_BUTTONS_BUTTON_HPP