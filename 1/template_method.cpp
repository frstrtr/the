#include <iostream>
#include <memory>
using namespace std;

class BaseValue
{
public:
    virtual void print() = 0;
};

class AValue : public BaseValue
{
    int i;

public:
    void set_value(int _i)
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
    void set_value(float _i)
    {
        i = _i;
    }
    void print()
    {
        cout << i << endl;
    }
};

class Base
{
    shared_ptr<BaseValue> value;

public:
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

template <class value_type>
class MainClass
{
public:
    template <class T>
    shared_ptr<T> GenerateBase(float f)
    {
        shared_ptr<T> res = make_shared<T>();
        res->set_value_type<value_type>();
        res->set_value(f);
    }
};

int main()
{
    MainClass<AValue> m_A;
    auto _a = m_A.GenerateBase<A>(11);

    
    MainClass<BValue> m_B;
    auto _b = m_B.GenerateBase<B>(1337);

}