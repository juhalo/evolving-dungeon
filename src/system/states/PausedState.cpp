#include "system/states/PausedState.hpp"

namespace ED::System {
PausedState::PausedState(sf::RenderWindow& window, const Fonts& fonts)
    : m_window(window)
{
}

void PausedState::update(sf::Time)
{ /* Do nothing */
}

void PausedState::render()
{
    m_playingState->render();
    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Yellow);
    m_window.draw(shape);
}

GameState* PausedState::handleEvent(const sf::Event& event)
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
            return m_menuState;
            break;
        }
        if (event.key.code == sf::Keyboard::Key::Space) {
            return m_playingState;
            break;
        }
    }
    return nullptr; // no transition (currently)
}

void PausedState::setMenuState(MenuState& menuState)
{
    m_menuState = &menuState;
}

void PausedState::setPlayingState(PlayingState& playingState)
{
    m_playingState = &playingState;
}
};
