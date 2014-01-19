#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double f = 3.0/7.0;
    double minDif = 10.0;
    int num = 0;
    for (int d = 1000000; d >= 999900; d--)
    {
        int n = floor(d*f);
        double dif = f - (double)(n)/d;
        if (dif <= 0)
            continue;
        if (dif < minDif)
        {
            minDif = dif;
            num = n;
        }
    }
    cout << num;
    return 0;
}
