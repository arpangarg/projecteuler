#include <iostream>
#include <cmath>

using namespace std;

int isPrime(long long n)
{
     if (n == 1 || n == 2)
        return 1;
     int sq = (int)ceil(sqrt(n));
     for (int i = 2; i <= sq; i++)
     {
         if(n % i == 0)
              return 0;
     }
     return 1;
}

int maxConsPrimes(int a, int b)
{
    bool done = false;
    int n = 0;
    int prime;
    while (!done)
    {
        prime = n*n + a*n + b;
        if(prime < 2)
            return 0;
        else
        {
            if(isPrime(prime))
                n++;
            else
                done = true;
        }
    }
    return n;
}

int main()
{
    int maxCP = 0;
    int temp, maxA, maxB;
    for (int a = -999; a < 1000; a++)
    {
        for (int b = 0; b < 1000; b++)
        {
            temp = maxConsPrimes(a, b);
            if (temp > maxCP)
            {
                maxCP = temp;
                maxA = a;
                maxB = b;
            }
        }
    }

    cout << maxA*maxB;
    return 0;
}
