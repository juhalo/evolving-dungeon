#include "Textures.hpp"

namespace ED::Texture {
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
} // namespace ED::Texture
