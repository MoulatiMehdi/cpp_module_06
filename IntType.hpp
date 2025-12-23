#include "AType.hpp"
#include <string>

class IntType : AType
{
  private:
    int _value;

  public:
    IntType(const std::string &str);
    IntType(const IntType &other);
    ~IntType();

    bool isValid();
    void convert();

  private:
    IntType();
    IntType &operator<<(const IntType &other);
};


