#include <iostream>
#include <memory>
using namespace std;

class A
{
public:
    int i;

    A(int _i) : i(_i)
    {
    }

    // operator int(){
    //     return;
    // }
};

int main()
{
    shared_ptr<A> a = make_shared<A>(13378);
}