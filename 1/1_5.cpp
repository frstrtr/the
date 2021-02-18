#include <iostream>
#include <memory>
using namespace std;

class mainSub
{
public:
    virtual int getNum() = 0;
};

class subA : public mainSub
{
public:
    int getNum() override
    {
        return 1337;
    }
};

class subB : public mainSub
{
public:
    int a = 1;

    int getNum() override
    {
        return a;
    }
};

template <class subType>
class Base
{
    public:
    Base(){
        sub = make_shared<subType>();
    }
    shared_ptr<mainSub> sub;
};

#define A Base<subA>
#define B Base<subB>

int main()
{
    shared_ptr<A> test_a = make_shared<A>();
    shared_ptr<B> test_b = make_shared<B>();
    cout << test_b->sub->getNum() << endl;
}