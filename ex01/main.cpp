#include "Serializer.hpp"
#include <iostream>
#include <stdint.h>

int main()
{
    Data a(100);

    uintptr_t     a_raw = Serializer::serialize(&a);
    long          b_raw = reinterpret_cast<long>(&a);
    unsigned long c_raw = reinterpret_cast<unsigned long>(&a);


    Data *a_ptr = Serializer::deserialize(a_raw);
    Data *b_ptr = reinterpret_cast<Data *>(b_raw);
    Data *c_ptr = reinterpret_cast<Data *>(c_raw);
    //

    std::cout << &a << std::endl;
    std::cout << a_ptr << std::endl;
    std::cout << b_ptr << std::endl;
    std::cout << c_ptr << std::endl;

    return 0;
}
