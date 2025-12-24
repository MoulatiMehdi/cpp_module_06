#include "DoubleType.hpp"
#include <cctype>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

DoubleType::DoubleType() : AType("")
{
    updateState();
}

DoubleType::DoubleType(const std::string &str) : AType(str)
{
    updateState();
}

DoubleType::DoubleType(const DoubleType &other) : AType(other)
{
    updateState();
}

DoubleType::~DoubleType()
{
}

void DoubleType::updateState()
{
    if (_state != Pass)
        return;
    if (_str.empty() || isspace(_str.at(0)))
        _state = Error;
    else
    {
        std::istringstream iss(_str);
        iss >> _value;
        if (!iss.eof() || iss.fail())
            _state = Error;
    }
}

void DoubleType::convert()
{
    if (_state != Pass)
        return error();
    if (std::numeric_limits<char>::max() < _value ||
        std::numeric_limits<char>::min() > _value)
        error("char", Error);
    else if (!std::isprint(_value))
        error("char", Hidden);
    else
        std::cout << "char : " << static_cast<char>(_value) << std::endl;

    std::cout << "int : " << _value << std::endl;
    std::cout << "float : " << static_cast<float>(_value) << std::endl;
    std::cout << "double : " << static_cast<double>(_value) << std::endl;
}
