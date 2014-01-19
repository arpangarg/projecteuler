#include <iostream>
#include <cmath>
#include <vector>

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
    for (int k = 0; k < v.size(); k++)
        panArr[v[k]] = 1;

    for (int m = 1; m < v.size(); m++)
    {
        if (panArr[m] == 0)
            return 0;
    }
    return 1;
}

void printV(vector<int> v)
{
    for (int k = 0; k < v.size(); k++)
    {
        cout << v[k];
    }
    cout << endl;
}

int main()
{
    bool found = false;
    int n = 7654322;
    vector<int> panV;
    while (!found)
    {
        panV.clear();
        n--;
        panV = addToVect(panV, n);
        if (checkPanVec(panV))
        {
            if (isPrime(n))
                found = true;
        }
    }
    printV(panV);
    return 0;
}
