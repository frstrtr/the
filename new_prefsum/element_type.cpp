#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <deque>
#include "share.h"
using namespace std;

int element_type::hash()
{
    return element->hash;
}

int element_type::prev_hash()
{
    return element->prev_hash;
}
