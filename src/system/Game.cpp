#include "system/Game.hpp"

namespace ED::System {
Game::Game()
    : m_window(init(), Constant::gameName, sf::Style::Close)
    , m_menuState(MenuState(m_window, m_fonts))
    , m_playingState(PlayingState(m_window, m_fonts, m_textures))
    , m_currentState(&m_menuState)
    , m_fonts()
    , m_textures()
{
    m_window.setFramerateLimit(Constant::frameRate);
    m_window.setKeyRepeatEnabled(false);

    m_playingState.setMenuState(m_menuState);
    m_menuState.setPlayingState(m_playingState);
}
void Game::run()
{
    sf::Clock clock;

    while (m_window.isOpen()) {
        while (m_window.pollEvent(m_event)) {
            GameState* nextState = m_currentState->handleEvent(m_event);
            if (nextState)
                m_currentState = nextState;
        }

        auto deltaTime = clock.restart();
        m_currentState->update(deltaTime);
        m_currentState->render();
    }
}

void Game::loadResources()
{
    m_fonts.load(ED::Font::ID::normal, "resources/fonts/PressStart2P.ttf");
    m_textures.load(ED::Texture::ID::tiles, "resources/textures/tileset.png");
}

sf::VideoMode Game::init()
{
    loadResources();
    return sf::VideoMode(sf::Vector2u(Constant::windowWidth, Constant::windowHeight));
}
};
