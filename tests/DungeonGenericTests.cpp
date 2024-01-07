#include "Textures.hpp"
#include <SFML/Graphics.hpp>
#include <gtest/gtest.h>
#include <iostream>

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
