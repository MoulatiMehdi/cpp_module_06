#include "IntType.hpp"
#include <climits>
#include <iostream>
#include <string>

#define SIZE(arr) sizeof(arr) / sizeof(arr[0])

#define RESET     "\033[0m"
#define FAIL      "\033[1;30;41m FAIL " RESET
#define PASS      "\033[1;30;42m PASS " RESET
#define LABEL     "\033[1;90m"

struct Test
{
    std::string  input;
    AType::State expected;
};

struct Score
{
    int size;
    int fail;
};

std::string toString(AType::State state)
{
    switch (state)
    {
        case AType::Pass:
            return "Pass";
        case AType::Hidden:
            return "Hidden";
        case AType::Error:
            return "Error";
    }
    return "Unknown";
}

int main()
{
    const Test tests[] = {
        {       "nanf", AType::Error},
        {      "-inff", AType::Error},
        {      "+inff", AType::Error},
        {       "inff", AType::Error},
        {        "1.f", AType::Error},
        {       "1.5f", AType::Error},
        {         ".5", AType::Error},
        {         "1.", AType::Error},
        {        "1.5", AType::Error},
        {        "nan", AType::Error},
        {       "+inf", AType::Error},
        {       "-inf", AType::Error},
        {        ".5f", AType::Error},
        {       "1..5", AType::Error},
        {          ".", AType::Error},
        {       "1.5.", AType::Error},
        {       ".1.5", AType::Error},
        {       ".15.", AType::Error},
        {         ".f", AType::Error},
        {          "f", AType::Error},
        {      ".1.5f", AType::Error},
        {      ".15.f", AType::Error},
        {         "1f", AType::Error},
        {      "1..5f", AType::Error},
        {      "1.5.f", AType::Error},
        {        "inf", AType::Error},
        {       "inff", AType::Error},
        {          "1",  AType::Pass},
        {"-2147483648",  AType::Pass},
        { "2147483647",  AType::Pass},
        { "2147483648",  AType::Error},
        {"-2147483649",  AType::Error},
        {"-",  AType::Error},
        {"+",  AType::Error},
        {"+0",  AType::Pass},
        {"-0",  AType::Pass},
        {"--",  AType::Error},
        {"++",  AType::Error},
    };

    const int size  = SIZE(tests);
    Score     score = {size, 0};

    for (int i = 0; i < size; i++)
    {
        const Test &test = tests[i];
        IntType     a(test.input);

        if (test.expected != a.getState())
        {
            std::cout << FAIL << LABEL " : " << test.input << std::endl;
            std::cout << LABEL << "\t\tExpceted : " << toString(test.expected)
                      << RESET << std::endl;
            std::cout << LABEL << "\t\tGot      : " << toString(a.getState())
                      << RESET << std::endl;
            score.fail++;
        }
    }

    std::cout << LABEL << std::string(50, '-') << RESET << std::endl;
    std::cout << "\t";

    if (score.fail > 0)
        std::cout << FAIL;
    else
        std::cout << PASS;

    std::cout << LABEL " : IntType (" << score.fail << "/" << score.size << ")"
              << RESET << std::endl;
}
