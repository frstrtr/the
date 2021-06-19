#include <iostream>
#include <deque>
using namespace std;



int main(){

    deque<int> dq = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << *(dq.end() - (5+1)) << endl;
    cout << *(dq.end() - dq.size()) << endl;
    

}