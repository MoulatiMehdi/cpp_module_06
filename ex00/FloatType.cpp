#include "FloatType.hpp"
#include "Printer.hpp"
#include <cmath>
#include <limits>
#include <sstream>

FloatType::FloatType() : AType("0.0f"), _value(0), _isPseudo(false)
{
}

FloatType::FloatType(const std::string &str)
    : AType(str),
      _value(0),
      _isPseudo(isPseudo(_str))
{
    if (_isPseudo)
        _value = strtof(_str.c_str(), NULL);
    else if (!isValid())
        _state = Error;
    else
    {
        std::istringstream iss(_str);
        std::string        s;
        iss >> std::noskipws >> _value;
        std::getline(iss, s);
        if (iss.fail() || s != "f")
            _state = Error;
    }
}

FloatType::FloatType(const FloatType &other)
    : AType(other),
      _value(other._value),
      _isPseudo(other._isPseudo)
{
}

FloatType::~FloatType()
{
}

bool FloatType::isPseudo(const std::string &str)
{
    return str == "+inff" || str == "-inff" || str == "nanf";
}

bool FloatType::isValid() const
{
    if (_str.find(".") == std::string::npos)
        return false;
    if (_isPseudo)
        return true;
    return _str.find_first_not_of("0123456789.+-f") == std::string::npos;
}

void FloatType::convert() const
{
    if (_isPseudo || std::numeric_limits<char>::max() < _value ||
        std::numeric_limits<char>::min() > _value)
        Printer::fail(static_cast<char>(_value));
    else
        Printer::show(static_cast<char>(_value));

    if (_isPseudo ||
        std::numeric_limits<int>::max() < static_cast<long>(_value) ||
        std::numeric_limits<int>::min() > static_cast<long>(_value))
        Printer::fail(static_cast<int>(_value));
    else
        Printer::show(static_cast<int>(_value));

    Printer::show(static_cast<float>(_value));
    Printer::show(static_cast<double>(_value));
}
