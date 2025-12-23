#include "IntType.hpp"
#include <cctype>
#include <iostream>
#include <limits>
#include <string>

IntType::IntType() : AType()
{
}

IntType::IntType(const std::string &str) : AType(str)
{
    _iss >> _value;
    updateState();
}

IntType::IntType(const IntType &other) : AType(other)
{
    _iss >> _value;
    updateState();
}

IntType::~IntType()
{
}

void IntType::convert()
{
    if (_state != Pass)
    {
        msg("char", _state);
        msg("int", _state);
        msg("float", _state);
        msg("double", _state);
        return;
    }

    if (std::numeric_limits<char>::max() < _value ||
        std::numeric_limits<char>::min() > _value)
        std::cout << "char : Impossible" << std::endl;
    else if (!std::isprint(_value))
        std::cout << "char : Not Displayable" << std::endl;
    else
        std::cout << "char : " << static_cast<char>(_value) << std::endl;

    std::cout << "int : " << _value << std::endl;
    std::cout << "float : " << static_cast<float>(_value) << std::endl;
    std::cout << "double : " << static_cast<double>(_value) << std::endl;
}

bool IntType::isValid()
{
    return _state == Pass;
}
