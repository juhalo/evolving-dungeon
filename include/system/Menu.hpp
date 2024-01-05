#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/**
 * @brief Handles the main menu
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
};
