#include <iostream>
#include <memory>
using namespace std;

#include <boost/function.hpp>
#include <boost/bind.hpp>

class Arg
{
public:
    Arg(int _a){
        a = _a;
    }

    int a;
};

typedef boost::function<bool(std::shared_ptr<Arg>)> protocol_handle;

class Functor
{
public:
    protocol_handle handle;

    Functor(protocol_handle _handle) : handle(std::move(_handle)) {

    }

    void test_functor(){
        shared_ptr<Arg> arg = make_shared<Arg>(1337);
        handle(arg);
    }
};

class Main
{

public:
    bool func(std::shared_ptr<Arg> arg)
    {
        cout << "Arg->a = " << arg->a << endl;;
        return true;
    }
};

int main()
{
    cout << "start" << endl;
    shared_ptr<Main> _m = make_shared<Main>();
    //auto x = boost::bind(&Main::func, _m.get(), _1);
    protocol_handle x = [_m](shared_ptr<Arg> arg){_m->func(arg); return true;};
    shared_ptr<Functor> functor = make_shared<Functor>(std::move(x));
    shared_ptr<Arg> arg = make_shared<Arg>(1337);
    cout << "call handle" << endl;
    //functor->handle(arg);

    functor->test_functor();

}