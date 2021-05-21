#include <iostream>
#include <string>
using namespace std;

class Base
{
protected:
    const int version;

    Base(int ver) : version(ver) {}

public:
    virtual void Deserialize(string json) = 0;
};

class A : public Base
{
    int value;

public:
    //VERSION = 1
    A() : Base(1) {}

    void Deserialize(string json) override { /*...*/ }
};

class B : public Base
{
    float value;

public:
    //VERSION = 16
    B() : Base(16) {}

    void Deserialize(string json) override { /*...*/ }
};

class version{
    public:
    const int v;

    version(int ver) : v(ver) {}
};

template<int N>
Base* createX(string json) = delete;

template<>
Base* createX<1>(string json) {
    return new A();
}

template<>
Base* createX<16>(string json) {
    return new B();
}

// Base *create_obj(int version, string json)
// {
//     Base* result;
//     switch (version)
//     {
//     case 1:
//         result = new A();
//         break;
//     case 16:
//         result = new B();
//         break;
    
//     default:
//         //ERROR
//         break;
//     }
//     return result;
// }

int main()
{
    string json = "example_json";
    int v = 16;
    const int want_version = version(v).v;

    //Error: ‘want_version’ was not initialized with a constant expression
    //Base* obj = createX<want_version>(json);
}