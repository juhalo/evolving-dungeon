#pragma once

#include "Constants.hpp"
#include "Resources.hpp"
#include <SFML/Graphics.hpp>

namespace ED::System {
/**
 * @brief SFML TileMap
 * @note This is the example subclass SFML TileMap
 *
 */
class TileMap : public sf::Drawable, public sf::Transformable {
public:
    /**
     * @brief Construct a new Tile Map object
     *
     */
    TileMap();

    /**
     * @brief Destroy the Tile Map object
     *
     */
    ~TileMap();

    /**
     * @brief Load a tileset on this TileMap
     *
     * @param textures Textures for the tiles
     * @param tileSize Size of each tile
     * @param tiles Tiles of the tilemap
     * @param width Width of the level
     * @param height Height of the level
     */
    void load(const Textures& textures, sf::Vector2u tileSize, const int* tiles, unsigned width, unsigned height);

private:
    /**
     * @brief Draws the TileMap to target, provided by class sf::Drawable
     *
     * @param target The render object, i.e. window
     * @param states States used for drawing to the target
     */
    void draw(sf::RenderTarget& target, const sf::RenderStates& states) const final;

    /**
     * @brief Vertex array for the tiles
     *
     */
    sf::VertexArray m_vertices;

    /**
     * @brief Textures of the TileMap
     *
     */
    sf::Texture m_tileSet;
};
};
