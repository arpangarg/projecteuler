#include <iostream>
#include <cmath>

using namespace std;

int isPrime(int n)
{
     if (n == 1)
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
    int numPrime = 0;
    int i = 2;
    while (numPrime < 10000)
    {
          if (isPrime(i))
             numPrime++;
          i++;
    }
    cout << i - 1;
    cin.get();
    return 0;
}
