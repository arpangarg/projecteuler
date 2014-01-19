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

void printV(vector<int> v)
{
    for (int k = v.size() - 1; k >= 0; k--)
        cout << v[k];
    cout << endl;
}

vector<int> multiply(vector<int> toMul, int c)
{
    int temp;
    int carry = 0;
    for(int k = 0; k < 10; k++)
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

vector<int> add(vector<int> vec1, vector<int> vec2) //same size vectors
{
    int temp;
    int carry = 0;
    for(int k = 0; k < 10; k++)
    {
        temp = vec1[k] + vec2[k] + carry;
        if (temp > 9)
        {
            carry = temp/10;
            temp = temp % 10;
        }
        else
        {
            carry = 0;
        }
        vec1[k] = temp;
    }
    return vec1;
}

int main()
{
    vector<vector<int> > seriesNums;
    for (int i = 1; i < 1000; i++)
    {
        vector<int> temp(10, 0);
        temp[0] = 1;
        for (int j = 0; j < i; j++)
            temp = multiply(temp, i);
        seriesNums.push_back(temp);
        temp.clear();
    }
    vector<int> total(10, 0);
    for(int m = 0; m < 999; m++)
        total = add(total, seriesNums[m]);

    printV(total);
    return 0;
}
