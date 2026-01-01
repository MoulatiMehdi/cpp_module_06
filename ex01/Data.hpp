#include <string>

struct Data
{
  private:
    std::string name;
    int         age;

  public:
    Data();
    Data(const std::string &name, int value);
    Data(const Data &other);
    Data &operator=(const Data &other);
    ~Data();

    const std::string getName() const;
    int               getAge() const;
};
