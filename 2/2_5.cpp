#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

#define F(X)              \
    for (auto i : X)      \
    {                     \
        cout << i << " "; \
    }                     \
    cout << endl;
    
int main()
{
    deque<int> dq = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto it = dq.begin() + 6;
    F(dq)
    cout << distance(dq.begin(), it) << " " << dq[distance(dq.begin(), it)]<< endl;
    dq.erase(it);
    F(dq)
}