#ifndef MOLECULAR_REACTOR_CONTROLLER_CONTROLLER_HPP
#define MOLECULAR_REACTOR_CONTROLLER_CONTROLLER_HPP

#include "../View/window_manager.hpp"
#include "../View/button_manager.hpp"
#include "../View/flask_window.hpp"
#include "../MathTools/molecular_manager.hpp"

namespace Control
{
    class Controller
    {
    private:
        View::WindowManager*    window_manager_     = nullptr;
        View::ButtonManager*    button_manager_     = nullptr;
        Math::MolecularManager* molecular_manager_  = nullptr;
        View::FlaskWindow*      flask_window_       = nullptr;

    public:
        Controller(View::WindowManager*         window_manager,
                   View::ButtonManager*         button_manager,
                   Math::MolecularManager*      molecular_manager,
                   const char* const * const    molecule_textures);
        ~Controller();

        void AddNewButton        (View::BasicButton* button_ptr);
        void ManageEvents        (Graphics::Event& event, Graphics::Mouse& mouse);
        void LaunchPhysicalEngine(Math::Walls& walls);
        void DrawWindows         ();
    };
    
}

#endif