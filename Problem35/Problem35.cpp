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

int numDigits(int i)
{
    int numDig = 0;
    if (i == 0)
        return 0;
    while (i > 0)
    {
        i /= 10;
        numDig++;
    }
    return numDig;
}

int circPrime(long long n)
{
    int numDig = numDigits(n);
    int t;
    for (int i = 0; i < numDig; i++)
    {
        if(!isPrime(n))
            return 0;
        t = n%10;
        n /= 10;
        n += t*ceil(pow(10, numDig - 1));
    }
    return 1;
}

int main()
{
    int circPrimes = 0;
    for (int i = 2; i < 1000000; i++)
    {
        if (circPrime(i))
        {
            circPrimes++;
            cout << i << endl;
        }
    }

    cout << circPrimes << endl;

    return 0;
}
