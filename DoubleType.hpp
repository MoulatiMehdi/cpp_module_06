#include "AType.hpp"
#include <string>

class DoubleType : AType
{
  private:
    int _value;

  public:
    DoubleType(const std::string &str);
    DoubleType(const DoubleType &other);
    ~DoubleType();

    void updateState();
    void convert();

  private:
    DoubleType();
    DoubleType &operator<<(const DoubleType &other);
};
