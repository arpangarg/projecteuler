#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int sum;
    vector<int> abund;
    for (int i = 2; i < 28124; i++)
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
        if (sum > i)
        {
            abund.push_back(i);
        }
    }
    int qArr[28124] = {0};
    for (int q = 2; q < 28123; q++)
    {
        if (qArr[q] == 1)
            continue;
        for (int r = 0; r < abund.size(); r++)
        {
            for(int s = r; s < abund.size(); s++)
            {
                if ((abund[r] + abund[s] < 28123) && (qArr[abund[r] + abund[s]] == 0))
                {
                    qArr[abund[r] + abund[s]] = 1;
                }
                if(abund[r] + abund[s] == q && qArr[q] == 0)
                {
                    qArr[q] = 1;
                    break;
                }
                else if(abund[r] + abund[s] > q && qArr[q] == 0)
                    break;
            }
            if (qArr[q] == 1)
                break;
        }
    }

    int s = 0;
    for (int t = 1; t < 28123; t++)
    {
        if(qArr[t] == 0)
            s += t;
    }
    cout << s;
    return 0;
}
