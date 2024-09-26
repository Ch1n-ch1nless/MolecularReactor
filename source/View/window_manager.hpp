#ifndef MOLECULAR_REACTOR_VIEW_WINDOW_HPP
#define MOLECULAR_REACTOR_VIEW_WINDOW_HPP

#include "abstract_window.hpp"
#include <vector>

namespace View
{
    class WindowManager
    {
    private:
        std::vector<AWindow*>   windows_array_;
        Graphics::Window*       graph_window_;

    public:
         WindowManager(std::size_t width, std::size_t height, const char* const global_window_name);
         WindowManager(Graphics::Window* const graph_window);
        ~WindowManager();

        void DrawWindows();

        void AddWindow   (AWindow* new_window);
    };
}

#endif //MOLECULAR_REACTOR_VIEW_WINDOW_HPP