#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int numDigits(int i)
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

void printV(vector<int> v)
{
    for (int k = 0; k < v.size(); k++)
        cout << v[k];
    cout << endl;
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
            if(k == 0)
            {
                toMul[0] = temp;
                toMul.insert(toMul.begin(), carry);
                return toMul;
            }
        }
        else
        {
            carry = 0;
        }
        toMul[k] = temp;
    }
    return toMul;
}

vector<int> add(vector<int> bigger, vector<int> smaller)
{
    int temp;
    int carry = 0;
    int sizeDif = bigger.size() - smaller.size();
    for (int s = 0; s < sizeDif; s++)
        smaller.insert(smaller.begin(), 0);

    for(int k = smaller.size() - 1; k >= 0; k--)
    {
        temp = bigger[k] + smaller[k] + carry;
        if (temp > 9)
        {
            carry = temp/10;
            temp = temp % 10;
            if (k == 0)
            {
                bigger[0] = temp;
                bigger.insert(bigger.begin(), carry);
                return bigger;
            }
        }
        else
        {
            carry = 0;
        }
        bigger[k] = temp;
    }
    return bigger;
}

int main()
{
    vector<vector<int> > denom;
    vector<int> t;
    t.push_back(2);
    denom.push_back(t);
    t[0] = 5;
    denom.push_back(t);

    for (int i = 2; i < 1000; i++)
    {
        vector<int> temp = denom[i-1];
        temp = multiply(temp, 2);
        temp = add(temp, denom[i-2]);
        denom.push_back(temp);
    }

    vector<vector<int> > numer;
    vector<int> tp;
    tp.push_back(3);
    numer.push_back(tp);

    for(int j = 1; j < 1000; j++)
    {
        vector<int> temp = add(denom[j], denom[j-1]);
        numer.push_back(temp);
    }

    int count = 0;
    for (int k = 0; k < denom.size(); k++)
    {
        if(numer[k].size() > denom[k].size())
            count++;
    }
    cout << count;
    return 0;
}
