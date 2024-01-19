#pragma once

#include "Constants.hpp"
#include "Resources.hpp"
#include "system/TileMap.hpp"
#include <SFML/Graphics.hpp>

namespace ED::System {
class Level {
public:
    /**
     * @brief Construct a new Level object
     *
     * @param fonts Fonts of the level
     * @param textures Textures of the level
     */
    Level(const Fonts& fonts, const Textures& textures, sf::Vector2u tileMapSize);

    /**
     * @brief Destroy the Level object
     *
     */
    ~Level();

    /**
     * @brief Get the tile map object
     *
     * @return The tile map
     */
    const TileMap& tileMap() const;

private:
    /**
     * @brief Size of tile maps of the level
     *
     */
    sf::Vector2u m_tileMapSize;

    /**
     * @brief Tile map of the level
     *
     */
    TileMap m_tileMap;
};
};
