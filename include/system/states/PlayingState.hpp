#pragma once

#include "Constants.hpp"
#include "Resources.hpp"
#include "system/Button.hpp"
#include "system/Level.hpp"
#include "system/states/GameState.hpp"
#include "system/states/MenuState.hpp"
#include "system/states/PausedState.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>

namespace ED::System {

class MenuState;
class PausedState;

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

    /**
     * @brief Set the Menu State object
     *
     * @param menuState The new menu state object
     */
    void setMenuState(MenuState& menuState);

    /**
     * @brief Set the Paused State object
     *
     * @param pausedState The new paused state object
     */
    void setPausedState(PausedState& pausedState);

private:
    /**
     * @brief The window object
     *
     */
    sf::RenderWindow& m_window;

    /**
     * @brief Menu state of the game
     *
     */
    MenuState* m_menuState;

    /**
     * @brief Paused state of the game
     *
     */
    PausedState* m_pausedState;

    /**
     * @brief Current level of the game
     *
     */
    Level m_level;
};
};
