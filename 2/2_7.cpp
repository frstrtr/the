#include <iostream>

class A;
class Interface
{
private:
    A *_a;

public:
    Interface(A *a) : _a(a)
    {
    }

    Interface(Interface &I) : _a(I._a)
    {
    }

    int get_value();
};

class A : public Interface
{
public:
    int value;

public:
    A(int _v) : Interface(this)
    {
        value = _v;
    }
    A(Interface I) : Interface(I)
    {
    }
};

int Interface::get_value()
{
    return _a->value;
}

int main()
{
    A *a = new A(1337);
    A *a2 = new A(a);

    std::cout << "a: value = " << a->get_value() << std::endl;
    std::cout << "a2: value = " << a2->get_value() << std::endl;

    a->value *= 10;

    std::cout << "a: value = " << a->get_value() << std::endl;
    std::cout << "a2: value = " << a2->get_value() << std::endl;
}