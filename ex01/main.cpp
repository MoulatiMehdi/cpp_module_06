#include "Serializer.hpp"
#include <iostream>
#include <stdint.h>

int main()
{
    Data a(100);

    uintptr_t a_raw = Serializer::serialize(&a);
    Data     *a_ptr = Serializer::deserialize(a_raw);

    if (&a == a_ptr)
        std::cout << "same pointer" << std::endl;
    else
        std::cout << "not the same pointer" << std::endl;

    return 0;
}
