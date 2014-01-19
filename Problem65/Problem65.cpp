#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

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
    vector<int> num;
    vector<int> den;

    num.push_back(2);
    den.push_back(1);

    for (int i = 2; i <= 100; i++)
    {
        vector<int> temp = den;
        int t;
        if (i % 3 == 0)
            t = 2*i/3;
        else
            t = 1;
        den = num;
        vector<int> temp2 = den;
        temp2 = multiply(den, t);
        num = add(temp2, temp);
    }

    int sum = 0;
    for(int m = 0; m < num.size(); m++)
        sum += num[m];

    cout << sum;

    return 0;
}
