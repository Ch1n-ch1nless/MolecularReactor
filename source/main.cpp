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

    View::AddBlueCircleButton* blue_button = new View::AddBlueCircleButton(&gas_model, {900, 100});
    View::AddRedSquareButton*  red_button  = new View::AddRedSquareButton(&gas_model, {1000, 100});

    button_manager.AddButton(blue_button);
    button_manager.AddButton(red_button);

    window_manager.AddWindow(blue_button);
    window_manager.AddWindow(red_button);

    View::FlaskWindow* flask_window = new View::FlaskWindow(gas_model.GetUpdatedMoleculeData(), Math::TEXTURE_FILES);
    window_manager.AddWindow(flask_window);

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

        button_manager.ManageEvents(event, mouse);

        gas_model.LaunchPhysicalEngine(walls);
        flask_window->UpdateData(gas_model.GetUpdatedMoleculeData());

        window_manager.DrawWindows();

        window.Display();
        window.Clear();
    }
    
    
    return 0;
}