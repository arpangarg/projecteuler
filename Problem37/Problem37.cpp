#include <iostream>
#include <cmath>

using namespace std;

int isPrime(long long n)
{
     if (n < 2)
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

int numDigits(long long i)
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

int trPrime(long long n)
{
    int numDig = numDigits(n);
    long long temp = n;

    for(int k = 0; k < numDig; k++)
    {
        if(!isPrime(temp))
            return 0;
        temp /= 10;
    }
    temp = n;
    for (int m = 0; m < numDig; m++)
    {
        if(!isPrime(temp))
            return 0;
        temp = temp % (int)ceil(pow(10, numDig - m - 1));
    }
    return 1;
}

int main()
{
    int trunPr = 0;
    long long n = 11;
    long long sum = 0;
    while (trunPr < 11)
    {
        if(trPrime(n))
        {
            trunPr++;
            sum += n;
        }
        n++;
    }
    cout << sum;

    return 0;
}
