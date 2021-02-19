#include <iostream>
#include <memory>
using namespace std;
class B;

class A
{
public:
    shared_ptr<B> value;
    int num = 1;
};

class B
{
public:
    weak_ptr<A> value;
    int num = 2;
};

int main()
{
    shared_ptr<A> a = make_shared<A>();
    {
        shared_ptr<B> b = make_shared<B>();
        a->value = b;
    }
    
    a->value->value = a;
    cout << a->value->num << endl;
    cout << a->value->value.lock()->num << endl;

    a->value->value.reset();

    cout << a->value->num << endl;
    cout << a->value->value.lock()->num << endl;
}