#include <iostream>
#include <cmath>

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
    int numPrimes = 0, sideLen = 1, numTotal = 1;
    int i = 3, m = 2;
    int counter = 0;
    bool done = false;

    while(1)
    {
        if(isPrime(i))
            numPrimes++;
        numTotal++;
        counter++;
        if (counter == 4)
        {
            m += 2;
            sideLen += 2;
            if (numTotal/numPrimes >= 10)
                break;
            counter = 0;
        }
        i += m;
    }
    cout << sideLen;
    return 0;
}
