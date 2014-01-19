#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int numSol;
    int maxSol = 0;
    int maxP;
    for (int p = 1; p <= 1000; p++)
    {
        numSol = 0;
        for (int a = 1; a < 1000; a++)
        {
            for (int b = 1; b < 1000; b++)
            {
                int ci = (int)ceil(sqrt(a*a + b*b));
                double cd = sqrt(a*a + b*b);
                if ((ci == cd) && (a + b + ci == p))
                    numSol++;
                else if(a + b + ci > p)
                    break;
            }
        }
        if (numSol > maxSol)
        {
            maxSol = numSol;
            maxP = p;
        }
    }
    cout << maxP;
    return 0;
}
