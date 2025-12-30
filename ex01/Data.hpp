class Data
{
  private:
    int _value;

  public:
    Data();
    Data(int value);
    Data(const Data &other);
    Data &operator=(const Data &other);
    ~Data();
};
