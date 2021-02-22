#include <iostream>
#include <memory>
using namespace std;

class A
{
public:
    int i = 0;
    A(int _i)
    {
        i = _i;
    }
    A(shared_ptr<A> _a)
    {
        i = _a->i + 1000;
    }
};

int main()
{
    shared_ptr<A> _a1 = make_shared<A>(1337);
    cout << _a1->i << endl;
    _a1 = make_shared<A>(_a1);
    cout << _a1->i << endl;
}