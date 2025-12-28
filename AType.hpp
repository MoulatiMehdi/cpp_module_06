#ifndef A_TYPE_HPP
#define A_TYPE_HPP

#include <string>

class AType
{
  public:
    enum State
    {
        Error,
        Pass
    };

    AType(const std::string &str);
    AType(const AType &other);
    virtual ~AType();

    State        getState() const;

    virtual void convert() const = 0;

  protected:
    const std::string &_str;
    State              _state;

  private:
    static const std::string DEFAULT;
    AType();
    AType &operator=(const AType &other);
};

#endif
