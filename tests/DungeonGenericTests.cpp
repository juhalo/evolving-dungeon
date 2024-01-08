#include "Constants.hpp"
#include "Textures.hpp"
#include "system/Button.hpp"
#include <SFML/Graphics.hpp>
#include <gtest/gtest.h>

// Demonstrate some basic assertions, checks that googletest load correctly.
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
    bool texturesLoadedSuccessfully = ED::Texture::loadTextures();
    // Needs to be assert for the next part to not cause errors and break the test
    ASSERT_EQ(true, texturesLoadedSuccessfully);
    EXPECT_EQ(ED::Texture::font->getInfo().family, "Press Start 2P");
}

// Check basic properties of button class
TEST(ButtonTest, BasicProperties)
{
    bool texturesLoadedSuccessfully = ED::Texture::loadTextures();
    // Needs to be assert for the next part to not cause errors and break the test
    ASSERT_EQ(true, texturesLoadedSuccessfully);

    // Test non-clickable button:
    std::string name = "Test test";
    ED::System::Button noneButton = ED::System::Button(name, sf::Vector2f(0, 0), sf::Color::Black, sf::Color::White, ED::Constant::ButtonType::none);
    EXPECT_EQ(noneButton.type(), ED::Constant::ButtonType::none);
    EXPECT_EQ(noneButton.clickButton(sf::Vector2i(1, 1)), false);
    EXPECT_EQ(noneButton.clickButton(sf::Vector2i(100, 100)), false);
    EXPECT_EQ(noneButton.position(), sf::Vector2f(0, 0));

    // Test clickable button:
    ED::System::Button clickButton = ED::System::Button(name, sf::Vector2f(0, 0), sf::Color::Black, sf::Color::White, ED::Constant::ButtonType::startGame);
    EXPECT_EQ(clickButton.type(), ED::Constant::ButtonType::startGame);
    EXPECT_EQ(clickButton.clickButton(sf::Vector2i(1, 1)), true);
    EXPECT_EQ(clickButton.clickButton(sf::Vector2i(100, 100)), false);
    EXPECT_EQ(clickButton.position(), sf::Vector2f(0, 0));

    // Test changing buttons properties:
    ED::System::Button changeButton = ED::System::Button(name, sf::Vector2f(0, 0), sf::Color::Black, sf::Color::White, ED::Constant::ButtonType::none);
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
