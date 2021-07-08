#include <iostream>
using namespace std;

class A
{
protected:
    int a;

public:
    A() : a(0) {}
    A(int _a) : a(_a) {}

    operator int()
    {
        return a;
    }

    A &operator=(int v)
    {
        a = v;
    }
};

class B : public A
{
    int b;

public:
    B() : A(), b(0) {}
    B(A _a, int _b) : A(_a), b(_b) {}

    operator int()
    {
        return A::operator int() + b;
    }
    
    B &operator=(int v)
    {
        A::operator=(v);
        b = v;
        return *this;
    }
};

int main()
{
    A a(100);
    cout << int(a) << endl;

    B b(a, 1);
    cout << int(b) << endl;

    B b2;
    b2 = 100;
    cout << int(b2) << endl;
}