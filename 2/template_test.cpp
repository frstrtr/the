#include <iostream>
#include "template_test.h"
using namespace std;

template <typename T>
void test::testF(T v)
{
    cout << v << endl;
}

int main()
{
    //testF<int>(10);
}