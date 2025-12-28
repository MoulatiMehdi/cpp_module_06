#ifndef FLOAT_TYPE_HPP
#define FLOAT_TYPE_HPP

#include "AType.hpp"
#include <string>

class FloatType : public AType
{
  private:
    float _value;
    bool  _isPseudo;

  public:
    FloatType(const std::string &str);
    FloatType(const FloatType &other);
    ~FloatType();

    void convert() const;
    bool isValid() const;

    static bool isPseudo(const std::string &str);

  private:
    FloatType();
    FloatType &operator<<(const FloatType &other);
};

#endif
