#include "system/states/PausedState.hpp"

namespace ED::System {
PausedState::PausedState(sf::RenderWindow& window, const Fonts& fonts)
    : m_window(window)
    , m_background(sf::RectangleShape(sf::Vector2f(0, 0)))
{
    initializeUI(fonts);
}

void PausedState::update(sf::Time)
{ /* Do nothing */
}

void PausedState::render()
{
    m_playingState->render();
    m_window.draw(m_background);
    for (auto& element : m_UI)
        m_window.draw(element);
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
    case sf::Event::MouseButtonPressed:
        const sf::Vector2i& clickPosition = sf::Mouse::getPosition(m_window);
        auto isClickable = [=](Button i) { return i.clickButton(clickPosition); };
        auto it = std::find_if(m_UI.begin(), m_UI.end(), isClickable);
        if (it != m_UI.end()) {
            switch (it->type()) {
            case Constant::ButtonType::quitToDesktop:
                m_window.close();
                break;
            case Constant::ButtonType::quitToMenu:
                return m_menuState;
                break;
            case Constant::ButtonType::unpauseGame:
                return m_playingState;
                break;
            default: // Do nothing;
                break;
            }
        }
        break;
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

void PausedState::initializeUI(const Fonts& fonts)
{
    sf::Vector2u windowSize = m_window.getSize();
    float numOfElements = 3;
    unsigned y = windowSize.y;
    unsigned x = windowSize.x;
    float middleY = y / (2 * numOfElements);
    float middleX = x / 2;
    unsigned i = 0;

    m_UI.push_back(Button("Continue game", sf::Vector2f(middleX, (i++ / numOfElements) * y + middleY), sf::Color::White, sf::Color::Black, ED::Constant::ButtonType::unpauseGame, fonts));
    m_UI.push_back(Button("Main menu", sf::Vector2f(middleX, (i++ / numOfElements) * y + middleY), sf::Color::White, sf::Color::Black, ED::Constant::ButtonType::quitToMenu, fonts));
    m_UI.push_back(Button("Quit to desktop", sf::Vector2f(middleX, (i++ / numOfElements) * y + middleY), sf::Color::White, sf::Color::Black, ED::Constant::ButtonType::quitToDesktop, fonts));

    m_background.setFillColor(sf::Color((uint8_t)80, (uint8_t)80, (uint8_t)80, (uint8_t)160));
    m_background.setSize(sf::Vector2f(m_window.getSize().x, m_window.getSize().y));
}
};
