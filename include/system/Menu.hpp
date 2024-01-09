#pragma once

#include "Constants.hpp"
#include "Resources.hpp"
#include "system/Button.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <algorithm>

namespace ED::System {
/**
 * @brief Class for handling the main menu
 *
 */
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
    std::vector<Button> m_UI;

    /**
     * @brief Fonts used
     *
     */
    Fonts m_fonts;

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

    /**
     * @brief Load the resources used throughout the program
     *
     */
    void loadResources();
};
} // namespace ED::System
