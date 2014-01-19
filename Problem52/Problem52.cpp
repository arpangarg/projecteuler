#include <iostream>
#include <cmath>
#include <vector>
#include <map>

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

vector<int> addToVect(vector<int> v, int n)
{
    int numDig = numDigits(n);
    int temp = n;
    for (int t = numDig - 1; t >= 0; t--)
    {
        temp /= (int)ceil(pow(10, t));
        temp = temp % 10;
        v.push_back(temp);
        temp = n;
    }
    return v;
}

void printV(vector<int> v)
{
    for (int k = 0; k < v.size(); k++)
        cout << v[k];
    cout <<endl;
}

int vecToNum(vector<int> v)
{
    int sum = 0;
    for(int i = 0; i < v.size(); i++)
    {
        sum = 10*sum + v[i];
    }
    return sum;
}

vector<int> multiply(vector<int> toMul, int c)
{
    int temp;
    int carry = 0;
    for(int k = toMul.size() - 1; k >= 0; k--)
    {
        temp = c*toMul[k] + carry;
        if (temp > 9)
        {
            carry = temp/10;
            temp = temp % 10;
        }
        else
        {
            carry = 0;
        }
        toMul[k] = temp;
    }
    return toMul;
}

bool isPerm(vector<int> v1, vector<int> v2)
{
    map<int, int> m1, m2;
    for(int a = 0; a < v1.size(); a++)
        m1[v1[a]]++;
    for(int b = 0; b < v2.size(); b++)
        m2[v2[b]]++;
    if (m1 == m2)
        return true;
    return false;
}

bool satisfiesReq(vector<int> v)
{
    for(int m = 2; m < 7; m++)
    {
        vector<int> temp = v;
        temp = multiply(temp, m);
        if(!isPerm(v, temp))
            return false;
    }
    return true;
}

int main()
{
    vector<vector<int> > toCheck;
    for (int i = 10; i < 1000000; i++)
    {
        int numDig = numDigits(i);
        int temp = i/(int)ceil(pow(10, numDig - 2));
        if (temp > 16)
            i = (int)ceil(pow(10, numDig));
        vector<int> t;
        t = addToVect(t, i);
        toCheck.push_back(t);
    }

    for (int k = 0; k < toCheck.size(); k++)
    {
        if(satisfiesReq(toCheck[k]))
        {
            printV(toCheck[k]);
            break;
        }
    }

    return 0;
}
