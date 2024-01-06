#include "Textures.hpp"

namespace ED {
namespace Texture {
    sf::Font font;

    bool loadTextures()
    {
        if (!font.loadFromFile("resources/fonts/PressStart2P.ttf")) {
            return false;
        }
        return true;
    }
} // namespace Texture
} // namespace ED
