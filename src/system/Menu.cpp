#include "system/Menu.hpp"

namespace ED::System {
Menu::Menu()
    : m_window(sf::VideoMode(sf::Vector2u(Constant::windowWidth, Constant::windowHeight)), Constant::gameName, sf::Style::Close)
    , m_fonts()
{
    m_window.setFramerateLimit(Constant::frameRate);
    m_window.setKeyRepeatEnabled(false);
    loadResources();
    initializeUI();
}

Menu::~Menu() { }

void Menu::menuLoop()
{
    while (isRunning()) {
        pollEvent();
        render();
    }
}

bool Menu::isRunning() const
{
    return m_window.isOpen();
}

void Menu::pollEvent()
{
    while (m_window.pollEvent(m_event)) {
        switch (m_event.type) {
        case sf::Event::Closed:
            m_window.close();
            break;
        case sf::Event::KeyPressed:
            if (m_event.key.code == sf::Keyboard::Key::Delete) {
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
                    break; // FIXME: Start a game if this button is clicked
                default: // Do nothing;
                    break;
                }
            }
            break;
        }
    }
}

void Menu::drawUI()
{
    for (auto& element : m_UI)
        m_window.draw(element);
}

void Menu::render()
{
    m_window.clear();
    drawUI();
    m_window.display();
}

void Menu::initializeUI()
{
    sf::Vector2u windowSize = m_window.getSize();
    float numOfElements = 2;
    unsigned y = windowSize.y;
    unsigned x = windowSize.x;
    float middleY = y / (2 * numOfElements);
    float middleX = x / 2;
    unsigned i = 0;

    m_UI.push_back(Button("Start a new game", sf::Vector2f(middleX, (i++ / numOfElements) * y + middleY), sf::Color::White, sf::Color::Black, ED::Constant::ButtonType::startGame, m_fonts));
    m_UI.push_back(Button("Quit game", sf::Vector2f(middleX, (i++ / numOfElements) * y + middleY), sf::Color::White, sf::Color::Black, ED::Constant::ButtonType::quitToDesktop, m_fonts));
}

void Menu::loadResources()
{
    m_fonts.load(ED::Font::ID::normal, "resources/fonts/PressStart2P.ttf");
    m_textures.load(ED::Texture::ID::tiles, "resources/textures/tileset.png");
}

} // namespace ED::System
