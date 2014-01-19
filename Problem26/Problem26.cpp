#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    bool done = false;

    vector<int> dividend;
    vector<int> quotient;
    int temp;
    int numRec = 0;
    int i = 10;
    int maxRec = 0, maxN = 2;

    for (int n = 2; n < 1000; n++)
    {
        done = false;
        i = 10;
        dividend.clear();
        quotient.clear();
        while (!done)
        {
            numRec = 0;
            dividend.push_back(i);
            if(i/n == 0)
            {
                quotient.push_back(0);
                i *= 10;
            }
            else
            {
                temp = i/n;
                quotient.push_back(temp);
                i = (i - temp*n)*10;
            }
            for (int m = dividend.size() - 1; m >= 0 ; m--)
            {
                numRec++;
                if(dividend[m] == i)
                {
                    done = true;
                    if (numRec > maxRec)
                    {
                        maxRec = numRec;
                        maxN = n;
                    }
                    break;
                }
            }
        }
    }

    cout << maxN << " " << maxRec;

    return 0;
}
