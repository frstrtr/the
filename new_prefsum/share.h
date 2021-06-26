#pragma once

struct share
{
    int hash;
    int prev_hash;

    int work;

    share(int _hash, int _prev, int _w){
        hash = _hash;
        prev_hash = _prev;
        work = _w;
    }
};