#pragma once

#include "Constants.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/**
 * @brief Handles the main menu
 *
 */
namespace ED::System {
class Menu {
public:
    /**
     * @brief Construct a new Menu object
     *
     */
    Menu();

    /**
     * @brief Destroy the Menu object
     *
     */
    ~Menu();

    /**
     * @brief Handle the main menu loop
     *
     */
    void menuLoop();

    /**
     * @brief Check if the window is open
     *
     * @return true If window is open,
     * @return false otherwise
     */
    bool isRunning() const;

private:
    /**
     * @brief The window object
     *
     */
    std::shared_ptr<sf::RenderWindow> m_window;

    /**
     * @brief Event for keyboard input, closing of window etc.
     *
     */
    sf::Event m_event;

    /**
     * @brief Holds the UI of the menu
     *
     */
    sf::CircleShape m_UI;

    /**
     * @brief Handle input events inside the menu
     *
     */
    void pollEvent();

    /**
     * @brief Draw menu's UI
     *
     */
    void drawUI();

    /**
     * @brief Render the menu screen
     *
     */
    void render();

    /**
     * @brief Initialize the UI of the menu screen
     *
     */
    void initializeUI();
};
} // namespace ED::System
