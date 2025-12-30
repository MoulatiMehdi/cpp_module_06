#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

int main(int, char *[])
{
    std::srand(std::time(0));
    {
        Base a;
        identify(a);
        identify(&a);
        std::cout << std::string(50, '-') << std::endl;
    }
    {
        A a;
        identify(a);
        identify(&a);
        std::cout << std::string(50, '-') << std::endl;
    }
    {
        B a;
        identify(a);
        identify(&a);
        std::cout << std::string(50, '-') << std::endl;
    }
    {
        C a;
        identify(a);
        identify(&a);
        std::cout << std::string(50, '-') << std::endl;
    }

    {
        Base *a = generate();
        identify(a);
    }
    {
        Base &a = *generate();
        identify(a);
        std::cout << std::string(50, '-') << std::endl;
    }
    return 0;
}
