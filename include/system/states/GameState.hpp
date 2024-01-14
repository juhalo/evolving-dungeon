#pragma once

#include <SFML/Graphics.hpp>

namespace ED::System {
/**
 * @brief Abstract class for state of the game
 *
 */
class GameState {
public:
    /**
     * @brief Handle user input events
     *
     * @return Pointer to new current state or nullptr if did not change
     */
    virtual GameState* handleEvent(const sf::Event&) = 0;

    /**
     * @brief Update the state
     *
     */
    virtual void update(sf::Time) = 0;

    /**
     * @brief Render the state
     *
     */
    virtual void render() = 0;

    /**
     * @brief Destroy the Game State object
     *
     */
    virtual ~GameState() = default;
};
};
