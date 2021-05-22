#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    // uint64_t a = 12750863378945658756;
    // unsigned long long b = 12750863378945658756;
    // cout << a << " == " << b << " is " << a == b << "\n";

    string str_a = "12750863378945658756";
    stringstream ss;
    ss << str_a;
    unsigned long long a;
    ss >> a;
    cout << a << endl;
    cout << UINT64_MAX << endl;
    cout << (a < UINT64_MAX) << endl;
    

    u_int64_t b = a;
    cout << b << endl;
    unsigned long long b_a = b;
    cout << b_a << endl;
}