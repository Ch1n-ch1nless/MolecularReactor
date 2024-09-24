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
        EventType type_;

    public:
        Event() :
            event_(),
            type_(EventType::None)
        {
        }

        Event(EventType type) :
            event_(),
            type_(type)
        {
        }
        
        ~Event() = default;

        friend class Window;
    };
} // namespace Graphics

#endif //MOLECULAR_REACTOR_GRAPHICS_EVENT_HPP