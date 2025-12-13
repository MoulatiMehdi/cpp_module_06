#include "TypeConverter.hpp"
#include <cctype>
#include <climits>
#include <cmath>

TypeConverter::TypeConverter()
{
}

TypeConverter::TypeConverter(const TypeConverter &)
{
}

TypeConverter &TypeConverter::operator=(const TypeConverter &)
{
    return *this;
}

TypeConverter::~TypeConverter()
{
}

bool TypeConverter::isChar(const std::string &str)
{
    return str.length() == 1 && !isdigit(str[0]);
}

bool TypeConverter::isInt(const std::string &str)
{
    size_t i   = 0;
    size_t len = str.length();
    if ((str[i] == '+' || str[i] == '-') && i < len)
        i++;
    while (i < len)
    {
        if (!isdigit(str[i]))
            return false;
        i++;
    }
    return i == len;
}

bool TypeConverter::isFloat(const std::string &str)
{
    size_t i   = 0;
    size_t len = str.length();

    if (str == "+inff" || str == "-inff" || str == "nanf")
        return true;
    if (str[len - 1] != 'f' || len - 1 == 0)
        return false;

    if (i < len && (str[i] == '+' || str[i] == '-'))
        i++;
    while (i < len && isdigit(str[i]))
    {
        i++;
    }
    if (i < len && str[i] == '.')
    {
        if (!(i - 1 < len && isdigit(str[i - 1])) &&
            !(i + 1 < len && isdigit(str[i + 1])))
            return false;
        i++;
    }
    while (isdigit(str[i]) && i < len)
    {
        i++;
    }
    if (i >= len || str[i] != 'f')
        return false;
    i++;
    return i == len;
}

bool TypeConverter::isDouble(const std::string &str)
{
    if (str == "+inf" || str == "-inf" || str == "nan")
        return true;

    size_t i   = 0;
    size_t len = str.length();
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (i < len && isdigit(str[i]))
    {
        i++;
    }
    if (i < len && str[i] == '.')
    {
        if (!(i - 1 < len && isdigit(str[i - 1])) &&
            !(i + 1 < len && isdigit(str[i + 1])))
            return false;
        i++;
    }
    else
        return false;
    while (isdigit(str[i]) && i < len)
    {
        i++;
    }
    return i == len;
}

TypeConverter::Type TypeConverter::getLiteralType(const std::string &str)
{
    TypeAction actions[4] = {
        {  isChar,   Char},
        {   isInt,    Int},
        { isFloat,  Float},
        {isDouble, Double}
    };
    int size = sizeof(actions) / sizeof(actions[0]);

    for (int i = 0; i < size; i++)
    {
        if (actions[i].func(str))
            return actions[i].type;
    }
    return Unknown;
}
