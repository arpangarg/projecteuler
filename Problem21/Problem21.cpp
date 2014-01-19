#include <iostream>
#include <cmath>

using namespace std;

int d[10000];

int main()
{
    d[0] = d[1] = 0;
    int sum;

    for (int i = 2; i < 10000; i++)
    {
        sum = 0;
        for (int k = 1; k <= (int)sqrt(i); k++)
        {
            if (i % k == 0)
            {
                sum += k;
                if ((double)k != sqrt(i) && k != 1)
                    sum += i/k;
            }
        }
        d[i] = sum;
    }

    int totalSum = 0;
    sum = 0;
    int m;
    for (int j = 2; j < 10000; j++)
    {
       m = d[j];
       if (m == j) continue;
       if (m < 10000)
       {
           if (d[m] == j)
           {
                totalSum += j;
                //cout << j << endl;
           }
       }
       else
       {
        for (int k = 1; k <= (int)sqrt(m); k++)
        {
            if (m % k == 0)
            {
                sum += k;
                if ((double)k != sqrt(m) && k != 1)
                    sum += m/k;
            }
        }
        if (sum == j)
            totalSum += j;
        sum = 0;
       }
    }
    cout << totalSum;
    return 0;
}
