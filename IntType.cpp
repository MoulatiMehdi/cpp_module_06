#include "IntType.hpp"
#include <cctype>
#include <iostream>
#include <limits>
#include <string>

IntType::IntType() : AType()
{
    updateState();
}

IntType::IntType(const std::string &str) : AType(str)
{
    updateState();
}

IntType::IntType(const IntType &other) : AType(other)
{
    updateState();
}

IntType::~IntType()
{
}

void IntType::updateState()
{
    if (isspace(_str.at(0)))
        _state = Error;
    else
    {
        std::istringstream iss(_str);
        iss >> _value;
        if (!iss.eof() || iss.fail())
            _state = Error;
    }
}

void IntType::convert()
{
    if (_state != Pass)
        return error();

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
