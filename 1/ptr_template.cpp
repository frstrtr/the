#include <iostream>
#include <memory>
using namespace std;

template <typename T>
class Base
{
public:
    T value;

    void debug(){
        cout << value << endl;
    }
};

template<typename T>
void F(shared_ptr<T> base){
    base->debug();
}

int main()
{
    shared_ptr<Base<int>> b = make_shared<Base<int>>();
    b->value = 100;
    F(b);
}