#include "button_manager.hpp"

using namespace Graphics;
using namespace GUI;
using namespace Math;

ButtonManager::ButtonManager() :
    buttons_array_()
{
}

ButtonManager::ButtonManager(const std::vector<Button*>& array) :
    buttons_array_(array)
{
}

ButtonManager::~ButtonManager()
{
    for (Button* button : buttons_array_)
    {
        delete button;
    }
}

void ButtonManager::AddNewButton(Button* button)
{
    buttons_array_.push_back(button);
}

void ButtonManager::DrawButtons(Window& window)
{
    for (Button* cur_button : buttons_array_)
    {
        cur_button->Draw(window);
    }
}

int ButtonManager::CheckMouse(Window& window, Mouse& mouse)
{
    Vector mouse_position = mouse.GetMouseCoords(window);

    for (int index = 0; index < buttons_array_.size(); ++index)
    {
        if (buttons_array_[index]->IsMouseOnButton(mouse_position)) return index;
    }

    return -1;
}

bool ButtonManager::ManageEvents(Window& window, const Event& event, Mouse& mouse)
{
    for (Button* button : buttons_array_)
    {
        button->UnHovered();
    }

    int button_index = CheckMouse(window, mouse);
    if (button_index == -1) return false;

    switch (event.type)
    {
    case EventType::MouseButtonPressed:
        buttons_array_[button_index]->Pressed();
        buttons_array_[button_index]->Act();
        return true;

    case EventType::MouseButtonReleased:
        buttons_array_[button_index]->Released();
        return true;


    case EventType::MouseMoved:
    case EventType::None:
        buttons_array_[button_index]->Hovered();
        return true;
    case EventType::WindowClosed:
    default:
        break;
    }

    return false;
}
