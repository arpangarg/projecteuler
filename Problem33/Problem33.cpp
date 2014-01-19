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
    int n1, n2, d1, d2;
    double temp, real;
    int num = 1, den = 1;
    for (int n = 10; n < 99; n++)
    {
        for (int d = n + 1; d < 100; d++)
        {
            n1 = n/10;
            n2 = n%10;
            d1 = d/10;
            d2 = d%10;

            real = (double)n/d;

            if (n1 == d1 && n1 != 0)
                temp = (double)n2/d2;
            else if(n1 == d2 && n1 != 0)
                temp = (double)n2/d1;
            else if(n2 == d1 && n2 != 0)
                temp = (double)n1/d2;
            else if(n2 == d2 && n2 != 0)
                temp = (double)n1/d1;
            else
                temp = 0;

            if(real == temp)
            {
                num *= n;
                den *= d;
            }
        }
    }

    int gcdiv = gcd(num, den);
    cout << den/gcdiv;

    return 0;
}
