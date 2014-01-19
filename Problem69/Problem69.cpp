#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int isPrime(long long n)
{
     if (n == 1)
        return 0;
     if (n == 2)
        return 1;
     int sq = (int)ceil(sqrt(n));
     for (int i = 2; i <= sq; i++)
     {
         if(n % i == 0)
              return 0;
     }
     return 1;
}

int main()
{
    vector<int> primes;

    for (int i = 2; i < 1000000; i++)
    {
        if (isPrime(i))
            primes.push_back(i);
    }

    int maxPrF = 0;
    int maxI = 0;

    for (int i = 2; i <= 1000000; i++)
    {
        int numPrF = 0;
        int j = 0;
        while (primes[j] < (int)ceil(sqrt(i)))
        {
            if (i % primes[j] == 0)
                numPrF++;
            j++;
        }
        if (numPrF > maxPrF)
        {
            maxPrF = numPrF;
            maxI = i;
        }
    }
    cout << maxI;
    return 0;
}
