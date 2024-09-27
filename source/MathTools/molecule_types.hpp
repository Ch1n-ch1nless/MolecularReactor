#ifndef MOLECULAR_REACTOR_MATH_TOOLS_MOLECULE_TYPES
#define MOLECULAR_REACTOR_MATH_TOOLS_MOLECULE_TYPES

namespace Math
{
    enum class MoleculeType : unsigned int
    {
        BlueCircle = 0,
        RedSquare  = 1,

        MaxNumberOfTypes
    };

    const char* const TEXTURE_FILES[(unsigned int)MoleculeType::MaxNumberOfTypes] = {
                                                                                     "pictures/blue_circle_16_16.png",
                                                                                     "pictures/red_square_16_16.png"
                                                                                    };
}

#endif