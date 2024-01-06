#include "Textures.hpp"

namespace ED {
namespace Texture {
    std::shared_ptr<sf::Font> font;

    bool loadTextures()
    {
        sf::Font temp;
        if (!temp.loadFromFile("resources/fonts/PressStart2P.ttf")) {
            return false;
        }
        font = std::make_shared<sf::Font>(temp);
        return true;
    }
} // namespace Texture
} // namespace ED
