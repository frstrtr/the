#include <iostream>
#include <memory>
#include <cstring>
using namespace std;

#pragma pack(push, 1)
struct A
{
    int a;
    int b;
    int c;
    char str[9]; // = "hello";
};
#pragma pack(pop)

struct B
{
    int b;
    int c;
    char str[9]; // = "hello";
};


//[int(x) for x in struct.pack('<iii9s', 300, 600, 900, b'hello!!1')]
//[44, 1, 0, 0, 88, 2, 0, 0, 132, 3, 0, 0, 104, 101, 108, 108, 111, 33, 33, 49, 0]


int main()
{
    char s[] = "hello!!1";
    A a = {300, 600, 900};
    strcpy(a.str, s);
    // a.str = new char[strlen("hello")];

    // strcpy(a.str, s);//, strlen(s));
    cout << a.str << endl;
    for (int i = 0; i < strlen(a.str); i++){
        cout << (unsigned int)(((unsigned char*)a.str)[i]) << " ";
    }
    cout << endl;
    unsigned char *a_bytes = reinterpret_cast<unsigned char *>(&a);

    int len = (sizeof(a) / sizeof(*a_bytes));
    for (int i = 0; i < len; i++)
    {
        cout << (unsigned int)a_bytes[i] << " ";
    }
    cout << endl;

    cout << "len: " << (sizeof(a) / sizeof(*a_bytes)) << endl;

    cout << "==============================" << endl;


    char s2[] = "hello!!1";
    B b = {600, 900};
    strcpy(b.str, s2);
    // a.str = new char[strlen("hello")];

    // strcpy(a.str, s);//, strlen(s));
    cout << b.str << endl;
    for (int i = 0; i < strlen(b.str); i++){
        cout << (unsigned int)(((unsigned char*)b.str)[i]) << " ";
    }
    cout << endl;
    unsigned char *b_bytes_temp;
    unsigned char *b_bytes;
    b_bytes_temp = reinterpret_cast<unsigned char *>(&b);
    b_bytes = b_bytes_temp;

    int len2 = (sizeof(b) / sizeof(*b_bytes));
    for (int i = 0; i < len2; i++)
    {
        cout << (unsigned int)b_bytes[i] << " ";
    }
    cout << endl;

    cout << "len: " << (sizeof(b) / sizeof(*b_bytes)) << endl;

    //===========================================================

    B *b_unpack;
    b_unpack = (B*)b_bytes;

    cout << "unpack res: " << b_unpack->str << " " << b_unpack->b << " " << b_unpack->c << endl;
}