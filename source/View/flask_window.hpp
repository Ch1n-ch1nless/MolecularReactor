#ifndef MOLECULAR_REACTOR_VIEW_FLASK_WINDOW_HPP
#define MOLECULAR_REACTOR_VIEW_FLASK_WINDOW_HPP

#include "abstract_window.hpp"
#include "../MathTools/molecule.hpp"

namespace View
{   
    class FlaskWindow : public AWindow
    {
    private:
        const std::vector<Math::Molecule*>*  data_;
        Graphics::Sprite                    sprites_[(unsigned int)Math::MoleculeType::MaxNumberOfTypes];
        Graphics::Sprite                    background_;

    public:
         FlaskWindow(const std::vector<Math::Molecule*>* molecules_array, const char* const * const molecule_textures, const char* const background);
        ~FlaskWindow();

        void Draw(Graphics::Window& window);

        void UpdateData(const std::vector<Math::Molecule*>* new_data);
    };
};

#endif