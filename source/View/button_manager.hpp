#ifndef MOLECULAR_REACTOR_VIEW_BUTTON_MANAGER_HPP
#define MOLECULAR_REACTOR_VIEW_BUTTON_MANAGER_HPP

#include "basic_button.hpp"
#include <vector.hpp>

namespace View
{
    class ButtonManager
    {
    private:
        std::vector<BasicButton*> buttons_array_;

    public:
         ButtonManager();
         ButtonManager(std::vector<BasicButton*>& src_array);
        ~ButtonManager();

        void ManageEvents(Graphics::Event& event, Graphics::Mouse& mouse);
    };
}

#endif //MOLECULAR_REACTOR_VIEW_BUTTON_MANAGER_HPP