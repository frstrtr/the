#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <deque>
#include <queue>
#include "share.h"
#include <chrono>
#include <thread>
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
        return element;
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
            sum[_share->hash] = new_sum_element;
            new_sum_element.prev->second.nexts.push_back(sum.find(_share->hash));
        }
        else
        {
            sum[_share->hash] = new_sum_element;
        }
    }

#define set_cur_it(new_value) \
    cur_it = new_value;       \
    cur_it_nexts = cur_it->second.nexts

#define get_q() \
    q.front();  \
    q.pop()

    void remove(int hash)
    {
        //TODO: throw if hash not exists in items;
        auto _share = items[hash];
        items.erase(hash);

        queue<map<int, element_type>::iterator> q;
        auto remover = sum[hash];

        auto cur_it = sum.find(hash);
        auto &cur_it_nexts = cur_it->second.nexts;

        if (remover.nexts.empty())
        {
            cur_it = sum.end();
        }
        else
        {
            for (auto item : cur_it_nexts)
            {
                item->second.prev = remover.prev;
                q.push(item);
            }
            auto new_it = get_q();
            set_cur_it(new_it);
        }
        //добавлять все nexts в текущей cur_it в q и проходить их.
        while (!q.empty() || (cur_it != sum.end()))
        {
            if (cur_it != sum.end())
            {
                cur_it->second -= remover;
                for (auto item : cur_it_nexts)
                {
                    q.push(item);
                }
            }
            if (!q.empty())
            {
                auto new_it = get_q();
                set_cur_it(new_it);
            }
            else
            {
                break;
            }
        }
        sum.erase(hash);
    }
#undef set_cur_it
#undef get_q

    element_delta_type get_delta(int first_hash, int second_hash)
    {
        if (sum.find(first_hash) == sum.end())
        {
            throw invalid_argument("first_hash in get_delta existn't in sum!");
        }
        if (sum.find(second_hash) == sum.end())
        {
            throw invalid_argument("second in get_delta existn't in sum!");
        }

        element_delta_type fir(sum[first_hash]);
        element_delta_type sec(sum[second_hash]);
        return fir - sec;
    }

    int get_last(int hash)
    {
        auto _it = sum.find(hash);
        if (_it == sum.end())
        {
            throw invalid_argument("[get_last] hash not exists in sum");
        }
        cout << _it->second.element;
        auto last = _it->second.prev_hash();
        while (_it != sum.end())
        {
            _it = _it->second.prev;
            last = _it->second.prev_hash();
            // this_thread::sleep_for(chrono::milliseconds(1));
        }
        return last;
    }

    element_delta_type get_delta_to_last(int hash)
    {
        auto el = sum.find(hash);
        if (el == sum.end())
        {
            throw invalid_argument("[get_delta_to_last] hash not exists in sum");
        }
        element_delta_type delta(el->second);
        delta.tail = get_last(hash);
        return delta;
    }

    //todo: remove range
};

#define get_delta_time(t1, t2) \
    float(std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()) / 1000000 << " seconds."

#define start_timer() \
    t1 = std::chrono::high_resolution_clock::now()

#define end_timer(text)                             \
    t2 = std::chrono::high_resolution_clock::now(); \
    std::cout << text << " time: " << get_delta_time(t1, t2) << endl

