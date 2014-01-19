#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    bool found = false;
    int c = 143;
    int Sc;
    while (!found)
    {
        c++;
        Sc = c*(2*c-1);
        double bD = (1.0 + sqrt(1.0 + 24.0*Sc))/6.0;
        int bI = (int)bD;
        double aD = (-1.0 + sqrt(1.0 + 8.0*Sc))/2.0;
        int aI = (int)aD;
        if (bI == bD && aI == aD)
            found = true;
    }
    cout << Sc;

    return 0;
}
