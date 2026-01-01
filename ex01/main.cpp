#include "Serializer.hpp"
#include <iostream>
#include <stdint.h>

int main()
{
    Data a("bob", 18);

    uintptr_t a_raw = Serializer::serialize(&a);
    Data     *a_ptr = Serializer::deserialize(a_raw);

    if (&a != a_ptr)
    {
        std::cout << "not the same pointer" << std::endl;
        return -1;
    }
    std::cout << "same pointer" << std::endl;
    std::cout << "\tname : " << a_ptr->getName() << std::endl;
    std::cout << "\tage  : " << a_ptr->getAge() << std::endl;
    return 0;
}
