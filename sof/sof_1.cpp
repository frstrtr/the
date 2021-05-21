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

Base *create_obj(int version, string json)
{
    Base* result;
    switch (version)
    {
    case 1:
        result = new A();
        break;
    case 16:
        result = new B();
        break;
    
    default:
        //ERROR
        break;
    }
    return result;
}

int main()
{
    string json = "example_json";
    int want_version = 16;

    Base* obj = create_obj(16, json);
}