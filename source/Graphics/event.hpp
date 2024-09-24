#ifndef MOLECULAR_REACTOR_GRAPHICS_EVENT_HPP
#define MOLECULAR_REACTOR_GRAPHICS_EVENT_HPP

#include <SFML/Graphics.hpp>

namespace Graphics
{
    enum class EventType
    {
        None,
        WindowClosed,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
    };

    class Event
    {
    private:
        sf::Event event_;

    public:
        EventType type;

        Event() :
            event_(),
            type(EventType::None)
        {
        }

        Event(EventType event_type) :
            event_(),
            type(event_type)
        {
        }
        
        ~Event() = default;

        friend class Window;
    };
} // namespace Graphics

#endif //MOLECULAR_REACTOR_GRAPHICS_EVENT_HPP