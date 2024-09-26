#ifndef MOLECULAR_REACTOR_VIEW_BASIC_BUTTON_HPP
#define MOLECULAR_REACTOR_VIEW_BASIC_BUTTON_HPP

#include "abstract_window.hpp"

namespace View
{
    enum class ButtonStates : unsigned int
    {
        Normal   = 0,
        Hovered  = 1,
        Pressed  = 2,
        Released = 3,

        MaxNumberOfStates       //<- constant to regulate max number of button states
    };

    class BasicButton : public AWindow
    {
    private:
        Graphics::Sprite    sprites_[(unsigned int)ButtonStates::MaxNumberOfStates];
        Math::Vector        position_;
        std::size_t         width_;
        std::size_t         height_;
        ButtonStates        state_;

    public:
         BasicButton(std::size_t width, std::size_t height, const Math::Vector& position, const char* const * const textures_files);
         BasicButton(std::size_t width, std::size_t height, const Math::Vector& position, const char* const texture_file);
        ~BasicButton() = default;

        virtual void Act() = 0;

        void Draw(Graphics::Window& window);

        bool IsMouseOnButton(const Graphics::Mouse& mouse);

        void Pressed  ();
        void Released ();
        void Hovered  ();
        void UnHovered();
    };
}

#endif //MOLECULAR_REACTOR_VIEW_BASIC_BUTTON_HPP