void first_test()
{
    //vector of pointers for shares
    vector<share *> shares;
    for (int i = 1; i < 100; i++)
    {
        shares.push_back(new share(i, i - 1, i * 10));
    }

    //init tracker
    auto t1 = std::chrono::high_resolution_clock::now();
    prefsum tracker;
    for (auto item : shares)
    {
        tracker.add(item);
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "time delay = " << get_delta_time(t1, t2) << endl;

    cout << tracker.sum[90].height << " " << tracker.sum[90].work << endl;

    //get delta [90, 58)
    auto delta = tracker.get_delta(90, 58);
    cout << delta.height << " " << delta.work << endl;

    tracker.remove(95);
    delta = tracker.get_delta(90, 58);
    cout << delta.height << " " << delta.work << endl;

    t1 = std::chrono::high_resolution_clock::now();
    tracker.remove(77);
    delta = tracker.get_delta(90, 58);
    cout << delta.height << " " << delta.work << endl;
    t2 = std::chrono::high_resolution_clock::now();
    std::cout << "time delay = " << get_delta_time(t1, t2) << endl;

    t1 = std::chrono::high_resolution_clock::now();
    for (int i = 78; i < 89; i++)
    {
        tracker.remove(i);
    }
    delta = tracker.get_delta(90, 58);
    cout << delta.height << " " << delta.work << endl;
    t2 = std::chrono::high_resolution_clock::now();
    std::cout << "time delay = " << get_delta_time(t1, t2) << endl;

    //added 900 shares to tracker
    cout << "Starting adding 900 shares..." << endl;
    t1 = std::chrono::high_resolution_clock::now();
    for (auto i = 100; i < 1000; i++)
    {
        share *item = new share(i, i - 1, i * 10);
        tracker.add(item);
    }
    t2 = std::chrono::high_resolution_clock::now();
    std::cout << "time delay = " << get_delta_time(t1, t2) << endl;
    cout << "                   ...finish!" << endl;

    //going from best to last
    cout << "Starting going for 1000 shares..." << endl;
    t1 = std::chrono::high_resolution_clock::now();
    auto it_going1000 = tracker.sum[999].prev;
    while (it_going1000 != tracker.sum.end())
    {
        cout << it_going1000->second.hash() << " ";
        it_going1000 = it_going1000->second.prev;
        // this_thread::sleep_for(chrono::milliseconds(1));
    }
    t2 = std::chrono::high_resolution_clock::now();
    std::cout << "time delay = " << get_delta_time(t1, t2) << endl;
    cout << "                   ...finish!" << endl;

    //Get delta_last for 999
    cout << "Get delta_last for 999\n";
    t1 = std::chrono::high_resolution_clock::now();
    auto delta_last999 = tracker.get_delta_to_last(5);
    cout << delta_last999.head << " " << delta_last999.tail << " " << delta_last999.height << " " << delta_last999.work << endl;
    t2 = std::chrono::high_resolution_clock::now();
    std::cout << "time delay = " << get_delta_time(t1, t2) << endl;
    cout << "                   ...finish!" << endl;

    //removed 900 shares in tracker
    cout << "Starting removing 900 shares..." << endl;
    t1 = std::chrono::high_resolution_clock::now();
    for (auto i = 100; i < 1000; i++)
    {
        tracker.remove(i);
    }
    t2 = std::chrono::high_resolution_clock::now();
    std::cout << "time delay = " << get_delta_time(t1, t2) << endl;
    cout << "                   ...finish!" << endl;
}

void second_test()
{
    //vector of pointers for shares
    vector<share *> shares;
    for (int i = 1; i < 10; i++)
    {
        shares.push_back(new share(i, i - 1, i * 10));
    }

    std::chrono::_V2::system_clock::time_point t1;
    std::chrono::_V2::system_clock::time_point t2;

    //init tracker
    start_timer();
    prefsum tracker;
    for (auto item : shares)
    {
        tracker.add(item);
    }
    end_timer("Adding in tracker");

    //remove test
    start_timer();
    tracker.remove(7);
    cout << "removed 7" << endl;
    auto delta = tracker.get_delta(9, 4);
    cout << "get_delta(9, 4): " << delta.height << " " << delta.work << endl;
    end_timer("Removing element 7 and get_delta(9,4)");

    //test curent chain
    {
        auto _it = tracker.sum.find(9);
        while (_it != tracker.sum.end()){
            cout << _it->second.hash() << ":" << _it->second.prev_hash() << " ";
            _it = _it->second.prev;
        }
        cout << endl;
    }
}

int main()
{
    //first_test();
    second_test();
}