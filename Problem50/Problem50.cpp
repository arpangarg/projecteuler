#include <iostream>
#include <cmath>
#include <vector>

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
    vector<int> primes;
    for (int i = 2; i < 1000000; i++)
    {
        if(isPrime(i))
        {
            primes.push_back(i);
        }
    }

    int k, maxSeq = 0, thePrime = 0, start = 0;
    bool done = false;
    for (k = primes.size() - 1; k > 1; k--)
    {
        done = false;
        while(!done)
        {
            int m;
            m = start;
            int sum = 0, seq = 0;
            while (sum < primes[k])
            {
                sum += primes[m];
                m++; seq++;
                if (sum == primes[k])
                {
                    if (seq > maxSeq)
                    {
                        maxSeq = seq;
                        thePrime = primes[k];
                    }
                    start = 0;
                    done = true;
                    break;
                }
                else if (sum > primes[k])
                {
                    start++;
                    if (start >= k)
                    {
                        start = m = 0;
                        done = true;
                    }
                    break;
                }
            }
        }
    }
    cout << thePrime;
    return 0;
}
