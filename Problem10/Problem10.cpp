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

int main()
{
    long long sum = 0;
    for (int i = 2; i < 2000000; i++)
    {
        if(isPrime(i))
           sum += i;
    }
    cout << sum;
    cin.get();
    return 0;
}
