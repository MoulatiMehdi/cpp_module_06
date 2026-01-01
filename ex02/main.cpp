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

    Base *objs[] = {
        new Base(),
        new A(),
        new B(),
        new C(),
    };

    for (int i = 0; i < 4; i++)
    {
        identify(*objs[i]);
        identify(objs[i]);
        std::cout << std::string(50, '-') << std::endl;
        delete objs[i];
    }

    {
        std::cout << "\tGenerate function with pointer : " << std::endl;
        Base *a = generate();
        identify(a);
        delete a;
        std::cout << std::string(50, '-') << std::endl;
    }
    {
        std::cout << "\tGenerate function with reference : " << std::endl;
        Base &a = *generate();
        identify(a);
        delete &a;
        std::cout << std::string(50, '-') << std::endl;
    }
    return 0;
}
