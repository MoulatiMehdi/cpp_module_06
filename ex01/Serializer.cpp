#include "Serializer.hpp"
#include <cstdint>

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &)
{
}

Serializer &Serializer::operator=(const Serializer &)
{
    return *this;
}

Serializer::~Serializer()
{
}

uintptr_t serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}
