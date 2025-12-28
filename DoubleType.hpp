#ifndef DOUBLE_TYPE_HPP
#define DOUBLE_TYPE_HPP

#include "AType.hpp"
#include <string>

class DoubleType : public AType
{
  private:
    double _value;

  public:
    DoubleType(const std::string &str);
    DoubleType(const DoubleType &other);
    ~DoubleType();

    void convert();
    bool isPseudo();
    bool isValid();

  private:
    void updateState();
    DoubleType();
    DoubleType &operator<<(const DoubleType &other);
};

#endif
