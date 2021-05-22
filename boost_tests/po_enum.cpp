#include <iostream>
using namespace std;

#include <boost/program_options.hpp>
namespace po = boost::program_options;

enum ValueTypes
{
    first,
    second
};

    std::istream &operator>>(std::istream &in, ValueTypes &value)
    {
        std::string token;
        in >> token;
        //cout << token << endl;
        if (token == "0")
            value = first;
        else if (token == "1")
            value = second;
        return in;
    }

class A
{
public:
    A(ValueTypes _v)
    {
        value = _v;
    }

    ValueTypes value;
};

int main(int ac, char *av[])
{
    cout << "STARTED" << endl;
    A a(ValueTypes::second);
    po::options_description desc("test");
    desc.add_options()("debug", po::value<ValueTypes>(&a.value)->default_value(ValueTypes::first) /*->default_value(false)*/, "enable debugging mode");

    po::variables_map vm;
    po::store(po::parse_command_line(ac, av, desc), vm);
    po::notify(vm);

    cout << a.value << endl;
}