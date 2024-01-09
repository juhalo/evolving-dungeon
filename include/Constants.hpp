#pragma once

#include <string>

namespace ED {
/**
 * @brief Constants for the evolving dungeon game
 *
 */
namespace Constant {
    /**
     * @brief Height of the window
     *
     */
    static unsigned windowHeight = 1000;

    /**
     * @brief Width of the window
     *
     */
    static unsigned windowWidth = 1000;

    /**
     * @brief Frame rate of the window
     *
     */
    static unsigned frameRate = 60;

    /**
     * @brief Name of the game
     *
     */
    static std::string gameName = "Evolving Dungeon";

    /**
     * @brief Types of buttons
     *
     */
    enum class ButtonType {
        none,
        startGame,
        unpauseGame,
        quitToMenu,
        quitToDesktop,
    };
} // namespace Constant
namespace Texture {
    enum class ID {
        enemy,
        player,
        tiles,
        weapon,
        item,
    };
} // namespace Texture
namespace Font {
    enum class ID {
        normal,
    };
} // namespace Font
namespace Sound {
    enum class ID {}; // FIXME: Should have id's for different possible sounds
} // namespace Sound
} // namespace ED

// Forward declarations
template <typename Resource, typename ID>
class Resources;

namespace sf {
class Texture;
class Font;
class Sound;
} // namespace sf

typedef Resources<sf::Texture, ED::Texture::ID> Textures;
typedef Resources<sf::Font, ED::Font::ID> Fonts;
typedef Resources<sf::Sound, ED::Sound::ID> Sounds;
