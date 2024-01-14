#pragma once

#include "Constants.hpp"
#include "Resources.hpp"
#include "system/Button.hpp"
#include "system/states/MenuState.hpp"
// #include "system/states/PausedState.hpp"
#include "system/states/PlayingState.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <algorithm>

namespace ED::System {
class Game {
public:
    /**
     * @brief Construct a new Game object
     *
     */
    Game();

    /**
     * @brief Run the game loop
     *
     */
    void run();

private:
    /**
     * @brief Fonts used
     *
     */
    Fonts m_fonts;

    /**
     * @brief Texture used
     *
     */
    Textures m_textures;

    /**
     * @brief The window object
     *
     */
    sf::RenderWindow m_window;

    /**
     * @brief Menu of the game
     *
     */
    MenuState m_menuState;
    // PausedState m_pausedState;

    /**
     * @brief Ongoing game part of the game
     *
     */
    PlayingState m_playingState;

    /**
     * @brief Current state of the game
     *
     */
    GameState* m_currentState;

    /**
     * @brief Event for keyboard input, closing of window etc.
     *
     */
    sf::Event m_event;

    /**
     * @brief Load the resources used throughout the program
     *
     */
    void loadResources();

    /**
     * @brief Initialize the resources and return window's video mode
     *
     * @return Window's video mode
     */
    sf::VideoMode init();
};
};
