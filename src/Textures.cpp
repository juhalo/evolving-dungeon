#include "Textures.hpp"

namespace ed {
namespace Textures {
    sf::Font font;

    bool loadTextures()
    {
        if (!font.loadFromFile("resources/fonts/PressStart2P.ttf")) {
            return false;
        }
        return true;
    }
}
}
