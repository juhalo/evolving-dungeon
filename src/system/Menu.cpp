#include "system/Menu.hpp"

namespace ED::System {
Menu::Menu()
    : m_window(std::make_shared<sf::RenderWindow>(sf::VideoMode(sf::Vector2u(Constant::windowWidth, Constant::windowHeight)), Constant::gameName))
{
    initializeUI();
}

Menu::~Menu() { }

void Menu::menuLoop()
{
    pollEvent();
    render();
}

bool Menu::isRunning() const
{
    return m_window->isOpen();
}

void Menu::pollEvent()
{
    while (m_window->pollEvent(m_event)) {
        switch (m_event.type) {
        case sf::Event::Closed:
            m_window->close();
            break;
        case sf::Event::KeyPressed:
            if (m_event.key.code == sf::Keyboard::Key::Delete) {
                m_window->close();
                break;
            }
        }
    }
}

void Menu::drawUI()
{
    m_window->draw(m_UI);
}

void Menu::render()
{
    m_window->clear();
    drawUI();
    m_window->display();
}

void Menu::initializeUI()
{
    m_UI = sf::CircleShape(100.f);
    m_UI.setFillColor(sf::Color::Green);
}

} // namespace ED::System
