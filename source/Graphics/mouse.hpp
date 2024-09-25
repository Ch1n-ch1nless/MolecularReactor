#ifndef MOLECULAR_REACTOR_GRAPHICS_HPP
#define MOLECULAR_REACTOR_GRAPHICS_HPP

#include "window.hpp"
#include "../MathTools/vector.hpp"

namespace Graphics
{
    class Mouse
    {
    private:
        sf::Mouse    mouse_;
        Math::Vector pos_;
    
    public:
        Mouse();
        Mouse(const Math::Vector& position);
        ~Mouse() = default;

        Math::Vector GetMouseCoords(Window& window);
        Math::Vector GetMouseCoords() const;
    };
    
} // namespace Graphics

#endif //MOLECULAR_REACTOR_GRAPHICS_MOUSE_HPP