#include "DoubleType.hpp"
#include <cctype>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

DoubleType::DoubleType() : AType(""), _value(0)
{
}

DoubleType::DoubleType(const std::string &str) : AType(str), _value(0)
{
    updateState();
}

DoubleType::DoubleType(const DoubleType &other)
    : AType(other),
      _value(other._value)
{
}

DoubleType::~DoubleType()
{
}

void DoubleType::updateState()
{
    if (_state != Pass)
        return;

    if (!isValid())
        _state = Error;
    else if (isPseudo())
        _value = strtod(_str.c_str(), NULL);
    else
    {
        std::istringstream iss(_str);
        iss >> _value;
        if (!iss.eof() || iss.fail())
            _state = Error;
    }
}

bool DoubleType::isValid()
{
    if (_str.empty() || isspace(_str[0]))
        return false;
    if (isPseudo())
        return true;

    std::size_t i = 0;
    if (strchr("+-", _str[0]) != NULL)
        i++;
    while (i < _str.length())
    {
        if (!std::isdigit(_str[i]) && _str[i] != '.')
            return false;
        i++;
    }
    return _str.find('.') != std::string::npos;
}

bool DoubleType::isPseudo()
{
    return _str == "+inf" || _str == "-inf" || _str == "nan";
}

void DoubleType::convert()
{
    if (_state != Pass)
        return unknown();

    if (isPseudo() || _value > std::numeric_limits<char>::max() ||
        _value < std::numeric_limits<char>::min())
        error("char", Error);
    else if (!std::isprint(_value))
        error("char", Hidden);
    else
        std::cout << "char : '" << static_cast<char>(_value) << "'"
                  << std::endl;

    if (isPseudo() || std::numeric_limits<int>::max() < _value ||
        std::numeric_limits<int>::min() > _value)
        error("int", Error);
    else
        std::cout << "int : " << static_cast<int>(_value) << std::endl;

    if (!isPseudo() && (_value > std::numeric_limits<float>::max() ||
                        _value < -std::numeric_limits<float>::max()))
        error("float", Error);
    else
        std::cout << "float : " << std::fixed << std::setprecision(1)
                  << static_cast<float>(_value) << "f" << std::endl;

    std::cout << "double : " << std::fixed << std::setprecision(1)
              << static_cast<double>(_value) << std::endl;
}
