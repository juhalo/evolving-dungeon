#pragma once

#include "Constants.hpp"
#include "Resources.hpp"
#include "system/Button.hpp"
#include "system/states/GameState.hpp"
#include "system/states/MenuState.hpp"
#include "system/states/PlayingState.hpp"
#include <SFML/Graphics.hpp>

namespace ED::System {

class MenuState;
class PlayingState;

/**
 * @brief Class for the state of the game when playing the game (unpaused)
 *
 */
class PausedState : public GameState {
public:
    /**
     * @brief Construct a new Paused State object
     *
     * @param window Window of the state
     * @param fonts Fonts of the state
     */
    PausedState(sf::RenderWindow& window, const Fonts& fonts);

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
     * @brief Set the Playing State object
     *
     * @param playingState The new playing state object
     */
    void setPlayingState(PlayingState& playingState);

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
     * @brief Playing state of the game
     *
     */
    PlayingState* m_playingState;
};
};
