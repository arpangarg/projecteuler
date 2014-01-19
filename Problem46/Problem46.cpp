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
    int squares[10000] = {0};
    for (int m = 1; m < 10000; m++)
        squares[m] = m*m;
    for (int i = 5; i < 10000; i += 2)
    {
        if(isPrime(i))
            continue;
        int t = 1;
        int n = i - 2*squares[t];
        while(n > 0)
        {
            if(isPrime(n))
                break;
            t++;
            n = i - 2*squares[t];
        }
        if (n <= 0)
        {
            cout << i;
            break;
        }
    }

    return 0;
}
