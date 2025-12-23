#include "AType.hpp"
#include <iostream>
#include <string>

const std::string AType::DEFAULT = "";

AType::AType() : _str(DEFAULT), _iss(DEFAULT)
{
}

AType::AType(const std::string &str) : _str(str), _iss(str)
{
}

AType::AType(const AType &other) : _str(other._str), _iss(other._str)
{
}

AType &AType::operator=(const AType &)
{
    return *this;
}

AType::~AType()
{
}

void AType::updateState()
{
    if (_iss.eof() && !_iss.fail())
        _state = Pass;
    else
        _state = Error;
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
