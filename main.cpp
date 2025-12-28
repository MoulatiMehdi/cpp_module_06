#include "AType.hpp"
#include "CharType.hpp"
#include "DoubleType.hpp"
#include "FloatType.hpp"
#include "IntType.hpp"
#include "Printer.hpp"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 2)
        return -1;

    bool      pass = false;
    const int size = 4;

    std::cout << "\tinput : " << argv[1] << "\n" << std::endl;

    AType *a[size] = {
        new CharType(argv[1]),
        new IntType(argv[1]),
        new FloatType(argv[1]),
        new DoubleType(argv[1])
    };

    for (int i = 0; i < size; i++)
    {
        if (a[i]->getState() == AType::Pass)
        {
            std::cout << i << std::endl;
            a[i]->convert();
            pass = true;
            std::cout << std::string(50, '-') << std::endl;
        }
    }
    if (!pass)
        Printer::unknown();

    for (int i = 0; i < size; i++)
    {
        delete a[i];
    }

    return -1;
}
