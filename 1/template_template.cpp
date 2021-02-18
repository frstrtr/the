#include <iostream>
#include <memory>
#include <string>
using namespace std;

template <class T>
class A
{
public:
    T a;

    A(T _a) {
        a = _a;
    }

    void debug()
    {
        cout << a << endl;
    }
};

template <class T>
class B
{
public:
    T b;

    B(T _b) {
        b = _b;
    }

    void debug()
    {
        cout << b << endl;
    }
};

template <class a_T>
class Converter
{
public:
    template <template <class> class MsgType>
    shared_ptr<MsgType<a_T>> generate_msg(a_T arg)
    {
        shared_ptr<MsgType<a_T>> msg = make_shared<MsgType<a_T>>(arg);
        return msg;
    }
};

int main()
{
    Converter<int> converter;
    Converter<string> converter2;

    converter.generate_msg<B>(12)->debug();
    converter.generate_msg<A>(567)->debug();
    converter2.generate_msg<A>("test")->debug();
}