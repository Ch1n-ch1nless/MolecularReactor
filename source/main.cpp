#include "MathTools/molecular_manager.hpp"
#include "MathTools/walls.hpp"
#include "Graphics/window.hpp"
#include "Graphics/mouse.hpp"
#include "Buttons/button_manager.hpp"
#include "Buttons/molecule_buttons.hpp"

int main()
{
    srand((unsigned int)time(NULL));

    Graphics::Window window(1200, 800, "Molecular reactor");
    Graphics::Event  event = {};
    Graphics::Mouse  mouse = {};

    Math::MolecularManager gas_model({400.0, 400.0});

    Math::Walls walls({200.0, 200.0}, 400.0, 400.0);

    GUI::ButtonManager button_manager;

    GUI::AddBlueCircleMoleculesButton* blue_plus_button = new GUI::AddBlueCircleMoleculesButton({900, 200}, &gas_model);
    GUI::AddRedSquareMoleculesButton*  red_plus_button  = new GUI::AddRedSquareMoleculesButton({1100, 200}, &gas_model);

    button_manager.AddNewButton(blue_plus_button);
    button_manager.AddNewButton(red_plus_button);

    while (window.IsOpen())
    {
        while (window.PollEvent(event))
        {
            if (event.type == Graphics::EventType::WindowClosed)
            {
                window.Close();
                return 0;
            }
        }

        button_manager.ManageEvents(window, event, mouse);
        button_manager.DrawButtons(window);
        
        gas_model.MoveMolecules();
        gas_model.CollideMolecules(walls);
        gas_model.CollideMolecules();
        gas_model.DrawMolecules(window);

        window.Display();

        window.Clear();

        //sf::sleep(sf::seconds(0.3f));
    }
    
    
    return 0;
}