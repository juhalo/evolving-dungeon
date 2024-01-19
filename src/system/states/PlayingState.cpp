#include "system/states/PlayingState.hpp"

namespace ED::System {
PlayingState::PlayingState(sf::RenderWindow& window, const Fonts& fonts, const Textures& textures)
    : m_window(window)
    , m_level(Level(fonts, textures, sf::Vector2u(ED::Constant::tileMapWidth, ED::Constant::tileMapHeight)))
{
}

void PlayingState::update(sf::Time)
{ /* Do nothing */
}

void PlayingState::render()
{
    m_window.draw(m_level.tileMap());
}

GameState* PlayingState::handleEvent(const sf::Event& event)
{
    switch (event.type) {
    case sf::Event::Closed:
        m_window.close();
        break;
    case sf::Event::KeyPressed:
        if (event.key.code == sf::Keyboard::Key::Delete) {
            m_window.close();
            break;
        }
        if (event.key.code == sf::Keyboard::Key::Escape) {
            return m_pausedState;
            break;
        }
    }
    return nullptr; // no transition (currently)
}

void PlayingState::setMenuState(MenuState& menuState)
{
    m_menuState = &menuState;
}

void PlayingState::setPausedState(PausedState& pausedState)
{
    m_pausedState = &pausedState;
}
};
