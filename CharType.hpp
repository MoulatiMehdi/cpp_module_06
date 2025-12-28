#ifndef CHAR_TYPE_HPP
#define CHAR_TYPE_HPP

#include "AType.hpp"
#include <string>

class CharType : public AType
{
  private:
    char _value;

  public:
    CharType(const std::string &str);
    CharType(const CharType &other);
    ~CharType();

    void updateState();
    void convert() const;

  private:
    CharType();
    CharType &operator<<(const CharType &other);
};

#endif
