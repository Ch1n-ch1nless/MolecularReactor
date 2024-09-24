#ifndef MOLECULAR_REACTOR_BUTTON_MOLECULE_BUTTON_HPP
#define MOLECULAR_REACTOR_BUTTON_MOLECULE_BUTTON_HPP

#include "button.hpp"
#include "button_pictures.hpp"
#include "../MathTools/molecular_manager.hpp"

namespace GUI
{
    class AddBlueCircleMoleculesButton : public Button
    {
    private:
        Math::MolecularManager* manager_ptr_;

    public:
        AddBlueCircleMoleculesButton(const Math::Vector& position, Math::MolecularManager* manager_ptr);
        
        ~AddBlueCircleMoleculesButton() = default;

        void Act();
    };

    class AddRedSquareMoleculesButton : public Button
    {
    private:
        Math::MolecularManager* manager_ptr_;

    public:
        AddRedSquareMoleculesButton(const Math::Vector& position, Math::MolecularManager* manager_ptr);
        
        ~AddRedSquareMoleculesButton() = default;

        void Act();
    };

} // namespace GUI

#endif //MOLECULAR_REACTOR_BUTTON_MOLECULE_BUTTON_HPP