#include "system/states/MenuState.hpp"

namespace ED::System {
MenuState::MenuState(sf::RenderWindow& window, const Fonts& fonts)
    : m_window(window)
{
    initializeUI(fonts);
}

void MenuState::update(sf::Time)
{ /* Do nothing */
}

void MenuState::render()
{
    m_window.clear();
    for (auto& element : m_UI)
        m_window.draw(element);
    m_window.display();
}

GameState* MenuState::handleEvent(const sf::Event& event)
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
    case sf::Event::MouseButtonPressed:
        const sf::Vector2i& clickPosition = sf::Mouse::getPosition(m_window);
        auto isClickable = [=](Button i) { return i.clickButton(clickPosition); };
        auto it = std::find_if(m_UI.begin(), m_UI.end(), isClickable);
        if (it != m_UI.end()) {
            switch (it->type()) {
            case Constant::ButtonType::quitToDesktop:
                m_window.close();
                break;
            case Constant::ButtonType::startGame:
                break; // FIXME: Return PlayingState here instead
            default: // Do nothing;
                break;
            }
        }
        break;
    }
    return nullptr; // no transition (currently)
}

void MenuState::initializeUI(const Fonts& fonts)
{
    sf::Vector2u windowSize = m_window.getSize();
    float numOfElements = 2;
    unsigned y = windowSize.y;
    unsigned x = windowSize.x;
    float middleY = y / (2 * numOfElements);
    float middleX = x / 2;
    unsigned i = 0;

    m_UI.push_back(Button("Start a new game", sf::Vector2f(middleX, (i++ / numOfElements) * y + middleY), sf::Color::White, sf::Color::Black, ED::Constant::ButtonType::startGame, fonts));
    m_UI.push_back(Button("Quit game", sf::Vector2f(middleX, (i++ / numOfElements) * y + middleY), sf::Color::White, sf::Color::Black, ED::Constant::ButtonType::quitToDesktop, fonts));
}
};
