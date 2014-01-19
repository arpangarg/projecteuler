#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

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

vector<int> addToVect(vector<int> v, int prod)
{
    int temp = prod;
    int numDig = numDigits(prod);
    for(int k = 0; k < numDig; k++)
    {
        temp /= (int)ceil(pow(10, numDig - k - 1));
        v.push_back(temp % 10);
        temp = prod;
    }
    return v;
}

vector<int> getMaxV(vector<int> v1, vector<int> v2)
{
    for (int k = 0; k < 9; k++)
    {
        if (v1[k] > v2[k])
            return v1;
        else if (v2[k] > v1[k])
            return v2;
    }
    return v1;
}

int checkPanVec(vector<int> v)
{
    int panArr[10] = {0};
    for (int k = 0; k < 9; k++)
        panArr[v[k]] = 1;

    for (int m = 1; m < 10; m++)
    {
        if (panArr[m] == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int n = 1;
    vector<int> panVec;
    vector<int> maxPan;
    for (int j = 0; j < 9; j++)
        maxPan.push_back(0);
    int prod;
    for (int i = 1; i < 10000; i++)
    {
        while (panVec.size() < 9)
        {
            prod = n*i;
            panVec = addToVect(panVec, prod);
            n++;
        }
        if (panVec.size() == 9)
        {
            if(checkPanVec(panVec))
            {
                maxPan = getMaxV(maxPan, panVec);
            }
            panVec.clear();
            n = 1;
        }
        else
        {
            panVec.clear();
            n = 1;
        }
    }

    for (int s = 0; s < 9; s++)
        cout << maxPan[s];

    return 0;
}
