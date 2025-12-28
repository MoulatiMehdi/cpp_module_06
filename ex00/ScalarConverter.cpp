#include "ScalarConverter.hpp"
#include "AType.hpp"
#include "CharType.hpp"
#include "DoubleType.hpp"
#include "FloatType.hpp"
#include "IntType.hpp"
#include "Printer.hpp"
#include <string>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &)
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &)
{
    return *this;
}

void ScalarConverter::convert(const std::string &str)
{
    const int size      = 4;
    bool      is_failed = true;

    AType *types[size] = {
        new CharType(str),
        new IntType(str),
        new FloatType(str),
        new DoubleType(str)
    };

    for (int i = 0; i < size; i++)
    {
        if (types[i]->getState() == AType::Pass)
        {
            types[i]->convert();
            is_failed = false;
            break;
        }
    }
    if (is_failed)
        Printer::unknown();
    for (int i = 0; i < size; i++)
    {
        delete types[i];
    }
}
