#ifndef MOLECULAR_REACTOR_VIEW_ABSTRACT_WINDOW_HPP
#define MOLECULAR_REACTOR_VIEW_ABSTRACT_WINDOW_HPP

#include "../Graphics/Graphics.hpp"

namespace View
{
    class AWindow
    {
    public:
                 AWindow() = default;
        virtual ~AWindow() = default;

        virtual void Draw(Graphics::Window& window) = 0;
    };
};

#endif //MOLECULAR_REACTOR_VIEW_ABSTRACT_WINDOW_HPP