#include <iostream>
#include <exception>
#include <map>
using namespace std;

int main()
{

    // try
    // {
    //     throw std::invalid_argument("1");
    // }
    // catch(const std::overflow_error& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // catch(const std::invalid_argument& e){
    //     std::cout << "inv: " << e.what() << "\n";
    // }
    
    map<int, int> d {{1,5}, {2, 10}};

    try{
        cout << d.at(1) << endl;
        cout << d.at(3) << endl;
    } catch(const std::out_of_range& e){
        cout << e.what() << endl;
    }




}