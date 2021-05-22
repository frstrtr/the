#include <iostream>
using namespace std;

class Base
{
    int v;

public:
    Base(int value) : v(value) {}
    operator int() const
    {
        return v;
    }
};

class A : public Base
{
public:
    A(int value) : Base(value * 10) {}
};

int main()
{
    A a(322);
    int _a = a;
    cout << _a << endl;
}