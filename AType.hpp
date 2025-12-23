#include <sstream>
#include <string>

class AType
{

  public:
    enum Type
    {
        Int,
        Char,
        Float,
        Double,
        Pseudo
    };

    enum State
    {
        Error,
        Hidden,
        Pass
    };

    static const std::string DEFAULT;
    static void              msg(const std::string &label, const State &state);

    AType();
    AType(const std::string &str);
    AType(const AType &other);
    ~AType();

    virtual bool isValid() = 0;
    virtual void convert() = 0;
    virtual void updateState();

  protected:
    const std::string &_str;
    std::istringstream _iss;
    State              _state;

  private:
    AType &operator=(const AType &other);
};
