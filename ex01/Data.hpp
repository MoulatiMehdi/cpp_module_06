#ifndef DATA_HPP
#define DATA_HPP

class Data
{
  private:
    int _value;

    Data();
    Data(int);
    Data(const Data &other);
    Data &operator=(const Data &other);
    ~Data();
};

#endif
