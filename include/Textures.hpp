#pragma once

#include <SFML/Graphics.hpp>

namespace ED {
namespace Texture {
    /**
     * @brief Font used
     *
     */
    extern std::shared_ptr<sf::Font> font;

    /**
     * @brief Load the textures for the game
     *
     * @return Whether or not the textures were loaded successfully
     */
    bool loadTextures();
} // namespace Texture
} // namespace ED
