#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>

class TypeConverter
{
  private:
    TypeConverter();
    TypeConverter(const std::string &str);
    TypeConverter(const TypeConverter &other);
    ~TypeConverter();
    TypeConverter &operator=(const TypeConverter &other);

  public:
    enum Type
    {
        Char,
        Int,
        Float,
        Double,
        Pseudo,
        Unknown
    };

    enum State
    {
        Invisible,
        Error,
        Ok
    };

    typedef struct
    {
        bool (*func)(const std::string &str);
        Type type;
    } TypeAction;

    static void error(const std::string &label, const State state);
    static bool isChar(const std::string &str);
    static bool isDouble(const std::string &str);
    static bool isInt(const std::string &str);
    static bool isFloat(const std::string &str);
    static Type getLiteralType(const std::string &str);
    static void convertToAllTypes(const std::string &str);
    static bool isPseudo(const std::string &str);
};

#endif
