#include "system/Button.hpp"

namespace ED {
namespace System {
    Button::Button(std::string text, sf::Vector2f position, sf::Color color, sf::Color fontColor, Constant::ButtonType type)
        : m_font(*Texture::font)
        , m_position(position)
        , m_type(type)
        , m_text(sf::Text(m_font, text, 38))
    {
        m_text.setOrigin(sf::Vector2f(m_text.getGlobalBounds().width / 2, m_text.getGlobalBounds().height / 2));
        m_text.setFillColor(fontColor);
        m_text.setOutlineColor(fontColor);

        m_size = sf::Vector2f(m_text.getGlobalBounds().width * 1.1f, m_text.getGlobalBounds().height * 2.0f);

        m_button.setSize(m_size);
        m_button.setOutlineThickness(3);
        m_button.setOutlineColor(fontColor);
        m_button.setFillColor(color);
        m_button.setOrigin(sf::Vector2f(m_button.getGlobalBounds().width / 2, m_button.getGlobalBounds().height / 2));
        m_button.setPosition(m_position);

        sf::Vector2f textPosition = sf::Vector2f(m_button.getPosition().x, m_button.getPosition().y);

        m_text.setPosition(textPosition);
    }

    Button::~Button() { }

    sf::Vector2f Button::position() const { return m_position; }

    void Button::setPosition(sf::Vector2f position)
    {
        m_position = position;
    }

    Constant::ButtonType Button::type() const { return m_type; }

    bool Button::clickButton(sf::Vector2i mousePosition) const
    {
        return (m_type != Constant::ButtonType::none) && (m_button.getGlobalBounds().contains(sf::Vector2f(mousePosition.x, mousePosition.y)));
    }

    void Button::draw(sf::RenderTarget& target, const sf::RenderStates& states) const
    {
        target.draw(m_button, states);
        target.draw(m_text, states);
    }
} // namespace System
} // namespace ED
