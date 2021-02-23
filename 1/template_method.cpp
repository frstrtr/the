#include <iostream>
#include <memory>
using namespace std;

class BaseValue
{
public:
    virtual void print() = 0;

    virtual void set_value(int i) = 0;
};

class AValue : public BaseValue
{
    int i;

public:
    void set_value(int _i) override
    {
        i = _i;
    }
    void print()
    {
        cout << i << endl;
    }
};
class BValue : public BaseValue
{
    float i;

public:
    void set_value(int _i) override
    {
        i = _i + 0.4;
    }
    void print()
    {
        cout << i << endl;
    }
};

class Base
{

public:
    shared_ptr<BaseValue> value;

    template <class type>
    void set_value_type()
    {
        value = make_shared<type>();
    }
};

class A : public Base
{
};
class B : public Base
{
};

class MainClass
{
public:
    template <class T, class T2>
    shared_ptr<T> GenerateBase(float f)
    {
        shared_ptr<T> res = make_shared<T>();
        res->template set_value_type<T2>();
        res->value->set_value(f);
        return res;
    }
};

int main()
{
    MainClass m;
    auto _a = m.GenerateBase<A, AValue>(11);
    _a->value->print();
    auto _b = m.GenerateBase<B, BValue>(1337);
    _b->value->print();
}