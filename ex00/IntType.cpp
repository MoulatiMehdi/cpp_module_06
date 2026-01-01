#include "IntType.hpp"
#include "Printer.hpp"
#include <limits>
#include <sstream>

IntType::IntType() : AType("0"), _value(0)
{
}

IntType::IntType(const std::string &str) : AType(str), _value(0)
{
    std::istringstream iss(_str);
    iss >> std::noskipws >> _value;
    if (!iss.eof() || iss.fail())
        _state = Error;
}

IntType::IntType(const IntType &other) : AType(other), _value(other._value)
{
}

IntType::~IntType()
{
}

void IntType::convert() const
{
    if (std::numeric_limits<char>::max() < _value ||
        std::numeric_limits<char>::min() > _value)
        Printer::fail(static_cast<char>(_value));
    else
        Printer::show(static_cast<char>(_value));

    Printer::show(static_cast<int>(_value));
    Printer::show(static_cast<float>(_value));
    Printer::show(static_cast<double>(_value));
}
