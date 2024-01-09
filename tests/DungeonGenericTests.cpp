#include "Constants.hpp"
#include "Resources.hpp"
#include "system/Button.hpp"
#include <SFML/Graphics.hpp>
#include <gtest/gtest.h>
#include <stdexcept>

// Demonstrate some basic assertions, checks that GoogleTest loads correctly.
TEST(HelloTest, BasicAssertions)
{
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}

// Check that SFML loads correctly
TEST(HelloTest, SFMLLoading)
{
    sf::Vector2i vectorOne = sf::Vector2i(0, -1);
    sf::Vector2i vectorTwo = sf::Vector2i(0, -1);
    EXPECT_EQ(vectorOne.x, vectorTwo.x);
    EXPECT_EQ(vectorOne.y, vectorTwo.y);

    sf::Vector2i vectorThree = sf::Vector2i(0, 1);
    EXPECT_EQ(vectorOne.x, vectorThree.x);
    EXPECT_NE(vectorOne.y, vectorThree.y);
}

// Check that static file loading works correctly
TEST(HelloTest, StaticFileLoading)
{
    // Checks that textures get loaded without errors
    Textures textures;
    EXPECT_NO_THROW(textures.load(ED::Texture::ID::tiles, "resources/textures/tileset.png"));

    // Checks that fonts get loaded properly without errors
    Fonts fonts;
    // Assert is needed because trying to access the font after this (in case of exception) would terminate the program
    ASSERT_NO_THROW(fonts.load(ED::Font::ID::normal, "resources/fonts/PressStart2P.ttf"));
    sf::Font font = fonts.resource(ED::Font::ID::normal);
    EXPECT_EQ(font.getInfo().family, "Press Start 2P");

    // Non-existent file should throw an exception
    EXPECT_THROW(fonts.load(ED::Font::ID::normal, "resources/fonts/DoesNotExist.ttf"), std::runtime_error);
}

// Check basic properties of button class
TEST(ButtonTest, BasicProperties)
{
    Fonts fonts;
    ASSERT_NO_THROW({
        fonts.load(ED::Font::ID::normal, "resources/fonts/PressStart2P.ttf");
    });

    // Test non-clickable button:
    std::string name = "Test test";
    ED::System::Button noneButton = ED::System::Button(name, sf::Vector2f(0, 0), sf::Color::Black, sf::Color::White, ED::Constant::ButtonType::none, fonts);
    EXPECT_EQ(noneButton.type(), ED::Constant::ButtonType::none);
    EXPECT_EQ(noneButton.clickButton(sf::Vector2i(1, 1)), false);
    EXPECT_EQ(noneButton.clickButton(sf::Vector2i(100, 100)), false);
    EXPECT_EQ(noneButton.position(), sf::Vector2f(0, 0));

    // Test clickable button:
    ED::System::Button clickButton = ED::System::Button(name, sf::Vector2f(0, 0), sf::Color::Black, sf::Color::White, ED::Constant::ButtonType::startGame, fonts);
    EXPECT_EQ(clickButton.type(), ED::Constant::ButtonType::startGame);
    EXPECT_EQ(clickButton.clickButton(sf::Vector2i(1, 1)), true);
    EXPECT_EQ(clickButton.clickButton(sf::Vector2i(100, 100)), false);
    EXPECT_EQ(clickButton.position(), sf::Vector2f(0, 0));

    // Test changing buttons properties:
    ED::System::Button changeButton = ED::System::Button(name, sf::Vector2f(0, 0), sf::Color::Black, sf::Color::White, ED::Constant::ButtonType::none, fonts);
    EXPECT_EQ(changeButton.string(), name);

    std::string newName = "New name right";
    changeButton.setString(newName);
    EXPECT_EQ(changeButton.string(), newName);
    EXPECT_EQ(changeButton.type(), ED::Constant::ButtonType::none);
    EXPECT_EQ(changeButton.clickButton(sf::Vector2i(1, 1)), false);
    EXPECT_EQ(changeButton.clickButton(sf::Vector2i(100, 100)), false);
    EXPECT_EQ(changeButton.position(), sf::Vector2f(0, 0));

    changeButton.setType(ED::Constant::ButtonType::startGame);
    EXPECT_EQ(changeButton.type(), ED::Constant::ButtonType::startGame);
    EXPECT_EQ(changeButton.clickButton(sf::Vector2i(1, 1)), true);
    EXPECT_EQ(changeButton.clickButton(sf::Vector2i(100, 100)), false);
    EXPECT_EQ(changeButton.position(), sf::Vector2f(0, 0));
}
