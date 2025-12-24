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
    msg("char", Error);
    msg("int", Error);
    msg("float", Error);
    msg("double", Error);
}

void AType::msg(const std::string &label, const State &state)
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
