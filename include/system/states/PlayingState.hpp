#pragma once

#include "Constants.hpp"
#include "Resources.hpp"
#include "system/Button.hpp"
#include "system/states/GameState.hpp"
#include "system/states/MenuState.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>

namespace ED::System {

class MenuState;

/**
 * @brief Class for the state of the game when playing the game (unpaused)
 *
 */
class PlayingState : public GameState {
public:
    /**
     * @brief Construct a new Playing State object
     *
     * @param window Window of the state
     * @param fonts Fonts of the state
     * @param textures Texture of the state
     */
    PlayingState(sf::RenderWindow& window, const Fonts& fonts, const Textures& textures);

    /**
     * @brief Handle user input events
     *
     * @return Pointer to new current state or nullptr if did not change
     */
    GameState* handleEvent(const sf::Event&) final;

    /**
     * @brief Update the state
     *
     */
    void update(sf::Time) final;

    /**
     * @brief Render the state
     *
     */
    void render() final;

private:
    /**
     * @brief The window object
     *
     */
    sf::RenderWindow& m_window;
};
};
