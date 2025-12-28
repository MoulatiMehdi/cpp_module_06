#include "Data.hpp"

Data::Data() : _value(0)
{
}

Data::Data(int value) : _value(value)
{
}

Data::Data(const Data &other) : _value(other._value)
{
}

Data &Data::operator=(const Data &other)
{
    if (this == &other)
        return *this;
    _value = other._value;
    return *this;
}

Data::~Data()
{
}
