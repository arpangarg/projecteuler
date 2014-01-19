#include <iostream>
#include <cmath>

using namespace std;

int gcd(int m, int n)
{
   if ((m % n) == 0)
      return n;
   else
      return gcd(n, m % n);
}

int main()
{
    double lower = 1.0/3.0;
    double higher = 1.0/2.0;
    int counter = 0;
    for (int d = 5; d <= 12000; d++)
    {
        for (int n = (int)(d*lower) + 1; n < (int)ceil(d*higher); n++)
        {
            if (gcd(n, d) == 1)
                counter++;
        }
    }
    cout << counter;
    return 0;
}
