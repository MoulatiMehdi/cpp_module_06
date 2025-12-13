#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>

class ScalarConverter
{
  public:
    static void convert(const std::string &str);

  private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ~ScalarConverter();
    ScalarConverter &operator=(const ScalarConverter &other);
};

#endif
