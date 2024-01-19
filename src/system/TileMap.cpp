#include "system/TileMap.hpp"

namespace ED::System {
TileMap::TileMap() { }

void TileMap::load(const Textures& textures, sf::Vector2u tileSize, const int* tiles, unsigned width, unsigned height)
{
    m_tileSet = textures.resource(ED::Texture::ID::tiles);

    // resize the vertex array to fit the level size
    m_vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
    m_vertices.resize(width * height * 6);

    // populate the vertex array, with two triangles per tile
    for (unsigned i = 0; i < width; ++i)
        for (unsigned j = 0; j < height; ++j) {
            // get the current tile number
            int tileNumber = tiles[i + j * width];

            // find its position in the tileset texture
            int tu = tileNumber % (m_tileSet.getSize().x / tileSize.x);
            int tv = tileNumber / (m_tileSet.getSize().x / tileSize.x);

            // get a pointer to the triangles' vertices of the current tile
            sf::Vertex* triangles = &m_vertices[(i + j * width) * 6];

            // define the 6 corners of the two triangles
            triangles[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            triangles[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            triangles[2].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
            triangles[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
            triangles[4].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            triangles[5].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);

            // define the 6 matching texture coordinates
            triangles[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            triangles[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            triangles[2].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            triangles[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            triangles[4].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            triangles[5].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
        }
}

TileMap::~TileMap() { }

void TileMap::draw(sf::RenderTarget& target, const sf::RenderStates& states) const
{
    // Copy is needed due to const reference, note change from tutorial due to SFML change, see https://github.com/SFML/SFML/pull/2008
    sf::RenderStates statesCopy(states);

    // apply the transform
    statesCopy.transform *= getTransform();

    // apply the tileset texture
    statesCopy.texture = &m_tileSet;

    // draw the vertex array
    target.draw(m_vertices, statesCopy);
}
};
