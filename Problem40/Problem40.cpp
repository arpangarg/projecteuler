#include <string>
#include <sstream>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string decFrac = "0";
    int i = 1;
    while (decFrac.size() <= 1000000)
    {
        decFrac += patch::to_string(i);
        i++;
    }

    int mult = 1;
    int temp;
    for (int m = 0; m < 7; m++)
        mult *= (decFrac[(int)ceil(pow(10, m))] - '0');

    cout << mult;
    return 0;
}
