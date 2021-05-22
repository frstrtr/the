#include <memory>
#include <iostream>
using namespace std;

class base
{
public:
    virtual void print() = 0;
};

class A : base
{
    int a;

public:
    A(int _a) : a(_a) {}

    void print() override
    {
        cout << a << endl;
    }
};

class B : base
{
    float b;

public:
    B(float _b) : b(_b) {}

    void print() override
    {
        cout << b << endl;
    }
};

template <class T, class... Args>
shared_ptr<T> make_obj(Args &&...args)
{
    auto res = make_shared<T>(args...);
    return res;
}

int main()
{
    auto _a = make_obj<A>(1);
    _a->print();
    auto _b = make_obj<B>(123.232);
    _b->print();
}