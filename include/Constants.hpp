#pragma once

#include <string>

/**
 * @brief Constants for the evolving dungeon game
 *
 */
namespace ED::Constant {
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
} // namespace ED::Constant
