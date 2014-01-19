#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// generate pythagorean triplets with Euclid's formula
// http://en.wikipedia.org/wiki/Pythagorean_triple

int gcd(int m, int n)
{
   if ((m % n) == 0)
      return n;
   else
      return gcd(n, m % n);
}

int main()
{
    vector<int> lengthArr(1500001, 0);
    for (int m = 1; m < (int)ceil(sqrt(1500000/2)); m++)
    {
        for (int n = 1; n < m; n++)
        {
            if ((m - n) % 2 == 0 || gcd(n, m) != 1)
                continue;
            else
            {
                int a = m*m - n*n;
                int b = 2*m*n;
                int c = m*m + n*n;
                int L = a + b + c;
                int step = L;
                int k = 1;
                while (step*k < 1500001)
                {
                    L = k*step;
                    lengthArr[L]++;
                    k++;
                }
            }
        }
    }
    int total = 0;
    for (int x = 0; x < 1500001; x++)
    {
        if (lengthArr[x] == 1)
            total++;
    }
    cout << total;
    return 0;
}
