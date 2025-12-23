#include "../TypeConverter.hpp"
#include <string>

typedef struct
{
    std::string name;
    bool (*func)(const std::string &);
} action;

int main(int argc, char *argv[])
{
    // std::string arr[] = {
    //     ".",    ".5",   ".1.5", ".15.",  "1",     "1.",    "1.5",
    //     "1..5", "1.5.", "f",    ".f",    ".5f",   ".1.5f", ".15.f",
    //     "1f",   "1.f",  "1.5f", "1..5f", "1.5.f",
    // };
    // int    size       = sizeof(arr) / sizeof(arr[0]);
    // action actions[4] = {
    //     {   "int",    TypeConverter::isInt},
    //     {  "char",   TypeConverter::isChar},
    //     { "float",  TypeConverter::isFloat},
    //     {"double", TypeConverter::isDouble},
    // };
    //
    // std::cout << std::string(5 * 12 + 5, '-') << std::endl;
    // std::cout << "|" << std::setw(10) << std::left << "number";
    // for (int j = 0; j < 4; j++)
    // {
    //     std::cout << " | " << std::setw(10) << std::boolalpha
    //               << actions[j].name;
    // }
    // std::cout << " |" << std::endl;
    // std::cout << std::string(5 * 12 + 5, '-') << std::endl;
    // for (int i = 0; i < size; i++)
    // {
    //     std::cout << "|" << std::setw(10) << std::left << arr[i];
    //     for (int j = 0; j < 4; j++)
    //     {
    //         std::cout << " | " << std::setw(10) << std::boolalpha
    //                   << actions[j].func(arr[i]);
    //     }
    //     std::cout << " |" << std::endl;
    //     std::cout << std::string(5 * 12 + 5, '-') << std::endl;
    // }

    if(argc != 2)
        return -1;
    TypeConverter::convertToAllTypes(argv[1]);
    return 0;
}
