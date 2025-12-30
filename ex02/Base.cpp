#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>

Base::~Base()
{
}

Base *generate(void)
{
    int num = rand() % 3;

    switch (num)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        default:
            return new C();
    }
}

void identify(Base *p)
{
    std::string name = "Base";

    if (dynamic_cast<A *>(p))
        name = "A";
    else if (dynamic_cast<B *>(p))
        name = "B";
    else if (dynamic_cast<C *>(p))
        name = "C";
    std::cout << "Object Type is : Pointer to " << name << std::endl;
}

void identify(Base &p)
{
    std::string name = "Base";
    try
    {
        (void)dynamic_cast<A &>(p);
        name = "A";
    }
    catch (...)
    {
    }
    try
    {
        (void)dynamic_cast<B &>(p);
        name = "B";
    }
    catch (std::exception &e)
    {
    }
    try
    {
        (void)dynamic_cast<C &>(p);
        name = "C";
    }
    catch (std::exception &e)
    {
    }
    std::cout << "Object Type is : Reference to " << name << std::endl;
}
