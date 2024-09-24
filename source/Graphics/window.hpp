#ifndef MOLECULAR_REACTOR_GRAPHICS_WINDOW_HPP
#define MOLECULAR_REACTOR_GRAPHICS_WINDOW_HPP

#include <SFML/Graphics.hpp>
#include "event.hpp"
#include "sprite.hpp"

namespace Graphics
{
    class Window
    {
    private:
        sf::RenderWindow window_;
        std::size_t      width_;
        std::size_t      height_;
    
    public:
        Window(std::size_t width, std::size_t height, const char* const window_name);
        ~Window() = default;

        bool IsOpen();
        void Close();
        void Clear();
        void Display();

        bool PollEvent(Event& event);
        void Draw(const Sprite& sprite);

        friend class Mouse;
    };
    
} // namespace Graphics

#endif