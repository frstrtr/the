#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/filesystem/operations.hpp>
using namespace std;


int main(){

    cout << boost::filesystem::initial_path() << endl;
}