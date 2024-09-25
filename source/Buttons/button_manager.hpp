#ifndef MOLECULAR_REACTOR_GUI_BUTTON_MANAGER_HPP
#define MOLECULAR_REACTOR_GUI_BUTTON_MANAGER_HPP

#include "button.hpp"
#include <vector>

namespace GUI
{
    class ButtonManager
    {
    private:
        std::vector<Button*> buttons_array_;

    public:
        ButtonManager();
        ButtonManager(const std::vector<Button*>& array);
        ~ButtonManager();

        void AddNewButton(Button* button);

        void DrawButtons(Graphics::Window& window);

        bool ManageEvents(Graphics::Window& window, 
                          Graphics::Event&  event, 
                          Graphics::Mouse& mouse     );

        int  CheckMouse( Graphics::Window& window, 
                         Graphics::Mouse& mouse    );
    };

} // namespace GUI

#endif //MOLECULAR_REACTOR_GUI_BUTTON_MANAGER_HPP