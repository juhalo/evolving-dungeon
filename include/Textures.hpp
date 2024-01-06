#pragma once

#include <SFML/Graphics.hpp>

namespace ED {
namespace Textures {
    /**
     * @brief Font used
     *
     */
    extern sf::Font font;

    /**
     * @brief Load the textures for the game
     *
     * @return Whether or not the textures were loaded successfully
     */
    bool loadTextures();
}
}
