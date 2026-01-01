#ifndef DOUBLE_TYPE_HPP
#define DOUBLE_TYPE_HPP

#include "AType.hpp"
#include <string>

class DoubleType : public AType
{
  private:
    double _value;
    bool   _isPseudo;

  public:
    DoubleType(const std::string &str);
    DoubleType(const DoubleType &other);
    ~DoubleType();

    void convert() const;
    bool isValid() const;

    static bool isPseudo(const std::string &str);

  private:
    void updateState();
    DoubleType();
    DoubleType &operator<<(const DoubleType &other);
};

#endif
