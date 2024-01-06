#include "system/Menu.hpp"

namespace ed {
namespace System {
    Menu::Menu()
        : m_window(std::shared_ptr<sf::RenderWindow>(new sf::RenderWindow { sf::VideoMode(sf::Vector2u(Constant::windowWidth, Constant::windowHeight)), Constant::gameName }))
    {
    }

    Menu::~Menu() { }

    void Menu::menuLoop()
    {
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);
        while (m_window->pollEvent(m_event)) {
            if (m_event.type == sf::Event::Closed)
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
}
}
