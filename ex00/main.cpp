#include "Printer.hpp"
#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 2)
        return -1;

    std::cout << "\tinput : " << argv[1] << "\n" << std::endl;
    ScalarConverter::convert(argv[1]);

    return -1;
}
