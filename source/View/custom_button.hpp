#ifndef MOLECULAR_REACTOR_VIEW_CUSTOM_BUTTONS_HPP
#define MOLECULAR_REACTOR_VIEW_CUSTOM_BUTTONS_HPP

#include "button_pictures.hpp"
#include "basic_button.hpp"
#include "../MathTools/custom_molecules.hpp"
#include "../MathTools/molecular_manager.hpp"

namespace View
{
    class AddBlueCircleButton : public BasicButton
    {
    private:
        Math::MolecularManager* manager_ptr_;

    public:
         AddBlueCircleButton(Math::MolecularManager* manager_ptr, const Math::Vector& top_left_corner);
        ~AddBlueCircleButton();

        void Act() override;
    };

    class AddRedSquareButton : public BasicButton
    {
    private:
        Math::MolecularManager* manager_ptr_;

    public:
         AddRedSquareButton(Math::MolecularManager* manager_ptr, const Math::Vector& top_left_corner);
        ~AddRedSquareButton();

        void Act() override;
    };
}

#endif //MOLECULAR_REACTOR_VIEW_CUSTOM_BUTTONS_HPP