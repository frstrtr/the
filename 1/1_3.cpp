#include <iostream>
#include <memory>
using namespace std;

template <typename type>
class Base
{
private:
    type value;

public:
    Base(type _value) : value(_value)
    {
    }

    void Print()
    {
        cout << value << endl;
    }
};

template <typename type>
class A : public Base<type>
{
    A(type _value) : Base<type>(_value)
    {
    }
};

template <typename type>
class B : public Base<type>
{
    B(type _value) : Base<type>(_value)
    {
    }
};

template <typename type>
void FA(shared_ptr<A<type>> msg)
{
}

template <typename type>
void FB(shared_ptr<B<type>> msg)
{
}

int main()
{
}