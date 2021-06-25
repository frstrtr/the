#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <deque>
#include <queue>
#include "share.h"
#include "element_type.h"
using namespace std;

class prefsum
{
public:
    map<int, share *> items;
    map<int, element_type> sum;

protected:
    element_type make_element(share *_share)
    {
        element_type element(_share);
        element.prev = sum.find(_share->prev_hash);
    }

public:
    void add(share *_share)
    {
        //TODO: throw if share exists in items;
        items[_share->hash] = _share;

        element_type new_sum_element = make_element(_share); //only this element
        if (new_sum_element.prev != sum.end())
        {
            new_sum_element += new_sum_element.prev->second;
        }
        sum[_share->hash] = new_sum_element;
    }

    void remove(int hash)
    {
        //TODO: throw if hash not exists in items;
        auto _share = items[hash];
        items.erase(hash);

        queue<map<int, element_type>::iterator> q;
        auto cur_it = 
        if ()
         = sum[hash].nexts.empty() ? sum.end() : {sum[hash].nexts[0]};

        while (!q.empty() || (cur_it != sum.end()))
        {
            cu
        }
    }

    //todo: remove range
};

int main()
{
}