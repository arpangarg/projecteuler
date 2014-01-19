#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void printV(vector<int> v)
{
    for (int k = 0; k < v.size(); k++)
        cout << v[k] << " ";
    cout <<endl;
}

int main()
{
    vector<vector<int> > pentSum;
    int count = 0;
    int n = 1;
    for (n = 1; n <= 5000; n++)
    {
        int i = 1;
        double aD = (n*(3.0*n-1) - 3.0*i*i + 3.0*i)/(2.0*i);
        int aI = (int)aD;
        double termD = (aD-4)/3.0 + 1;
        int termI = (int)termD;
        while (termI > n)
        {
            if (termI == termD && aI == aD && (aI - 1)%3 == 0)
            {
                vector<int> temp;
                temp.push_back(n*(3*n-1)/2);
                temp.push_back(termI*(3*termI-1)/2);
                temp.push_back(temp[0] + temp[1]);
                pentSum.push_back(temp);
                count++;
            }
            i++;
            aD = (n*(3.0*n-1) - 3.0*i*i + 3.0*i)/(2.0*i);
            aI = (int)aD;
            termD = (aD-4)/3.0 + 1;
            termI = (int)termD;
        }
    }
    int minDif = 10000000;

    for(int m = 0; m < pentSum.size(); m++)
    {
        int dif = pentSum[m][1] - pentSum[m][0];
        double nD = (1.0 + sqrt(1.0 + 24.0*dif))/6.0;
        int nI = (int)nD;
        if (nI == nD && dif < minDif)
            minDif = dif;
    }
    cout << minDif;
    return 0;
}
