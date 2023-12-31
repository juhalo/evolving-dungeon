#pragma once

#include <cassert>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>

/**
 * @brief Class for handling resource allocation
 *
 * @tparam ResourceType  Resource type
 * @tparam ID Identifier for a resource
 * @note Heavily inspired by the book SFML Game Development by Artur Moreira etc.
 */
template <typename Resource, typename ID>
class Resources {
public:
    /**
     * @brief Load specified resource
     *
     * @param id Identifier of the resource
     * @param filename File name of the resource
     */
    void load(ID id, const std::string& filename);

    /**
     * @brief Get resource object
     *
     * @param id Identifier of the resource
     * @return The resource object
     */
    Resource& resource(ID id);

    /**
     * @brief Get constant reference to the resource object
     *
     * @param id Identifier of the resource
     * @return Constant reference to the resource object
     */
    const Resource& resource(ID id) const;

private:
    /**
     * @brief Map of identifier to resource type
     *
     */
    std::map<ID, std::unique_ptr<Resource>> m_resources;
};

#include "Resources.inl"
