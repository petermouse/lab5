#include <iostream>
#include <vector>
#include <string>
class HugeInt
{
    public:
    HugeInt(long long int =0);
    HugeInt(std::string);
    HugeInt(short int ,std::vector<short int>) ;
    HugeInt operator+(const HugeInt &)const;
    HugeInt operator-(const HugeInt &)const;
    std::vector<short int> getData() const;
    void setData(long long int);
    short int getSign() const;
    friend std::ostream & operator<<(std::ostream &output,const HugeInt &);
    friend std::istream & operator>>(std::istream &input,HugeInt &);
    private:

    std::vector<short int> data;
    short int sign;
};
