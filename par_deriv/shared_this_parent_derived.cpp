#include <iostream>
#include <memory>
using namespace std;

class A
{
    int _i;

public:
    A(int i) : _i(i) {}

    void debug()
    {
        cout << this->_i << endl;
    }
};

class B : public A
{
    int _i2;

public:
    B(int i) : A(i), _i2(i + 100) {}

    void debug2()
    {
        cout << this->_i2 << endl;
    }
};

int main()
{
    B *b1 = new B(322);
    shared_ptr<B> b2 = make_shared<B>(1337);

    b1->debug();
    b1->debug2();
    b2->debug();
    b2->debug2();
}