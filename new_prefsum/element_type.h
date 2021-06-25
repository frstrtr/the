#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <deque>
using namespace std;

class share;

class element_type
{
public:
    map<int, element_type>::iterator prev;
    vector<map<int, element_type>::iterator> nexts;
    share *element;

    int32_t height;
    int32_t work;

public:
    element_type() {}
    element_type(share *_share)
    {
        element = _share;
        work = _share->work;
        height = 1;
    }

    int hash();
    int prev_hash();

    element_type operator+(const element_type &element)
    {
        element_type res = *this;
        res.work += element.work;
        res.height += element.height;
        return res;
    }

    element_type operator+(const element_type &element)
    {
        element_type res = *this;
        res.work -= element.work;
        res.height -= element.height;
        return res;
    }

    element_type operator+=(const element_type &element)
    {
        this->work += element.work;
        this->height += element.height;
        return *this;
    }

    element_type operator+=(const element_type &element)
    {
        this->work -= element.work;
        this->height -= element.height;
        return *this;
    }

    // static element_type get_null(){}
};