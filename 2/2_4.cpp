#include <iostream>


class Base
{
public:
    virtual int get_i() = 0;
};

class A : public Base
{
public:
    int get_i() override
    {
        return 7331;
    }
};

class B
{
public:
    int get_i()
    {
        return 1337;
    }
};

template <typename T, typename = typename std::enable_if<std::is_base_of<Base, T>::value>::type, typename K>
void F(T v, K k)
{
    std::cout << v.get_i() << std::endl;
    std::cout << k << std::endl;
}

int main()
{
    A a;
    B b;

    F(a, 100);
    // F(b); //ERROR!
}