#include "Textures.hpp"

sf::Font ed::Textures::font;

bool ed::Textures::loadTextures()
{
    if (!font.loadFromFile("resources/fonts/PressStart2P.ttf")) {
        return false;
    }
    return true;
}
