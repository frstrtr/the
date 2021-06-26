#include <iostream>
#include <map>
using namespace std;

void PrintMap(const char* name, map<int, int> &m){
    cout << "Name [" << name << "]: ";
    for (auto v : m)
    {
        cout << v.first << ":" << v.second << "; ";
    }
    cout << endl;
}

int main()
{
    map<int, int> a = {{1, 2}, {2, 3}};
    PrintMap("a", a);
    map<int, int> b_for_copy = {{3, 4}, {2, 1}};
    map<int, int> b = b_for_copy;
    PrintMap("b", b);
    map<int, int> c;
    PrintMap("c", c);
    cout << endl;

    c.merge(a);
    PrintMap("a->c[a]", a);
    PrintMap("a->c[c]", c);
    cout << endl;

    c.merge(b);
    PrintMap("b->c[a]", a);
    PrintMap("b->c[b]", b);
    PrintMap("b->c[c]", c);

    PrintMap("b_for_copy", b_for_copy);
}