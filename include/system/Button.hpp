#pragma once

#include "Constants.hpp"
#include "Textures.hpp"
#include <SFML/Graphics.hpp>

namespace ED {
namespace System {
    class Button : public sf::Drawable {
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
        Button(std::string text, sf::Vector2f position, sf::Color color, sf::Color fontColor, Constant::ButtonType type);

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

        /**
         * @brief Get the position of the button
         *
         * @return Current position of the button
         */
        sf::Vector2f position() const;

        /**
         * @brief Set the position of the button
         *
         * @param position The new position of the button
         */
        void setPosition(sf::Vector2f);

        /**
         * @brief Get the type of the button
         *
         * @return Type of the button
         */
        Constant::ButtonType type() const;

        /**
         * @brief
         *
         * @param mousePosition Position of the mouse
         * @return Whether mouse is over a clickable button or not
         */
        bool clickButton(sf::Vector2i mousePosition) const;

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
        sf::Vector2f m_position;

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

        /**
         * @brief Draws the Button to target, provided by class sf::Drawable
         *
         * @param target The render object, i.e. window
         * @param states States used for drawing to the target
         */
        void draw(sf::RenderTarget& target, const sf::RenderStates& states) const final;
    };
} // namespace System
} // namespace ED
