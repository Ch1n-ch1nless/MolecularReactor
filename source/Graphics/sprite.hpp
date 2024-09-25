#ifndef MOLECULAR_REACTOR_GRAPHICS_SPRITE_HPP
#define MOLECULAR_REACTOR_GRAPHICS_SPRITE_HPP

#include <SFML/Graphics.hpp>
#include "../MathTools/vector.hpp"

namespace Graphics
{
    class Sprite
    {
    private:
        sf::Texture texture_;
        sf::Sprite  sprite_;

    public:
        Sprite();
        ~Sprite();

        Sprite(const Sprite& other);

        Sprite& operator =(const Sprite& sprite);

        bool LoadFromFile(const char* const filename);
        void SetPosition(const Math::Vector& top_left_corner);

        friend class Window;
    };
} // namespace Graphics

#endif //MOLECULAR_REACTOR_GRAPHICS_SPRITE_HPP