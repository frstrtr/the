#pragma once

#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include "share.h"
using namespace std;

class element_type
{
public:
    map<int, element_type>::iterator prev;
    list<map<int, element_type>::iterator> nexts;
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

    int hash()
    {
        return element->hash;
    }
    int prev_hash()
    {
        return element->prev_hash;
    }

    element_type operator+(const element_type &element)
    {
        element_type res = *this;
        res.work += element.work;
        res.height += element.height;
        return res;
    }

    element_type operator-(const element_type &element)
    {
        element_type res = *this;
        res.work -= element.element->work;
        res.height -= 1;
        return res;
    }

    element_type operator+=(const element_type &element)
    {
        this->work += element.work;
        this->height += element.height;
        return *this;
    }

    element_type operator-=(const element_type &element)
    {
        this->work -= element.element->work;
        this->height -= 1;
        return *this;
    }

    // static element_type get_null(){}
};

class element_delta_type
{
public:
    int head;
    int tail;
    int32_t height;
    int32_t work;

    element_delta_type()
    {
    }

    element_delta_type(element_type &el)
    {
        head = el.hash();
        tail = el.prev_hash();
        height = el.height;
        work = el.work;
    }

    element_delta_type operator-(const element_delta_type &el) const
    {
        element_delta_type res = *this;
        res.tail = el.head;
        res.height -= el.height;
        res.work -= el.work;
        return res;
    }

    void operator-=(const element_delta_type &el)
    {
        tail = el.head;
        height -= el.height;
        work -= el.work;
    }
};