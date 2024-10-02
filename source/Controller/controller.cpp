#include "controller.hpp"

using namespace Control;

Controller::Controller( View::WindowManager*         window_manager,
                        View::ButtonManager*         button_manager,
                        Math::MolecularManager*      molecular_manager,
                        const char* const * const    molecule_textures) :
    window_manager_     (window_manager),
    button_manager_     (button_manager),
    molecular_manager_  (molecular_manager)
{
    flask_window_ = new View::FlaskWindow(molecular_manager->GetUpdatedMoleculeData(), molecule_textures);
    window_manager_->AddWindow(flask_window_);
}
    
Controller::~Controller()
{
    window_manager_     = nullptr;
    button_manager_     = nullptr;
    molecular_manager_  = nullptr;
    flask_window_       = nullptr;
}

void Controller::AddNewButton(View::BasicButton* button_ptr)
{
    button_manager_->AddButton(button_ptr);
    window_manager_->AddWindow(dynamic_cast<View::AWindow*>(button_ptr));
}

void Controller::ManageEvents(Graphics::Event& event, Graphics::Mouse& mouse)
{
    button_manager_->ManageEvents(event, mouse);
}

void Controller::LaunchPhysicalEngine(Math::Walls& walls)
{
    molecular_manager_->LaunchPhysicalEngine(walls);
    flask_window_->UpdateData(molecular_manager_->GetUpdatedMoleculeData());
}

void Controller::DrawWindows()
{
    window_manager_->DrawWindows();
}