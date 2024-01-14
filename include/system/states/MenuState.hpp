#pragma once

// #include "../Menu.hpp"
// #include "GameState.hpp"
#include "Constants.hpp"
#include "Resources.hpp"
#include "system/Button.hpp"
#include "system/states/GameState.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>

namespace ED::System {
/**
 * @brief Class for the state of the game when inside menu
 *
 */
class MenuState : public GameState {
public:
    /**
     * @brief Construct a new Menu State object
     *
     * @param window Window of the state
     * @param fonts Fonts of the state
     */
    MenuState(sf::RenderWindow& window, const Fonts& fonts);

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

    /**
     * @brief Holds the UI of the menu
     *
     */
    std::vector<Button> m_UI;

    /**
     * @brief Initialize the UI of the menu screen
     *
     */
    void initializeUI(const Fonts& fonts);
};
};
