#include "DoubleType.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
        return -1;

    DoubleType a(argv[1]);

    a.convert();
}
