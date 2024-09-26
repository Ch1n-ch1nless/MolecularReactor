#include "window_manager.hpp"

View::WindowManager::WindowManager(std::size_t width, std::size_t height, const char* const window_name) :
    windows_array_(),
    graph_window_ (nullptr)
{
    graph_window_ = new Graphics::Window(width, height, window_name);
}

View::WindowManager::WindowManager(Graphics::Window* window) :
    windows_array_(),
    graph_window_ (window)
{
}

View::WindowManager::~WindowManager()
{
    for (AWindow* window : windows_array_)
    {
        delete window;
    }

    delete graph_window_;
}

void View::WindowManager::DrawWindows()
{
    for (AWindow* window : windows_array_)
    {
        window->Draw(*graph_window_);
    }
}

void View::WindowManager::AddWindow(View::AWindow* new_window)
{
    windows_array_.push_back(new_window);
}