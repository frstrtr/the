#include <iostream>
#include <string>
using namespace std;


struct st1{
    int a;
    int b = 1337;
};

struct st2{
    int a;
    string str;
    st1 st;
};


class ReaderST{
    public:
    
    template <typename ST_TYPE>
    void PRINT(ST_TYPE ST);
};

template <>
void ReaderST::PRINT<st1>(st1 ST){
    cout << ST.a << " " << ST.b << endl;
}

template <>
void ReaderST::PRINT<st2>(st2 ST){
    cout << ST.a << " " << ST.str << " ";
    PRINT(ST.st);
}

int main(){
    st1 s = {12};
    cout << s.a << " " << s.b << endl;

    st2 s2 = {12,"asd", s};
    cout << s.a << " " << s.b << endl;

    ReaderST reader;
    reader.PRINT(s2);
}