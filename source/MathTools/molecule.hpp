#ifndef MOLECULAR_REACTOR_MATH_MOLECULE_HPP
#define MOLECULAR_REACTOR_MATH_MOLECULE_HPP

#include "vector.hpp"
#include "../Graphics/window.hpp"

namespace Math
{
    enum class MoleculeType : unsigned int
    {
        BlueCircle = 0,
        RedSquare  = 1,

        MaxNumberOfTypes
    };

    const char* const BLUE_CIRCLE_IMAGE = "pictures/blue_circle_16_16.png";
    const char* const RED_SQUARE_IMAGE  = "pictures/red_square_16_16.png";

    class Molecule
    {
    protected:
        Vector              pos_;
        Vector              velocity_;
        double              radius_;
        double              massa_;
        MoleculeType        type_;
        Graphics::Sprite    sprite_;

    public:
        Molecule(const Vector& position, const MoleculeType type, const double radius, const double massa);
        Molecule(const Vector& position, const Vector& velocity, const MoleculeType type, const double radius, const double massa);

        virtual ~Molecule() = default;

        void Draw(Graphics::Window& window);

        void Move(double dt);

        MoleculeType GetType() const { return type_; }

        bool operator ==(const Molecule& other);

        friend void Collide(Molecule* molecule1, Molecule* molecule2);
        
        friend class Wall;
    };

    void Collide(Molecule* molecule1, Molecule* molecule2);

} // namespace Math

#endif //MOLECULAR_REACTOR_MATH_MOLECULE_HPP