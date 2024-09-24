#include "window.hpp"

using namespace Graphics;


Window::Window(std::size_t width, std::size_t height, const char* const window_name) :
    window_(sf::VideoMode(width, height), window_name),
    width_ (width),
    height_(height)
{
}

bool Window::IsOpen()
{
    return window_.isOpen();
}
void Window::Close()
{
    window_.close();
}

void Window::Clear()
{
    window_.clear(sf::Color::Black);
}

void Window::Display()
{
    window_.display();
}

bool Window::PollEvent(Event& event)
{
    sf::Event secret_event  = event.event_;
    bool result             = window_.pollEvent(secret_event);

    if (!result) return result;

    if (secret_event.type == sf::Event::Closed)
    {
        event.type_ = EventType::WindowClosed;
    }
    else if (secret_event.type == sf::Event::MouseMoved)
    {
        event.type_ = EventType::MouseMoved;
    }
    else if (secret_event.type == sf::Event::MouseButtonPressed)
    {
        event.type_ = EventType::MouseButtonPressed;
    }
    else if (secret_event.type == sf::Event::MouseButtonReleased)
    {
        event.type_ = EventType::MouseButtonReleased;
    }
    else
    {
        event.type_ = EventType::None;
    }

    return result;
}

void Window::Draw(const Sprite& sprite)
{
    window_.draw(sprite.sprite_);
}