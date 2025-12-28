#include "AType.hpp"
#include <string>

const std::string AType::DEFAULT = "";

AType::AType() : _str(DEFAULT), _state(Pass)
{
}

AType::AType(const std::string &str) : _str(str), _state(Pass)
{
}

AType::AType(const AType &other) : _str(other._str), _state(Pass)
{
}

AType &AType::operator=(const AType &)
{
    return *this;
}

AType::~AType()
{
}

AType::State AType::getState() const
{
    return _state;
}
