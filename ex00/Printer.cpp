#include "Printer.hpp"
#include <iomanip>
#include <iostream>

void Printer::show(char value)
{
    if (!std::isprint(value))
        std::cout << "char : Not displayable" << std::endl;
    else
        std::cout << "char : '" << (value) << "'" << std::endl;
}

void Printer::show(int value)
{
    std::cout << "int : " << (value) << std::endl;
}

void Printer::show(float value)
{
    std::cout << "float : " << std::fixed << std::setprecision(1) << (value)
              << "f" << std::endl;
}

void Printer::show(double value)
{
    std::cout << "double : " << std::fixed << std::setprecision(1) << value
              << std::endl;
}

void Printer::fail(char)
{
    std::cout << "char : Impossible" << std::endl;
}

void Printer::fail(int)
{
    std::cout << "int : Impossible" << std::endl;
}

void Printer::fail(float)
{
    std::cout << "float : Impossible" << std::endl;
}

void Printer::fail(double)
{
    std::cout << "double : Impossible" << std::endl;
}

void Printer::unknown()
{
    int value = 0;

    Printer::fail(static_cast<char>(value));
    Printer::fail(static_cast<int>(value));
    Printer::fail(static_cast<float>(value));
    Printer::fail(static_cast<double>(value));
}
