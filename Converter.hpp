#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>

class Converter
{
  private:
    Converter();
    Converter(const std::string &str);
    Converter(const Converter &other);
    ~Converter();
    Converter &operator=(const Converter &other);

  public:
    enum Type

    {
        Char,
        Int,
        Float,
        Double,
        Unknown
    };

    typedef struct
    {
        bool (*func)(const std::string &str);
        Type type;
    } TypeAction;

    static bool isChar(const std::string &str);
    static bool isDouble(const std::string &str);
    static bool isInt(const std::string &str);
    static bool isFloat(const std::string &str);
    static Type getLiteralType(const std::string &str);
};

#endif
