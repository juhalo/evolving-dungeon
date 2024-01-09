template <typename Resource, typename ID>
void Resources<Resource, ID>::load(ID id, const std::string& filename)
{
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(filename)) {
        throw std::runtime_error("Resources::load - File loading failed for " + filename);
    }

    auto inserted = m_resources.insert(std::make_pair(id, std::move(resource)));

    // In debug mode, checks that there was no previous inserted value for given id
    assert(inserted.second);
}

template <typename Resource, typename ID>
Resource& Resources<Resource, ID>::resource(ID id)
{
    auto found = m_resources.find(id);
    // In debug mode, checks that we did not reach the end pointer, i.e. check that the resource exists
    assert(found != m_resources.end());
    return *found->second;
}

template <typename Resource, typename ID>
const Resource& Resources<Resource, ID>::resource(ID id) const
{
    auto found = m_resources.find(id);
    // In debug mode, checks that we did not reach the end pointer, i.e. check that the resource exists
    assert(found != m_resources.end());
    return *found->second;
}
