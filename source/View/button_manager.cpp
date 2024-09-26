#include "button_manager.hpp"

View::ButtonManager::ButtonManager() :
    buttons_array_()
{
}

View::ButtonManager::ButtonManager(std::vector<BasicButton*>& src_array) :
    buttons_array_(src_array)
{
}

View::ButtonManager::~ButtonManager()
{
    for (View::BasicButton* button : buttons_array_)
    {
        delete button;
    }
}

void View::ButtonManager::AddButton(BasicButton* new_button)
{
    buttons_array_.push_back(new_button);
}

void View::ButtonManager::ManageEvents(Graphics::Event& event, Graphics::Mouse& mouse)
{
    for (View::BasicButton* button : buttons_array_)
    {
        if (button->IsMouseOnButton(mouse))
        {
            switch (event.type)
            {
            case Graphics::EventType::MouseButtonPressed:
                button->Pressed();
                button->Act();
                break;

            case Graphics::EventType::MouseButtonReleased:
                button->Released();
                break;

            case Graphics::EventType::MouseMoved:
            case Graphics::EventType::None:
                button->Hovered();
                break;
            
            case Graphics::EventType::WindowClosed:
            default:
                break;
            }
        }
        else
        {
            button->UnHovered();
        }
    }
}