template <typename Resource, typename ID>
void Resources<Resource, ID>::load(ID id, const std::string& filename)
{
    std::unique_ptr<Resource> resource(new ResourceType());
    if (!resource->loadFromFile(filename)) { } // FIXME: Handle error

    // Insert to map, move used to transfer ownership
    m_resources.insert(std::make_pair(id, std::move(resource))); // FIXME: What happens if this already exists?
}

template <typename Resource, typename ID>
Resource& Resources<Resource, ID>::resource(ID id)
{
    auto found = m_resources.find(id);
    return *found->second; // FIXME: What happens if it was not found?
}

template <typename Resource, typename ID>
const Resource& Resources<Resource, ID>::resource(ID id) const
{
    auto found = m_resources.find(id);
    return *found->second; // FIXME: What happens if it was not found?
}
