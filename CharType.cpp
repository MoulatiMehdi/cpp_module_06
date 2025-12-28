#include "CharType.hpp"
#include <cctype>
#include <iostream>
#include <string>

CharType::CharType() : AType("")
{
    updateState();
}

CharType::CharType(const std::string &str) : AType(str)
{
    updateState();
}

CharType::CharType(const CharType &other) : AType(other)
{
    updateState();
}

CharType::~CharType()
{
}

void CharType::updateState()
{
    if (_state != Pass)
        return;
    if (_str.length() != 1 || std::isdigit(_str[0]))
        _state = Error;
    _value = _str[0];
}

void CharType::convert()
{
    if (!std::isprint(_value))
        error("char", Hidden);
    else
        std::cout << "char : " << _value << std::endl;
    std::cout << "int : " << static_cast<char>(_value) << std::endl;
    std::cout << "float : " << static_cast<float>(_value) << std::endl;
    std::cout << "double : " << static_cast<double>(_value) << std::endl;
}
