#include <iostream>
#include <limits>

int main(int argc, char *argv[])
{
    float _value = 2147483648;
    bool  a      = _value > std::numeric_limits<int>::max() ||
             _value < std::numeric_limits<int>::min();

    std::cout << a << std::endl;
    return 0;
}
