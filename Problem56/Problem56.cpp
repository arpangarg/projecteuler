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
                if(numDigits(carry) == 2)
                {
                    int t = carry/10;
                    carry = carry % 10;
                    toMul.insert(toMul.begin(), carry);
                    toMul.insert(toMul.begin(), t);
                }
                else
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

int getDigitalSum(vector<int> v)
{
    int sum = 0;
    for(int i = 0; i < v.size(); i++)
        sum += v[i];
    return sum;
}

int main()
{
    int maxSum = 0;
    for(int i = 2; i < 100; i++)
    {
        vector<int> v;
        v = addToVect(v, i);
        for(int j = 2; j < 100; j++)
        {
            v = multiply(v, i);
            int digitalSum = getDigitalSum(v);
            if(digitalSum > maxSum)
                maxSum = digitalSum;
        }
    }
    cout << maxSum;
    return 0;
}
