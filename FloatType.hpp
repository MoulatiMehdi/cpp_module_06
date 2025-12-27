#include "AType.hpp"
#include <string>

class FloatType : public AType
{
  private:
    double _value;

  public:
    FloatType(const std::string &str);
    FloatType(const FloatType &other);
    ~FloatType();

    void convert();
    bool isPseudo();
    bool isValid();

  private:
    void updateState();
    FloatType();
    FloatType &operator<<(const FloatType &other);
};
