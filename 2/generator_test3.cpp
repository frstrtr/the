#include <iostream>
#include <map>
#include <vector>
#include <boost/function.hpp>
using namespace std;

#define DEBUG(x) \
    cout << "test" << x << endl;

int main()
{
    map<int, int> d = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}};
    boost::function<bool(int &ref)> generator = [&](int key, int end_key)
    {
        auto _cur = d.find(key);
        auto _end_k = d.find(end_key);
        auto &_d = d;
        if (_end_k == d.end())
        {
            _cur = d.end();
        }

        return [=, &_d](int &ref) mutable
        {
            if ((_cur != _d.end()) && (_cur != _end_k))
            {
                ref = _cur->second;
                _cur = _d.find(_cur->first - 1);

                return true;
            }
            else
            {
                return false;
            }
        };
    }(5, 2);

    int ref;
    while (generator(ref))
    {
        cout << ref << " ";
    }
    cout << endl;
}