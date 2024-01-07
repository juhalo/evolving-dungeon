#pragma once

#include "Constants.hpp"
#include "Textures.hpp"
#include <SFML/Graphics.hpp>

namespace ED {
namespace System {
    class Button : sf::Drawable {
    public:
        /**
         * @brief Construct a new Button object (button is also used for non-clickable objects)
         *
         * @param text Text inside the button
         * @param pos Position of the button
         * @param color Color of the button
         * @param fontColor Color of the font
         * @param type Type of the button, e.g. is the button clickable or not
         */
        Button(std::string text, sf::Vector2f pos, sf::Color color, sf::Color fontColor, Constant::ButtonType type);

        /**
         * @brief Construct a new Button object (button is also used for non-clickable objects)
         *
         */
        Button() = default;

        /**
         * @brief Destroy the Button object
         *
         */
        ~Button();

    private:
        /**
         * @brief Text of the button
         *
         */
        sf::Text m_text;

        /**
         * @brief Font of the text
         *
         */
        sf::Font m_font;

        /**
         * @brief Position of the button
         *
         */
        sf::Vector2f m_pos;

        /**
         * @brief Size of the button
         *
         */
        sf::Vector2f m_size;

        /**
         * @brief Shape of the button
         *
         */
        sf::RectangleShape m_button;

        /**
         * @brief Type of the button
         *
         */
        Constant::ButtonType m_type;
    };
} // namespace System
} // namespace ED
