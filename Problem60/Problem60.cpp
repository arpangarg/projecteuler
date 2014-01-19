#include <iostream>
#include <cmath>
#include <string>
#include <vector>

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

string to_str(int n)
{
    string toRet = "";
    while (n >= 1)
    {
        toRet = (char)(n % 10 + '0') + toRet;
        n /= 10;
    }
    return toRet;
}

int to_int(string str)
{
    int toRet = 0;
    for (int i = 0; i < str.size(); i++)
        toRet = toRet*10 + (str[i] - '0');
    return toRet;
}

int rem(int x, int y)
{
    if (!isPrime(to_int(to_str(primes[x]) + to_str(primes[y])))
        || !isPrime(to_int(to_str(primes[y]) + to_str(primes[x]))))
        return 1;
    return 0;
}

int main()
{
    for (int k = 2; k < 10000; k++)
    {
        if (isPrime(k))
            primes.push_back(k);
    }

    int s = primes.size();
    for (int a = 0; a + 4 < s; a++)
    {
        for (int b = a + 1; b + 3 < s; b++)
        {
            if (rem(a, b))
                continue;
            for (int c = b + 1; c + 2 < s; c++)
            {
                if (rem(a, c))
                    continue;
                if (rem(b, c))
                    continue;
                for (int d = c + 1; d + 1 < s; d++)
                {
                    if (rem(a, d))
                        continue;
                    if (rem(b, d))
                        continue;
                    if (rem(c, d))
                        continue;
                    for (int e = d + 1; e < s; e++)
                    {
                        if (rem(a, e))
                            continue;
                        if (rem(b, e))
                            continue;
                        if (rem(c, e))
                            continue;
                        if (rem(d, e))
                            continue;
                        cout << primes[a] + primes[b] + primes[c] + primes[d] + primes[e];
                        return 0;
                    }
                }
            }
        }
    }
}
