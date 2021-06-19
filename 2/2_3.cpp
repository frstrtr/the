#include <iostream>
#include <iterator>
#include <algorithm>
#include <deque>
#include <map>
#include <random>
using namespace std;

template <typename T>
void F(T v)
{
    map<int, typename map<int, T>::iterator> _reverse;
    map<int, T> _map;
    int k = 100;
    _map[k] = v;

    _reverse[k] = _map.find(k);

    T res = _reverse[k]->second;

    cout << res  << endl;
}

int main()
{
    // deque<int> q;
    // q.push_back(1);
    // q.push_back(2);
    // q.push_back(3);

    // cout << "q distance begin-end = " << distance(q.begin(), q.end()) << endl;
    // cout << "q distance end-begin = " << distance(q.end(), q.begin()) << endl;

    map<int, int> m = {{1, 1}, {3, 3}, {4, 4}, {5, 5}};
    //m.erase(2);
    m[2] = 2;

    cout << "m[1:5]" << distance(m.find(1), m.find(9)) << endl;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << "value: " << it->first << " " << it->second << endl;
    }

    F<int>(1337);
}