#include "molecular_reactor.hpp"

int main()
{
    srand((unsigned int)time(NULL));

    Graphics::Window window(1200, 720, "Molecular reactor");
    Graphics::Mouse  mouse = {};

    Math::Walls walls({200.0, 200.0}, {600.0, 600.0});

    View::WindowManager     window_manager(&window);
    Math::MolecularManager  gas_model({400.0, 400.0});
    View::ButtonManager     button_manager = {};

    Control::Controller     model_controller(&window_manager, &button_manager, &gas_model, Math::TEXTURE_FILES);

    View::AddBlueCircleButton*      add_blue_button     = new View::AddBlueCircleButton(&gas_model, {900, 100});
    View::AddRedSquareButton*       add_red_button      = new View::AddRedSquareButton(&gas_model, {1000, 100});
    View::DeleteBlueCircleButton*   delete_blue_button  = new View::DeleteBlueCircleButton(&gas_model, {900, 200});
    View::DeleteRedSquareButton*    delete_red_button   = new View::DeleteRedSquareButton(&gas_model, {1000, 200});

    model_controller.AddNewButton(add_blue_button);
    model_controller.AddNewButton(add_red_button);
    model_controller.AddNewButton(delete_blue_button);
    model_controller.AddNewButton(delete_red_button);

    while (window.IsOpen())
    {
        mouse.UpdateCoords(window);

        Graphics::Event event;

        while (window.PollEvent(event))
        {
            if (event.type == Graphics::EventType::WindowClosed)
            {
                window.Close();
                break;
            }
        }

        model_controller.ManageEvents(event, mouse);

        model_controller.LaunchPhysicalEngine(walls);

        model_controller.DrawWindows();

        window.Display();
        window.Clear();
    }
    
    
    return 0;
}