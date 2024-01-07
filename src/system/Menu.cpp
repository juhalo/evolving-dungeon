#include "system/Menu.hpp"

namespace ED::System {
Menu::Menu()
    : m_window(std::make_shared<sf::RenderWindow>(sf::VideoMode(sf::Vector2u(Constant::windowWidth, Constant::windowHeight)), Constant::gameName))
    , m_UI(sf::CircleShape(100.f))
{
    m_UI.setFillColor(sf::Color::Green);
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
        if (m_event.type == sf::Event::Closed)
            m_window->close();
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

} // namespace ED::System
