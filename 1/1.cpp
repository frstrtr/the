#include <iostream>
using namespace std;

class A
{
public:
    int i = 0;
};

class subA
{
public:
    subA(int _i)
    {
        _a = new A();
        _a->i = _i;
    }

    operator A*()
    {
        return _a;
    }

private:
    A *_a;
};

class msg
{
public:
    void F(A *_a)
    {
        cout << _a->i << endl;
    }
};

int main()
{
    subA _SUBA(1337);
    msg MSG;
    MSG.F(_SUBA);
}