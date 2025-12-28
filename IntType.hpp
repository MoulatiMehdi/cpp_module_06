#ifndef INT_TYPE_HPP
#define INT_TYPE_HPP

#include "AType.hpp"
#include <string>

class IntType : public AType
{
  private:
    int _value;

  public:
    IntType(const std::string &str);
    IntType(const IntType &other);
    ~IntType();

    void updateState();
    void convert();

  private:
    IntType();
    IntType &operator<<(const IntType &other);
};

#endif
