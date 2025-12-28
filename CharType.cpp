#include "CharType.hpp"
#include "Printer.hpp"
#include <string>

CharType::CharType() : AType("0"), _value('0')
{
    updateState();
}

CharType::CharType(const std::string &str) : AType(str), _value(0)
{
    if (_str.length() != 1 || std::isdigit(_str[0]))
        _state = Error;
    else
        _value = _str[0];
}

CharType::CharType(const CharType &other) : AType(other), _value(other._value)
{
}

CharType::~CharType()
{
}

void CharType::updateState()
{
}

void CharType::convert() const
{
    Printer::show(static_cast<char>(_value));
    Printer::show(static_cast<int>(_value));
    Printer::show(static_cast<float>(_value));
    Printer::show(static_cast<double>(_value));
}
