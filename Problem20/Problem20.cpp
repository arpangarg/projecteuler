#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> multiply(vector<int> toMul, int c)
{
    int temp;
    int carry = 0;
    int vecSize = toMul.size();
    for(int k = 0; k < vecSize; k++)
    {
        temp = c*toMul[k] + carry;
        if (temp > 9)
        {
            carry = temp/10;
            temp = temp % 10;
            if (k == vecSize - 1)
            {
                toMul.push_back(carry);
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

vector<int> add(vector<int> vec1, vector<int> vec2) //same size vectors
{
    int temp;
    int carry = 0;
    int vecSize = vec1.size();
    for(int k = 0; k < vecSize; k++)
    {
        temp = vec1[k] + vec2[k] + carry;
        if (temp > 9)
        {
            carry = temp/10;
            temp = temp % 10;
            if (k == vecSize - 1)
            {
                vec1.push_back(carry);
            }
        }
        else
        {
            carry = 0;
        }
        vec1[k] = temp;
    }
    return vec1;
}

void printV(vector<int> fact)
{
    for(int m = fact.size() - 1; m >= 0; m--)
        cout << fact[m];
    cout << endl;
}

int main()
{
    vector<int> fact;
    fact.push_back(0);
    fact.push_back(0);
    fact.push_back(1);
    int c1, c2;
    vector<int> temp1;
    vector<int> temp2;
    for (int i = 99; i > 1; i--)
    {
        c1 = i/10;
        c2 = i%10;
        temp1 = multiply(fact, c1);
        temp1.insert(temp1.begin(), 0);
        temp2 = multiply(fact, c2);
        int leadZeros = temp1.size() - temp2.size();
        for(int m = 0; m < leadZeros; m++)
        {
            temp2.push_back(0);
        }
        fact = add(temp1, temp2);
    }
    int sum = 0;
    for(int m = fact.size() - 1; m >= 0; m--)
        sum += fact[m];
    cout << sum;
    return 0;
}
