#include <memory>
#include <iostream>
using namespace std;

class Base
{
public:
    template<class T>
    Base(){

    }
};

int main()
{
    // std::shared_ptr<Base> var = std::make_shared<Base>()<int>;
}