#include <string>

class AType
{
  public:
    enum State
    {
        Error,
        Hidden,
        Pass
    };

    void msg(const std::string &label, const State &state);

    AType();
    AType(const std::string &str);
    AType(const AType &other);
    ~AType();

    virtual void convert()     = 0;
    virtual void updateState() = 0;

    void error();

  protected:
    const std::string &_str;
    State              _state;

  private:
    static const std::string DEFAULT;
    AType                   &operator=(const AType &other);
};
