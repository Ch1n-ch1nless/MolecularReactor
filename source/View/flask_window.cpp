#include "flask_window.hpp"

View::FlaskWindow::FlaskWindow(const std::vector<Math::Molecule*>* data, const char* const * const molecule_textures) :
    data_      (data),
    sprites_   {}
{
    for (unsigned int i = 0; i < (unsigned int)Math::MoleculeType::MaxNumberOfTypes; ++i)
    {
        sprites_[i].LoadFromFile(molecule_textures[i]);
    }
}

View::FlaskWindow::~FlaskWindow()
{
}

void View::FlaskWindow::Draw(Graphics::Window& window)
{
    for (Math::Molecule* molecule_ptr : *data_)
    {
        sprites_[(unsigned int)molecule_ptr->GetType()].SetPosition(molecule_ptr->GetPosition());
        window.Draw(sprites_[(unsigned int)molecule_ptr->GetType()]);
    }
}

void View::FlaskWindow::UpdateData(const std::vector<Math::Molecule*>* new_data)
{
    data_ = new_data;
}