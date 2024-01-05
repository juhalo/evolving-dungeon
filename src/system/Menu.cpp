#include "system/Menu.hpp"

Menu::Menu()
    : m_window(std::shared_ptr<sf::RenderWindow>(new sf::RenderWindow { sf::VideoMode(sf::Vector2u(200, 200)), "Evolving Dungeon" }))
{
}

Menu::~Menu() { }

void Menu::menuLoop()
{
    sf::Event event;
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    while (m_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            m_window->close();
    }
    m_window->clear();
    m_window->draw(shape);
    m_window->display();
}

bool Menu::isRunning() const
{
    return m_window->isOpen();
}
