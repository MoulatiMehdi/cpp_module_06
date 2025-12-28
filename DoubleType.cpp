#include "DoubleType.hpp"
#include "Printer.hpp"
#include <cctype>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

DoubleType::DoubleType() : AType("0.0"), _value(0), _isPseudo(false)
{
}

DoubleType::DoubleType(const std::string &str)
    : AType(str),
      _value(0),
      _isPseudo(isPseudo(str))
{
    if (!isValid())
        _state = Error;
    else if (_isPseudo)
        _value = strtod(_str.c_str(), NULL);
    else
    {
        std::istringstream iss(_str);
        iss >> _value;
        if (!iss.eof() || iss.fail())
            _state = Error;
    }
}

DoubleType::DoubleType(const DoubleType &other)
    : AType(other),
      _value(other._value),
      _isPseudo(other._isPseudo)
{
}

DoubleType::~DoubleType()
{
}

bool DoubleType::isValid() const
{
    if (_str.empty())
        return false;
    if (_isPseudo)
        return true;
    return _str.find_first_not_of("0123456789.-+") == std::string::npos;
}

bool DoubleType::isPseudo(const std::string &str)
{
    return str == "+inf" || str == "-inf" || str == "nan";
}

void DoubleType::convert() const
{
    if (_isPseudo)
    {
        Printer::fail(static_cast<char>(_value));
        Printer::fail(static_cast<int>(_value));
        Printer::show(static_cast<float>(_value));
        Printer::show(static_cast<double>(_value));
    }
    else
    {
        if (std::numeric_limits<char>::max() < _value ||
            std::numeric_limits<char>::min() > _value)
            Printer::fail(static_cast<char>(_value));
        else
            Printer::show(static_cast<char>(_value));

        if (std::numeric_limits<int>::max() < _value ||
            std::numeric_limits<int>::min() > _value)
            Printer::fail(static_cast<int>(_value));
        else
            Printer::show(static_cast<int>(_value));

        if (std::numeric_limits<float>::max() < _value ||
            std::numeric_limits<float>::min() > _value)
            Printer::fail(static_cast<float>(_value));
        else
            Printer::show(static_cast<float>(_value));

        Printer::show(static_cast<double>(_value));
    }
}
