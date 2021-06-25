#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <boost/function.hpp>
#include <thread>
using namespace std;

typedef map<int, int> map_type;
typedef map_type::iterator it_type;

int main()
{
    map_type m = {{1, 2}, {2, 3}};
    list<int> keys = {1, 2, 3, 4, 5};

    boost::function<it_type()> generator = [&](list<int> _keys)
    {
        it_type res;
        return [=, &m]() mutable
        {
            if (!_keys.empty())
            {
                auto key = _keys.front();
                _keys.pop_front();
                return m.find(key);
            }
            else
            {
                _keys.pop_front();
                return m.end();
            }
        };
    }(keys);

    it_type ref;
    while ((ref = generator()) != m.end())
    {
        cout << ref->second << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }

    cout << "\nkeys:\n";
    for (auto i : keys)
    {
        cout << i << " ";
    }
}