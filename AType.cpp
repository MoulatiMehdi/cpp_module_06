#include "AType.hpp"
#include <iostream>
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

void AType::error()
{
    error("char", Error);
    error("int", Error);
    error("float", Error);
    error("double", Error);
}

void AType::error(const std::string &label, const State &state)
{
    switch (state)
    {
        case Error:
            std::cout << label << " : Impossible" << std::endl;
            break;
        case Hidden:
            std::cout << label << " : Not displayable" << std::endl;
            break;
        case Pass:
            break;
    }
}
