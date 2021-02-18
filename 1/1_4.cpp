#include <iostream>
using namespace std;


#define ECHO(F) { \
cout << "Name: " #F << endl; \
F();\
}


void test1_F()
{
}

void test2_F()
{
    cout << "TEST" << "\n";
}

//#define F(name) #name +"_F"

int main()
{
    ECHO(test2_F);
}