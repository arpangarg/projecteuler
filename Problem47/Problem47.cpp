#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

vector<int> primes;

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

void getPrimeFac(map<int, int> &primeFac, int k)
{
    if(isPrime(k))
        return;

    int vecS = primes.size();
    int m = 0;
    while(m < vecS)
    {
        if(k % primes[m] == 0)
        {
            primeFac[primes[m]]++;
            k /= primes[m];
            m = 0;
            if (k == 1)
                return;
        }
        else
            m++;
    }
}

int main()
{
    for (int i = 2; i <= 1000; i++)
    {
        if(isPrime(i))
            primes.push_back(i);
    }

    int count = 0;
    map<int, int> primeFac;
    for (int k = 647; k < 1000000; k++)
    {
        getPrimeFac(primeFac, k);
        if(primeFac.size() == 4)
            count++;
        else
            count = 0;
        primeFac.clear();
        if(count == 4)
        {
            cout << k - 3;
            break;
        }
    }
    return 0;
}
