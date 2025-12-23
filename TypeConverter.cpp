#include "TypeConverter.hpp"
#include <cctype>
#include <cerrno>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <ostream>
#include <sstream>
#include <string>

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

bool TypeConverter::isPseudo(const std::string &str)
{
    const std::string pseudos[] = {
        "nan", "nanf", "+inf", "-inf", "+inff", "-inff"
    };
    int size = sizeof(pseudos) / sizeof(pseudos[0]);

    for (int i = 0; i < size; i++)
    {
        if (pseudos[i] == str)
            return true;
    }
    return false;
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

static void fail()
{
    std::cout << "char : Impossible" << std::endl;
    std::cout << "int : Impossible " << std::endl;
    std::cout << "float : Impossible " << std::endl;
    std::cout << "double : Impossible " << std::endl;
}

bool TypeConverter::isFloat(const std::string &str)
{
    size_t i   = 0;
    size_t len = str.length();

    if (len <= 1 || str[len - 1] != 'f')
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
    TypeAction actions[] = {
        {isPseudo, Pseudo},
        {  isChar,   Char},
        {   isInt,    Int},
        { isFloat,  Float},
        {isDouble, Double},
    };
    int size = sizeof(actions) / sizeof(actions[0]);

    if (!str.empty())
    {
        for (int i = 0; i < size; i++)
        {
            if (actions[i].func(str))
                return actions[i].type;
        }
    }
    return Unknown;
}

static void convertFromCharToAll(std::istringstream &iss)
{
    char c;
    iss >> c;

    if (iss.fail() || !iss.eof())
        return fail();

    std::cout << "char : ";
    if (std::isprint(c))
        std::cout << static_cast<char>(c) << std::endl;
    else
        TypeConverter::error("char", TypeConverter::Invisible);
    std::cout << std::endl;
    std::cout << "int : " << static_cast<int>(c) << std::endl;
    std::cout << "float : " << static_cast<float>(c) << std::endl;
    std::cout << "double : " << static_cast<double>(c) << std::endl;
}

static void convertFromIntToAll(std::istringstream &iss)
{
    int n;
    iss >> n;

    if (iss.fail() || !iss.eof())
        return fail();

    if (std::numeric_limits<char>::max() < n ||
        std::numeric_limits<char>::min() > n)
        TypeConverter::error("char", TypeConverter::Error);
    else if (!std::isprint(n))
        TypeConverter::error("char", TypeConverter::Invisible);
    else
        std::cout << "char : " << static_cast<char>(n) << std::endl;

    std::cout << "int : " << static_cast<int>(n) << std::endl;

    std::cout << "float : " << static_cast<float>(n) << std::endl;

    std::cout << "double : " << static_cast<double>(n) << std::endl;
}

static void convertFromDoubleToAll(std::istringstream &iss)
{
    double n;
    iss >> n;

    if (iss.fail() || !iss.eof())
        return fail();

    if (std::numeric_limits<char>::max() < n ||
        std::numeric_limits<char>::min() > n)
        TypeConverter::error("char", TypeConverter::Error);
    else if (!std::isprint(n))
        TypeConverter::error("char", TypeConverter::Invisible);
    else
        std::cout << "char : " << static_cast<char>(n) << std::endl;

    if (std::numeric_limits<int>::max() < n ||
        std::numeric_limits<int>::min() > n)
        TypeConverter::error("int", TypeConverter::Error);
    else
        std::cout << "int" << static_cast<int>(n) << std::endl;

    if (std::numeric_limits<float>::max() < n ||
        std::numeric_limits<float>::min() > n)
        TypeConverter::error("float", TypeConverter::Error);
    else
        std::cout << "float : " << static_cast<float>(n) << std::endl;

    std::cout << "double : " << static_cast<double>(n) << std::endl;
}

static void convertFromFloatToAll(std::istringstream &iss)
{
    std::string c;
    float       n;
    iss >> n >> c;
    std::cout << c << std::endl;
    if (iss.fail() || c != "f" || !iss.eof())
        return fail();

    if (std::numeric_limits<char>::max() < n ||
        std::numeric_limits<char>::min() > n)
        TypeConverter::error("char", TypeConverter::Error);
    else if (!std::isprint(n))
        TypeConverter::error("char", TypeConverter::Invisible);
    else
        std::cout << "char : " << static_cast<char>(n) << std::endl;

    if (std::numeric_limits<int>::max() < static_cast<int>(n) ||
        std::numeric_limits<int>::min() > static_cast<int>(n))
        TypeConverter::error("int", TypeConverter::Error);
    else
        std::cout << static_cast<int>(n) << std::endl;

    std::cout << static_cast<float>(n) << std::endl;
    std::cout << static_cast<double>(n) << std::endl;
}

static void convertFromPseudoToAll(const std::string &str)
{
    TypeConverter::error("char", TypeConverter::Error);
    TypeConverter::error("int", TypeConverter::Error);
    if (str == "nanf" || str == "-inff" || str == "+inff")
    {
        std::cout << "float : " << str << std::endl;
        std::cout << "double : " << str.substr(0, str.length() - 1)
                  << std::endl;
    }
    else
    {
        std::cout << "float : " << str << "f" << std::endl;
        std::cout << "double : " << str << std::endl;
    }
}

void TypeConverter::error(const std::string &label, const State state)
{
    switch (state)
    {
        case Error:
            std::cout << label << " : " << "Impossible" << std::endl;
            return;
        case Invisible:
            std::cout << label << " : " << "Not displayable" << std::endl;
            return;
        case Ok:
            return;
    }
}

void TypeConverter::convertToAllTypes(const std::string &str)
{
    std::istringstream iss(str);
    Type               type = getLiteralType(str);
    switch (type)
    {
        case Pseudo:
            std::cout << "Pseudo" << std::endl;
            return convertFromPseudoToAll(str);

        case Char:
            std::cout << "Char" << std::endl;
            return convertFromCharToAll(iss);
        case Int:
            std::cout << "Int" << std::endl;
            return convertFromIntToAll(iss);
        case Double:
            std::cout << "Double" << std::endl;
            return convertFromDoubleToAll(iss);
        case Float:
            std::cout << "Float" << std::endl;
            return convertFromFloatToAll(iss);
        case Unknown:
            return fail();
    }
}


