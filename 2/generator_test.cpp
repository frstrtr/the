#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <boost/function.hpp>
using namespace std;

typedef map<int, int> map_type;
typedef map_type::iterator it_type;
typedef boost::function<it_type()> get_obj;

get_obj get_generator(map_type &m, list<int> &keys)
{
    get_obj gen = [&m, &keys]()
    {
        if (!keys.empty())
        {
            int key = keys.front();
            keys.pop_front();
            return m.find(key);
        }
        return m.end();
    };

    return gen;
}

#define for_generator(generator, ref, end) \
    while ((ref = generator()) != end)

int main()
{
    map_type m = {{1,2}, {2,3}};
    list<int> keys = {1, 2, 3, 4, 5};
    get_obj gen = get_generator(m, keys);

    it_type ref;
    for_generator(gen, ref, m.end())
    {
        cout << ref->second << endl;
    }
}