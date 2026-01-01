#include "Data.hpp"
#include <string>

Data::Data() : name("unknown"), age(0)
{
}

Data::Data(const std::string &name, int value) : name(name), age(value)
{
}

Data::Data(const Data &other) : name(other.name), age(other.age)
{
}

Data &Data::operator=(const Data &other)
{
    if (this == &other)
        return *this;
    age  = other.age;
    name = other.name;
    return *this;
}

Data::~Data()
{
}

int Data::getAge() const
{
    return age;
}

const std::string Data::getName() const
{
    return name;
}
